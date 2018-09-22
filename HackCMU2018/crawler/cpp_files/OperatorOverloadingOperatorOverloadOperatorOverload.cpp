// OperatorOverload.cpp : Redefining the operator with your won need.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Complex
{
private:
	int real, imag;
public:
	Complex(int r = 0, int i = 0) { real = r; imag = i; }
	Complex operator + (Complex const &obj)
	{
		Complex res;
		res.real = this->real + obj.real;
		res.imag = this->imag + obj.imag;
		return res;
	}

	void print() { cout << real << " + i " << imag << endl; }
};

class Test
{
private:
	int count;
public:
	Test() : count(5) {}
	void operator++()
	{
		count = count + 1;
	}
	void Display()
	{
		cout << "Count " << count << endl;
	}
};

int main()
{
	Test t;
	// This calls the function operator++
	++t;
	t.Display();

	Complex c1(10, 20), c2(20, 40);
	Complex C3 = c1 + c2;
	C3.print();
    return 0;
}

