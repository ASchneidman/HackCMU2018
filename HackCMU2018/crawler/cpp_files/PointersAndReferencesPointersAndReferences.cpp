// PointersAndReferences.cpp - Learning from pluralsight

#include "stdafx.h"
#include <iostream>
#include "Person.h"
using namespace std;

int main()
{
	int a = 3;
	cout << "a is " << a << endl;
	int *pA = &a;
	*pA = 4;
	cout << "a is " << a << endl;
	int b = 100;
	pA = &b;
	(*pA)++;
	cout << "a is " << a << ", *pA " << *pA << endl;

	Person Kate("Kate", "Gregory", 1234);
	Person *pKate = &Kate;

	//cout << "Kate " << pKate->GetName() << pKate->GetNumber() << endl;
	pKate->SetNumber(235);

	cout << "Kate: " << Kate.GetName() << " " << Kate.GetNumber() << endl;
	cout << "pKate: " << pKate->GetName() << " " << pKate->GetNumber() << endl;

	int& rA = a;
	rA = 5;
	cout << "a is " << a << endl;

	Person& rKate = Kate;
	rKate.SetNumber(345);
	cout << "rKate: " << rKate.GetName() << " " << rKate.GetNumber() << endl;

	int *badPointer = nullptr; // After adding program will not crash
	// if uninitialized then it will crash
	if (badPointer) 
	{
		badPointer = nullptr; // error it takes only address
		cout << *badPointer << endl; // program crashes
	}

	int& badReference;
	badReference = 3;
	cout << badReference << endl;

	return 0;
}