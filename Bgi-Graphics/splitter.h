#include <string>
#include <vector>
#include <iostream>
using namespace std;


class splitstring : public string {
	vector<string> flds;
public:
	splitstring(char *s) : string(s) { };
	vector<string>& split(char delim, int rep=0);
};

// split: receives a char delimiter; returns a vector of strings
// By default ignores repeated delimiters, unless argument rep == 1.
vector<string>& splitstring::split(char delim, int rep) {
	if (!flds.empty()) flds.clear();  // empty vector if necessary
	string work = data();
	string buf = "";
	int i = 0;
	while (i < work.length()) {
		if (work[i] != delim)
			buf += work[i];
		else if (rep == 1) {
			flds.push_back(buf);
			buf = "";
		} else if (buf.length() > 0) {
			flds.push_back(buf);
			buf = "";
		}
		i++;
	}
	if (!buf.empty())
		flds.push_back(buf);
	return flds;
}


//get line data from the buffer
vector<string> lines;

string getLines(char *buffer, int num)
{
	splitstring s(&buffer[0]);
	//get number of operations and data
	lines = s.split('\n');
	return lines[num];
}

//get operator and values
vector<string> fields;
string op;

void getOperatorValues(char *buffer)
{
	//char *h = 
	splitstring s(&buffer[0]);
	//get number of operations and data
	vector<string> op_val = s.split(':');
	//get the operator
	op = op_val[0];
	cout << "\n" << op <<endl ;
	//get fields
	splitstring fs(&op_val[1][0]); 
	fields = fs.split(',');
	for (int k = 0; k < fields.size(); k++){
		cout<< "val "<< k + 1 << " : " << fields[k] << endl;
	}
}

