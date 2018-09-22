// ArrayAsArgument.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void passValue(int value)
{
	value = 99;
}

void passArray(int prime[5])
{
	prime[0] = 11;
	prime[1] = 7;
	prime[2] = 5;
	prime[3] = 3;
	prime[4] = 2;
}

double getAverage(int arr[], int size)
{
	int iIndex, iSum = 0;
	double dAvg(0.0);

	for (iIndex = 0; iIndex < size; ++iIndex)
	{
		iSum = iSum + arr[iIndex];
	}
	dAvg = double(iSum) / size;

	return dAvg;
}

int main()
{
	int value(1);
	cout << "before passValue: " << value << endl;
	passValue(value);
	cout << "after passArray: " << value << endl;

	int prime[5] = { 2, 3, 5, 7, 11 };
	cout << "before passArray: " << prime[0] << " " << prime[1] << " " << prime[2] << " " << prime[3]
		<< " " << prime[4] << "\n";
	passArray(prime);
	cout << "after passArray: " << prime[0] << " " << prime[1] << " " << prime[2] << " " << prime[3]
		<< " " << prime[4] << "\n";

	int arrBalance[5]{ 1000, 2, 3, 17, 50 };
	double dAvg(0.0);
	dAvg = getAverage(arrBalance, 5);

	// output the returned value
	cout << "Average value is: " << dAvg << endl;
	return 0;
}

