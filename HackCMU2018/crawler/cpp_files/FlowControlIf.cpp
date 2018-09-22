// FlowControl.cpp 

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int x, y;
	cout << "Enter two numbers " << endl;
	cin >> x >> y;

	cout << x << " ";
	if (x > y)
	{
		cout << "is larger than ";
	}
	else
	{
		cout << "is not larger than ";
	}
	cout << y << endl;

	if (x + y > 10)
		cout << "thanks for choosing large numbers!" << endl;

	////////////////// While Loop ////////////////////////
	int x1;
	cout << "Enter a number " << endl;
	cin >> x1;

	bool prime = true;
	int i = 2;

	while (i <= x1/i)
	{
		int factor = x1 / i;
		if (factor * i == x1)
		{
			cout << "factor found: " << factor << endl;
			prime = false;
			break;
		}
		i = i + 1;
	}
	cout << x1 << " is " ;
	if (prime)
		cout << "prime " << endl;
	else
		cout << "not prime " << endl;

	////////////////// For Loop ////////////////////////
	int x2;
	cout << "Enter a number " << endl;
	cin >> x2;

	bool prime1 = true;
	int i1 = 2;

	for (int i = 2; i <= x / i; i++)
	{
		int factor1 = x2 / i1;
		if (factor1 * i1 == x2)
		{
			cout << "factor found: " << factor1 << endl;
			prime1 = false;
			break;
		}
	}
	cout << x2 << " is ";
	if (prime1)
		cout << "prime " << endl;
	else
		cout << "not prime " << endl;

	/////////////////////// Immediate If ////////////////////////
	int a = 99;
	while (a > 0)
	{
		cout << "Enter a number, 0 to quit " << endl;
		cin >> a;
		string sign = a > 0 ? "positive " : "0 or negative";
		cout << "your number is " << sign << endl;
	}


	//////////////////// Switch Statement //////////////////////////
	int z;
	cout << "Enter a number, 0 to quit " << endl;
	cin >> z;
	while (z > 0)
	{
		switch (z)
		{
		case 1: cout << "you entered 1" << endl;
			break;
		case 2:
		case 3:cout << "you entered 2 or 3" << endl;
			break;
		case 4: cout << "you entered 4" << endl;
		case 5: cout << "you entered 5" << endl;
			break;
		default:
			cout << "You enterted other than 1 - 5 " << endl;
		}
		cout << "Enter a number, 0 to quit " << endl;
		cin >> z;
	}

    return 0;
}

