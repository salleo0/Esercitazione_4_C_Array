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
		return 1;
	
	unsigned int d = DotProduct(n, ptr1, ptr2);
	
    return 0;
}


