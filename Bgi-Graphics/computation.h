/*
 * Header file consisting all the operator computations
 * Average, Maximum, Minimum and Variance
 */
#include <vector>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;
//enumerator to hold operators
enum operators {
	AVERAGE,
	MINIMUM,
	MAXIMUM,
	VARIANCE,
	NO_OP
};

//find average method
//return average
float computeAverage(vector<string> pars)
{
	float sum = 0;
	for(int index = 0; index < pars.size(); index++) //loop while adding values
	{
		sum += atof(&pars[index][0]);
	}
	
	return (sum / pars.size());
}

//find maximum method
//return maximum value
float findMaximum(vector<string> pars)
{
	int index = 0;
	float lvalue = atof(&pars[index][0]);
	for(index = 1; index < pars.size(); index++)
	{
		if(atof(&pars[index][0]) > lvalue)
		{
			lvalue = atof(&pars[index][0]);
		}
	}
	
	return lvalue;
}

//find minimum method
//return minimum value
float findMinimum(vector<string> pars)
{
	int index = 0;
	float lvalue = atof(&pars[index][0]);
	for(index = 1; index < pars.size(); index++)
	{
		if(atof(&pars[index][0]) < lvalue) 
		{
			lvalue = atof(&pars[index][0]);
		}
	}
	
	return lvalue;
}

//compute variance method
//return variance
float computeVariance(vector<string> pars)
{
	float var = 0;
	float sum_difference = 0; //variable to hold summation of differences. 
	float average = computeAverage(pars); // get the average.
	for(int x =0; x<pars.size(); x++)
	{
		sum_difference += pow((( atof(&pars[x][0])) - average) , 2.0);
	}
	
	var = (sum_difference / pars.size());
	return var;
}

//get the stardard variation from the computed variance
float stardardDeviation(vector<string> pars)
{
	return sqrt(computeVariance(pars));
}


//method to select the opator computation
float calculationOperator(operators op, vector<string> pars){
	switch(op)
	{
	case AVERAGE:
		return computeAverage(pars); //return average
		break;
	case MAXIMUM:
		return findMaximum(pars); //return maximum
		break;
	case MINIMUM:
		return findMinimum(pars); //return minimum
		break;
	case VARIANCE:
		return computeVariance(pars); //return variance
		break;
		default:
			cout << "ERROR : Operator not recognized.";
			break;
	};
	return 0;
}

