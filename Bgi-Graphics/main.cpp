/*
* BGI Graphics example
* @author MuchiriJohn 
* License: MIT
*/

#include <graphics.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <functional>
#include <unordered_map>
#include <bits/stdc++.h>

#include "computation.h"
#include "splitter.h"

using namespace std;

/*
* draw boxes
*/
void drawBoxes(int ln, int hg, string start, vector<string> fld, string ans){
	int width_blocks = ln;
	string text;
	int left, top, right, bottom;
	int tcenter;
	uint8_t x_o = 10, y_o = 30, rd=10;
	//iterate while drawing blocks.
	for(int x = 0; x < width_blocks ;  x++){
		text = "";
		//first square
		if(x <= 0 ) {
			setcolor(GREEN);
			text = start;
			tcenter = 20;
		}
		//value squares
		else if(x > 0 && x < width_blocks-1){
			setcolor(YELLOW);
			if(ln < 10) text = fld[x-1];
			tcenter = 40;
		}
		//ans square
		else {
			setcolor(ORANGE);
			if(ln < 10) text = "Ans=" + ans;
			tcenter = 10;
		}
		//define square boundaries
		left = (100*x) + x_o + (2*x);
		top = (100*hg) + y_o + (2*hg);
		right = (100 * (x+1)) + x_o + (2*x);
		bottom = (100 * (hg+1)) + y_o + (2*hg);
		//draw boxes
		roundrect(left, top, right, bottom, rd, rd);
		//draw values, forecolor = white.
		setcolor(WHITE);
		outtextxy(left+tcenter, top+40, text.c_str());
		//delay a few ms before drawing next box
		delay_ms(100);
		//if values > 7 show error message
		if(ln > 10 && x == 8){
			setcolor(RED);
			text = "ERROR: Too many numbers in this line. Wont fit to screen display, Maximum numbers per line is 7.";
			moveto(120, top+40);
			outtext(text.c_str());
			//x = ln;
		}
	}
}

/*
* get mapped operators
*/
int getMathType(std::string key) {
	const static std::unordered_map<std::string,int> mp_{
		{"AVERAGE",   AVERAGE},
		{"MAXIMUM",   MAXIMUM},
		{"MINIMUM",   MINIMUM},
		{"VARIANCE",  VARIANCE}
	};
	return mp_.count(key) ? mp_.at(key) : NO_OP;
}

/*
* main function
*/
int main(){
	
	//program variables.
	string name; //string to hold the name.
	char ch;
	string databuffer; //char buffer to hold file contents.
	
	cout << "\n===================================================================\n";
	cout << "Computing Math using Graphics\n";
	cout << "===================================================================\n\n";
	cout << "Enter the name of the textfile (e.g f.txt) : ";
	
	//get user specified file name.
	cin >> name;
	//create file i/o stream to read the file
	ifstream myfile(name.c_str(), ios::in | ios::binary); //create file input stream.
	
	if(!myfile){ //check if file exists, if not exit with error message.
		cout << "ERROR : Failed to open file!." ;
		cout << "Check filename or if the file exists.";
		system("pause");
		return 1; //exit
	}else{
		cout << "===================================================================\n";
		cout << "File stream created successfully.:\n\n";
		databuffer = ""; //force clear buffer;
	}
	
	//read the contents of the file, compact mode.
	//reads byte by byte, important so as not to lose any
	//characters.
	while(myfile.get(ch)){ //return false when myfile.eof is reached.
		databuffer += ch; //save read character to buffer.
		//cout << ch;
	}
	cout << databuffer; //output the contents.
	
	cout << "\n\n===================================================================\n\n";
	cout << "Parsing File....\n\n";
	///get the number of lines in the buffer
	getLines(&databuffer[0], 1);
	
	//start to draw BGI graphics
	initgraph(1000, 800);
	setcaption("Math Computation");
	setcolor(CYAN);
	outtextxy(10, 4, "Processing...");
	//compute
	for(int x=0; x < lines.size(); x++){
		double ans = 0.0;
		//get the fields.
		getOperatorValues(&lines[x][0]);
		switch (getMathType(op)) {
		case AVERAGE:
			ans = calculationOperator(AVERAGE, fields);
			break;
		case MAXIMUM:
			ans = calculationOperator(MAXIMUM, fields);
			break;
		case MINIMUM:
			ans = calculationOperator(MINIMUM, fields);
			break;
		case VARIANCE:
			ans = calculationOperator(VARIANCE, fields);
			break;
			default:
				break;
		}
		
		//convert ans to string using stringstream
		stringstream st (stringstream::in | stringstream::out);
		st.setf(ios::fixed, ios::floatfield);
		
		//check if decimal
		if((ans - (int)ans) > 0) st.precision(1);
		else st.precision(0);
		
		st << ans;
		
		string computed_ans = st.str();
		
		//output answer.
		cout<< "Ans = " << computed_ans; //output the ans.
		//draw grid with animation delay 500ms
		drawBoxes(fields.size() +2, x, op, fields, computed_ans);
		
	}
	//endDraw();
	
	cout << "\nDone.\n";
	cout << "\n\n===================================================================";
	
	system("pause"); //pause system.
	return 0; //end
}

