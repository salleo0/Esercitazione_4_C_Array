#include <iostream>
#include <sstream>
#include <fstream>
#include "Utils.hpp"
using namespace std;

int main()
{
	string inputFile = "data.txt";
	size_t numAssets;
	double capital;
	double *returnRate = nullptr;
	double *assetFraction = nullptr;
	if(!ImportData(inputFile, numAssets, capital, returnRate, assetFraction))
		return 1;
	
    return 0;
}

