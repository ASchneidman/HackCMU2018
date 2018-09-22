// Pointer.cpp : Basic Operations on pointers
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int a = 11;
	int *p = &a;
	cout << a << endl;
	cout << *p << endl;
	cout << p << endl;
	cout << &p << endl;
	cout << "After changing " << endl;
	*p = 12;
	cout << a << endl;
	cout << *p << endl;
	int b = 20;
	p = &b;
	cout << *p << endl;

	int d = 22;
	int *m = &d;
	cout << *m << endl;
	cout << "Pointer Arithmetic " << endl;
	cout << m << endl;
	cout << m + 1 << endl;

	int a2 = 1025;
	int *p0;
	p0 = &a2;
	cout << p0 << endl;

	cout << "Some more on pointers " << endl;
	int a1 = 1025;
	int *p1;
	p1 = &a1;
	cout << "Size of integer " << sizeof(a1) << endl;
	cout << "Address of p " << p1 << "and of *p " << *p1 << endl;
	char *c;
	c = (char*)p1;
	cout << "Size of char after typecasting " << sizeof(char) << endl;
	cout << "Address of c " << c << "and *c is " << *c << endl;

	cout << "Void Pointer in " << endl;
	void *p3;
	p3 = p1;
	cout << "Address of p3 is " << p3 << endl;
	// cout << "Address of p3 is " << p3 + 1 << endl;


    return 0;
}

