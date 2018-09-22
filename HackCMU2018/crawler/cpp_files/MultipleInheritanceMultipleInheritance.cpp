// MultipleInheritance.cpp : 

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class A
{
public:
	A()
	{
		cout << "A constructor called " << endl;
	}
	~A()
	{
		cout << "A Destructor called " << endl;
	}
};

class B : public A
{
public:
	B()
	{
		cout << "B constructor called " << endl;
	}
	~B()
	{
		cout << "B Destructor called " << endl;
	}
};

class C : public B
{
public:
	C()
	{
		cout << "C constructor called " << endl;
	}
	~C()
	{
		cout << "C Destructor called " << endl;
	}
};

int main()
{
	C c;
    return 0;
}

