// Pointers.cpp : Intro to Pointers in C++
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	// The address of Operator 
	int x(5);
	cout << x << "\n";  // Prints the value of x
	cout << &x << "\n"; // Prints the value of address of variable x

	// The derefernce operator 
	int x1(5);
	cout << x1 << "\n"; // prints the value of variable of x;
	cout << &x1 << "\n"; // prints the address  of variable x;
	cout << *(&x1) << "\n"; // prints the value of memeory address of variable x

	// Pointers 
	// while declaring pointer variable, we recommend putting the asterisk next to the variable name
	// while returning the pointers from a function it is clear to put asterisk next to int type

	// E.g. int *a;
	// E.g. int* doSomething();

	int iValue(5);
	int *ptr = &iValue;
	cout << "Value address " << &iValue << "\n";
	cout << ptr << "\n";
	
	// Dereferencing Operators
	cout << &iValue << endl;
	cout << iValue << endl;

	int *iPtr = &iValue;
	cout << iPtr << endl;
	cout << *iPtr << endl;

	// Pointers can be reassigned.
	int iValue1(5);
	int iValue2(7);

	int *iPtr2;

	iPtr2 = &iValue1;
	cout << *iPtr2 << endl;
	iPtr2 = &iValue2;
	cout << *iPtr2 << endl;
	
	// Size of Pointers remain same because it just a memory address.
	char *cPtr;
	int *iPtr;
	cout << sizeof(cPtr);
	cout << sizeof(iPtr);



	return 0;
}

