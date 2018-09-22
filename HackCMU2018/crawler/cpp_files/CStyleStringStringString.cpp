// String.cpp : C Style strings
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	char cString[] = "string";
	cout << cString << " has " << sizeof(cString) << " characters. \n";
	for (int iIndex(0); iIndex < sizeof(cString); iIndex++)
	{
		cout << cString[iIndex] << " ";
		cout << static_cast<int>(cString[iIndex]) << " " << endl;
	}

	// Default value for char array if you don't initalize 
	char c[2];
	c[0] = 'H';

	cout << c[0] << endl;
	cout << c[1] << endl; // prints garbage value
	cout << c[2] << endl; // prints garbage value

	char cName[25];
	cout << "Enter your name " << endl;
	cin >> cName;
	cin.getline(cName, 25); // This way we make sure that no overflow of characters occurs only occupying 254 characters
	                         // leaving space for null character.
	cout << "Enter your name " << cName << endl;
	
	// Manipulating C Style Strings
	char cSource[] = "Copy this !";
	char cDest[50];

	// To avoid the overflow of characters 
	strncpy_s(cDest, cSource, 49);
	cout << "Destination " << cDest; // Print "Copy this"

	// strlen() function which retuns the length of the string

	char cMyName[20] = "Alex";
	cout << "My name is " << cMyName << endl;
	cout << cMyName << " has " << strlen(cName) << " letters. \n";
	cout << cMyName << " has " << sizeof(cName) << " characters in the array. \n";

	return 0;
}

