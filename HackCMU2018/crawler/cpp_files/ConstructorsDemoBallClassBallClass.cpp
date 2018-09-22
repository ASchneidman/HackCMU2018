// BallClass.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Ball
{
	string m_sColor;
	double m_dRadius;
public:
	// Default constructors with no parameters 
	Ball()
	{
		m_sColor = "black";
		m_dRadius = 10.0;
	}

	// Constructors with only color parameter radius with default value
	Ball(const string &color)
	{
		m_sColor = color;
		m_dRadius = 10.0;
	}
	// Constructors with only radius parameter radius with default value
	Ball(double radius)
	{
		m_sColor = "Black";
		m_dRadius = radius;
	}
	// Constructor with both color and radius parameters 
	Ball(const string &color, double radius)
	{
		m_sColor = color;
		m_dRadius = radius;
	}

	void print()
	{
		cout << "Color: " << m_sColor << ", radius: " << m_dRadius << "\n";
	}
};

int main()
{
	Ball def;
	def.print();

	Ball blue("blue");
	blue.print();

	Ball twenty(20.0);
	twenty.print();

	Ball blueTwenty("Blue", 20.00);
	blueTwenty.print();

    return 0;
}

