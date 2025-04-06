#include <iostream>
using namespace std;

int main()
{
	/*
	int a = 2;
	int &b = a;
	const int *p = nullptr;
	
	cout << *p << endl;
	
	a++;
	// b++;
	// (*p)++;
	
	int c = 4;
	p = &c;
	
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "*p: " << *p << endl;
	
	cout << "p: " << p << endl;
	cout << "&a: " << &a << endl;
	cout << "&b: " << &b << endl;
	cout << "&p: " << &p << endl;
	*/
	
	// ARRAY 
	int i = 3;
	const unsigned int j = 3;
	int arr[j] = {1,2,3};
	for(unsigned int i = 0; i < 3; i++)
		cout << "arr[" << i << "]: " << arr[i] << endl;
	
	int *ptr1 = new int[i];
	
	int *ptr2 = &arr[0];
	cout << "*ptr2: " << *ptr2 << endl;
	cout << "arr[0]: " << arr[0] << endl;
	cout << "*arr: " << *arr << endl;
	cout << "*(ptr2 + 1): " << *(ptr2 + 1) << endl;

	delete [] ptr1;
	
	
	
    return 0;
}

