// FunctionOverload.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Test
{
public:
	void print(int i)
	{
		cout << "Int : " << i << endl;
	}
	void print(double d)
	{
		cout << "Float : " << d << endl;
	}
	void print(char *c)
	{
		cout << "Char is char* " << c << endl;
	}
	void print(int a, int b)
	{
		cout << a << " " << b << endl;
	}
	//void print(const int a, const int b)   // Error because const dosent make much difference
	//{
	//	cout << a << " " << b << endl;
	//}
	//void print(int *a, int *b)		// conversion from int* to int not possible.
	//{
	//	cout << a << " " << b << endl;
	//}

	int print() { return 11; }
	// char print() { return 'a'; } // function can't be overloaded based on return type
	int print(int *ptr) { return 11; } // pointer with array function are overloaded.
	// int print(int arr[]) { return 11; }
	int main() // main i not a keyword in C++ or any other language
	{
		return 2;
	}
	int foo1()
	{
		return 10;
	}
	//int foo1()   // Method overloading does not depend on return type.
	//{
	//	return 20;
	//}
};

int main()
{
	Test obj;
	obj.print("Hello World");
	obj.print(12.12);
	obj.print(22);
	obj.print(2, 4);
    return 0;
}

