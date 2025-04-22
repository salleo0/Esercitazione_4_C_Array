#include <iostream>
#include <fstream>
#include <sstream>
#include "Utils.hpp" // g++ requires: "src/Utils.hpp"
#include "ClassObj.hpp" // error if pragma once is not used in ClassObj

using namespace std;

int main()
{
	std::string inputFile = "vectors.txt";
	size_t n;
	unsigned int *ptr1 = nullptr;
	unsigned int *ptr2 = nullptr;
	
	if(!ImportVectors(inputFile, n, ptr1, ptr2))
	{
		cerr << "Something went wrong with inport" << endl;
		return -1;
	}
	else 
		cout << "Import successful: n= " n << " v1= " << ArrayToString(n, ptr1) << " v2= " << ArrayToString(n, ptr2) << endl;
	
	unsigned int d = DotProduct(n, ptr1, ptr2);
	cout << "dot product: " << d << endl;
	
	std::string outputFile = "./dotProduct.txt";
	if (!ExportResult(outputFile, n, ptr1, ptr2, d))
	{
		cerr << "Something went wrong with export" << endl;
	}
	else 
		cout << "Export successful" << endl;
	
	delete[] ptr1;
	delete[] ptr2;
	
    return 0;
}


