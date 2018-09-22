// AccessCombinations.cpp : publicily and privately derived classes
//

#include "stdafx.h"
#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////

class A
{
private:
	int privdataA;
protected:
	int protdataA;
public:
	int pubdataA;
};

class B : public A
{
public:
	void funct()
	{
		int a;
	//	a = privdataA; error : not accessible
		a = protdataA; // OK
		a = pubdataA; // OK
	}
};

class C : private A
{
public:
	void funct()
	{
		int a;
	//	a = privdataA;
		a = protdataA; // OK
		a = pubdataA; // OK
	}
};

int main()
{
	int a;
	B objB;
	//a = objB.privdataA;
	//a = objB.protdataA;
	a = objB.pubdataA; // OK (A public to B)
	C objC;
//	a = objC.privdataA; // error
//	a = objC.privdataA; // error
//	a = objC.pubdataA; // error
    return 0;
}

