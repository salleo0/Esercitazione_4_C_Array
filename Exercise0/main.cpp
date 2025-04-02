#include <iostream>
using namespace std;

int main()
{
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
	
	
    return 0;
}

