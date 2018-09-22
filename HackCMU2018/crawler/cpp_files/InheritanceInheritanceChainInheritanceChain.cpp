// InheritanceChain.cpp : Defines the entry point for the console application.
// Order of construction of inheritance chains

#include "stdafx.h"
#include <iostream>

class A
{
public:
	A()
	{
		std::cout << "A " << std::endl;
	}
};

class B: public A
{
public:
	B()
	{
		std::cout << "B " << std::endl;
	}
};

class C : public B
{
public:
	C()
	{
		std::cout << "C " << std::endl;
	}
};

class D : public C
{
public:
	D()
	{
		std::cout << "D " << std::endl;
	}
};

int main()
{
	std::cout << "Constructing A " << std::endl;
	A cA;
	std::cout << "Constructing B " << std::endl;
	B cB;
	std::cout << "Constructing C " << std::endl;
	C cC;
	std::cout << "Constructing D " << std::endl;
	D cD;
    return 0;
}

