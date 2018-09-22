// Namespace.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

namespace first
{
	int val = 50;
}

// Global Variable
int val = 100;

namespace ns1
{
	int value()
	{
		return 5;
	}
}

namespace ns2
{
	const double x = 100;
	double value()
	{
		return 2 * x;
	}
}

// class and namespace
namespace ns3
{
	void display();
	class Test
	{
	public:
		void Display()
		{
			cout << "ns3::Test::Display() " << endl;
		}
	};
}

void ns3::display()
{
	cout << "Display " << endl;
}

// nested namespace
namespace outer
{
	int x = 10;
	namespace inner
	{
		int z = x;
	}
}



int main()
{
	int val = 200;
	cout << first::val << endl;
	cout << ns1::value() << endl;
	cout << ns2::value() << endl;
	cout << ns2::x << endl;
	ns3::Test Obj;
	Obj.Display();
	ns3::display();
	cout << outer::inner::z << endl;
	return 0;
}

