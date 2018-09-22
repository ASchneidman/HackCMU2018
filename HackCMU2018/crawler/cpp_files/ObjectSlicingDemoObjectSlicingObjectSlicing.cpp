// ObjectSlicing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class Base
{
protected:
	int i;
public:
	Base(int a)
	{
		i = a;
	}

	virtual void Display()
	{
		cout << "I am base class object, i = " << i << endl;
	}
};

class Derived : public Base
{
	int j;
public:
	Derived(int a, int b) : Base(a) 
	{
		j = b;
	}

	virtual void Display()
	{
		cout << "I am derived class object, i = " << i << ", j = " << j << endl;
	}
};

void func1(Base &b)
{
	b.Display();
}

int main()
{
	Base b(10);
	Derived d(20, 30);
	func1(b);
	func1(d);

    return 0;
}

