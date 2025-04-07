#include <iostream>
#include <sstream>
#include <fstream>
#include "Utils.hpp"
using namespace std;

int main()
{
	string inputFile = "data.txt";
	size_t numAssets;
	double startingCapital;
	double *returnRate = nullptr;
	double *assetFraction = nullptr;
	if(!ImportData(inputFile, numAssets, startingCapital, returnRate, assetFraction))
		return 1;

	double finalCapital = FinalValueOfPortfolio(numAssets, startingCapital, returnRate, assetFraction);
	
	cout << ArrayToString(numAssets, returnRate) << endl << ArrayToString(numAssets, assetFraction) << endl;
	
	cout << finalCapital << endl;
	
	
    return 0;
}

