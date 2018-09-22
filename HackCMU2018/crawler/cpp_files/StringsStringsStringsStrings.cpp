// Strings.cpp 

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name;
	cout << "Who are you ?" << endl;
	cin >> name;
	cout << endl;

	string greeting = "Hello, " + name;

	if (name == "Kate")
	{
		greeting += ", I know you!";
	}

	cout << greeting << endl;

	// Member functions

	int l = greeting.length();

	cout << " \"" + greeting + "\" is "
		<< l << "characters long. " << endl;

	auto space = greeting.find(' ');
	string beginning = greeting.substr(space + 1);
	cout << beginning << endl;

	if (beginning == name)
	{
		cout << "expected result." << endl;
	}

	// Member functions Excercise

	string str1;
	string str2;

	cin >> str1 >> str2;

	int length1 = str1.length();
	int length2 = str2.length();

	if (length1 > length2)
		cout << str1 << " is longer." << endl;
	else
		cout << str2 << " is longer." << endl;

	if (length1 == length2)
		cout << "They are of same length." << endl;

    return 0;
}

