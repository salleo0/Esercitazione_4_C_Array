#include <iostream>
using namespace std;

int foo(int& a)
{
	a++;
	return a;
}

int* fooPtr(int* &ptr)
{
	(*ptr)++;
	
	int b = 2;
	ptr = &b;	// Attention: b will be deleted after the return statement
	
	return ptr;
}

int main()
{
	int a = 2;
	int b = 3;
	int &c = b;
	int *ptr1 = &a;	// & is the address-of operator
	int * &ptr = ptr1; // ptr is a reference for ptr1
	// int &* ptr;		error: references are not objects, they do not have addresses. Hence
	//						   we may not define a pointer to a reference
	cout << ptr1 << endl;
	cout << ptr << endl;
	
	ptr = &c;
	
	cout << "ptr1: " << ptr1 << endl;
	cout << "ptr: " << ptr << endl;
	cout <<"&c: " << &c << endl;	// the reference is not an object
	cout << "&b: " << &b << endl;
	
	cout << "&ptr: " << &ptr << endl;	// a pointer is an object itself
	
	// type of object and pointer must match. The following code produces an error:
	// double a = 2.0;
	//int *ptr1 = &a;
	
	// * is the dereference operator
	cout << "*ptr: " << *ptr << endl;
	*ptr = 4;
	cout << "b: " << b << endl;
	
	// it is an error to try to derefence a pointer that does not point to an object
	int *nptr = nullptr;	// nullptr is a literal
	
	// cout << *nptr << endl; 		error: the program will crash
	
	/// pointers and const
	const double pi = 3.14;
	// double *ptr = &pi; //error
	const double *cptr = &pi;
	// *cptr = 42; error
	double s = 1.0;
	cptr = &s; 		// it works
	// *cptr = 32;	// error: cannot change s through cptr
	const double *const pip = &pi;	// const pointer to const double
	
	int &ref = a;
	cout << "a: " << a << endl;
	cout << foo(a) << endl;
	cout << "a: " << a << endl;
	cout << "ptr: " << ptr << endl;
	
	// ARRAY (static)
	int i = 2;
	const unsigned int j = i;
	const unsigned int m = 5;
	const size_t n = 2;
	int arr[m] = {1,2};		// use i or j to dimension the array is an error
	int arr2[n];			// = arr; // no copy
	// arr2 = arr;			// no assignment
	
	int *aptr = &arr[0];
	cout << "aptr[0]: " << aptr[0] << endl;
	// int *jptr = aptr++;
	int *jptr = arr+1; 		// arr++ is not allowed
	cout << "*jptr: " << *jptr << endl;
	
	// ARRAY (dynamic)
	int k = 2;
	int *ptr3 = new int[k]{1,2};
	
	delete [] ptr3;
	
    return 0;
}

