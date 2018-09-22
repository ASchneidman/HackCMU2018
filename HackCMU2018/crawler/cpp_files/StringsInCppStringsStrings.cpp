// Strings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	string str1; // default constructor is called
	cout << str1; // its an empty string

	string str2("Hello World");
	string str3(str2); // copy constructor is called
	cout << str3 << endl;

	string str4("my string");
	string str5(str4, 4);
	cout << str5 << endl;
	string str6(str4, 3, 5);
	cout << str6 << endl;

	const char* szSource("my string");
	string sOutput(szSource, 4);
	cout << sOutput << endl;

	string sOutput1(4, 'Q');
	cout << sOutput1 << endl;

	cout << "String length and capacity " << endl;
	string sSource("0123456789");
	cout << sSource.length() << endl;

	string sString1("Not empty");
	cout << (sString1.empty() ? "true" : "false") << endl;

	string sString2;
	cout << (sString2.empty() ? "true" : "false") << endl;

	string sString3("Hello World");
	cout << sString3.max_size() << endl;
	cout << "Length of a string " << sString3.length() << endl;
	cout << "Capacity of a string " << sString3.capacity() << endl;

	cout << "String character access " << endl;
	string sSource2("abcdef");
	cout << sSource2[5] << endl;

	sSource2[2] = 'b';
	cout << sSource2 << endl;
	cout << sSource2.at(4) << endl;

	// Assignment 
	string s("One");
	cout << s << endl;

	const string s1("Two");
	s.assign(s1);
	cout << s1 << endl;

	// Assign c style string
	s.assign("Four");
	cout << s << endl;

	string s4;
	s4 = s = "Eleven";
	cout << s4 << s << endl;

	const string sSource4("abcdefghijklmn");
	string dest;

	dest.assign(sSource4, 2, 4);
	cout << dest << endl;

	cout << "Swapping the strings " << endl;
	string str01("Blue");
	string str02("Green");
	swap(str01, str02);
	cout << str01 << " " << str02 << endl;
	str01.swap(str02);
	cout << str01 << " " << str02 << endl;



    return 0;
}

