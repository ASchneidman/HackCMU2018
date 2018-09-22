#include "stdafx.h"
#include <iostream>
using namespace std;

class Operation
{
	int a, b, add, sub, mult;
	float div;
public:
	void get();
	void sum();
	void diff();
	void product();
	void division();
};

inline void Operation::get()
{
	cout << "Enter first value:";
	cin >> a;
	cout << "Enter second value:";
	cin >> b;
}

inline void Operation::sum()
{
	add = a + b;
	cout << "Addition of two numbers:" << a + b << endl;
}

inline void Operation::diff()
{
	sub = a - b;
	cout << "Difference of two numbers:" << a - b << endl;
}

inline void Operation::product()
{
	mult = a * b;
	cout << "Product of two numbers:" << a * b << endl;
}

inline void Operation::division()
{
	div = a / b;
	cout << "Division of two numbers:" << a / b << endl;
}

int main()
{
	cout << "Program using inline functions" << endl;
	Operation s;
	s.get();
	s.sum();
	s.diff();
	s.product();
	s.division();
	return 0;
}