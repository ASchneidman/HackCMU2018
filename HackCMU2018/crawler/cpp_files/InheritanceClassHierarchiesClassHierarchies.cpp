// ClassHierarchies.cpp : Employees Database using inheritance
//

#include "stdafx.h"
#include <iostream>

using namespace std;
const int LEN = 80; // Maximum length of names
///////////////////////////////////////////////////////////////////////

class Employees
{
	char name[LEN];
	unsigned long number;
public:
	void getdata()
	{
		cout << "\nEnter last Name: "; cin >> name;
		cout << "\nEnter Number: "; cin >> number;
	}

	void putdata() const
	{
		cout << "\n Name: " << name;
		cout << "\n Number: " << number;
	}
};
/////////////////////////////////////////////////////////////////////
class Manager : public Employees
{
	char title[LEN];
	double dues;
public:
	void getdata()
	{
		Employees::getdata();
		cout << "Enter the title: "; cin >> title;
		cout << "Enter the dues: "; cin >> dues;
	}

	void putdata()
	{
		Employees::putdata();
		cout << "\n Title: " << title;
		cout << "\n Giolf Club dues: " << dues;
	}
};
/////////////////////////////////////////////////////////////////////
class Scientist:public Employees 
{
	int pubs;
public:
	void getdata()
	{
		Employees::getdata();
		cout << "Enter number of pubs:"; cin >> pubs;
	}
	void putdata() const
	{
		Employees::putdata();
		cout << "\n Number of publications: " << pubs;
	}
};
///////////////////////////////////////////////////////////////////
class Laborer :public Employees
{
};

int main()
{
	Manager m1, m2;
	Scientist s1;
	Laborer l1;
	cout << endl;  // get data for several employees
	cout << "\n Enter data for Manager1";
	m1.getdata();

	cout << "\n Enter data for Manager2";
	m2.getdata();

	cout << "\n Enter data for Scientist 1";
	s1.getdata();

	cout << "\n Enter data for laborer 1";
	l1.getdata();

	cout << "\n Data on Manager1";
	m1.putdata();

	cout << "\n Data on Manager2";
	m2.putdata();

	cout << "\n Data on Scientist 1";
	s1.putdata();

	cout << "\n Data on laborer 1";
	l1.putdata();

	cout << endl;
    return 0;
}

