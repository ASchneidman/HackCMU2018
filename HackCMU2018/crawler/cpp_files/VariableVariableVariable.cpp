// Variable.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	// defining a variable of specific type
	char chValue;
	bool bValue;
	int nValue;
	float fValue;
	double dValue;

	// void can't be used a type
	// void vValue;
	
	// Two ways to initialize a variable
	// Copy Initialization by using equal sign
	int iValue = 5;  // Copy Value

	// direct initialization 
	int iValue1(5);

	// Uniform Initialization
	int iValue2{ 5 };

	// As per C++ new form of initialization that works for everything 
	// Uniform Initialization
	int iValue3{ 5 };

	int iValue4{}; // default initialization set to 0

	// Variable assignment
	int iValue5;
	iValue5 = 5; // Copy initialization

	// Defining multiple variables
	int a = 5, b = 6;
	int c(7), d(8);
	int e{ 9 }, f{ 10 };

	int x;
	int y;

	// code
	cout << "Enter a number " << endl;
	cin >> x;
	cout << "Enter another number " << endl;
	cin >> y;

	cout << "The Sum is : " << x + y << endl;
    return 0;
}

