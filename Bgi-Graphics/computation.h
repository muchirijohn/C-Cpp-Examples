/*
 * Header file consisting all the operator computations
 * Mean, mode, median, Maximum, Minimum and Variance
 */
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
//enumerator to hold operators
enum operators {
	MINIMUM,
	MAXIMUM,
	MEAN,
	MODE,
	MEDIAN,
	VARIANCE,
	NO_OP
};


const static unordered_map<string,int> ump_{
	{"MAXIMUM",		MAXIMUM},
	{"MINIMUM",		MINIMUM},
	{"MEAN",		MEAN},
	{"MODE",		MODE},
	{"MEDIAN",		MEDIAN},
	{"VARIANCE",	VARIANCE}
};

//find average method
//return average
float computeMean(vector<string> pars)
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
	float average = computeMean(pars); // get the average.
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

//compute median
float computeMedian(vector<string> pars){
	int size_ = pars.size();
	double arr[size_];
	for(int x=0; x< size_; x++) arr[x] = atof(&pars[x][0]);
	//sort the array
	sort(arr, arr + size_);
	if(size_ % 2 == 0)
		return (arr[size_/2 - 1] + arr[size_/2])/2;
	return arr[size_/2];
}

//compute mode
float computeMode(vector<string> pars){
	// Sort the array
	 int size_ = pars.size();
	 double arr[size_];
	 //convert values to array
	 for(int x=0; x< size_; x++) arr[x] = atof(&pars[x][0]);
	 //sort
	 sort(arr, arr + size_);

	//finding max frequency
	int max_count = 1, count = 1;
	double res = arr[0];
	for (int i = 1; i < size_; i++) {
		if (arr[i] == arr[i - 1])
			count++;
		else {
			if (count > max_count) {
				max_count = count;
				res = arr[i - 1];
			}
			count = 1;
		}
	}

	// when the last element is most frequent
	if (count > max_count)
	{
		max_count = count;
		res = arr[size_ - 1];
	}

	return res;
}


//method to select the opator computation
float calculationOperator(operators op, vector<string> pars){
	switch(op)
	{
	case MAXIMUM:
		return findMaximum(pars); //return maximum
		break;
	case MINIMUM:
		return findMinimum(pars); //return minimum
		break;
	case MEAN:
		return computeMean(pars); //return average
		break;
	case MODE:
		return computeMode(pars); //return minimum
		break;
	case MEDIAN:
		return computeMedian(pars); //return minimum
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

/*
 * get mapped operators
 */
inline uint8_t getMathType(string key) {
	return ump_.count(key) ? ump_.at(key) : NO_OP;
}
