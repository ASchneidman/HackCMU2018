// Constructors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Fraction
{
	int m_iNumerator;
	int m_iDenominator;
public:
	Fraction() // Default Constructor
	{
		m_iNumerator = 0;
		m_iDenominator = 1;
	}

	// Fraction with two parameters, one parameter having a default value
	Fraction(int numerator, int denominator = 1)
	{
		_ASSERT(denominator != 0);
		m_iNumerator = numerator;
		m_iDenominator = denominator;
	}

	// Default constructor - Reducing the redundant work by providing the default values.
	// Its defined in way that it can take one or two  user provided values.
	Fraction(int numerator = 0, int denominator = 1)
	{
		_ASSERT(denominator != 0);
		m_iNumerator = numerator;
		m_iDenominator = denominator;
	}

	int getNumerator() { return m_iNumerator; }
	int getDenominator() { return m_iDenominator; }
	double getValue() { return static_cast<double>(m_iNumerator) / m_iDenominator; }
};

int main()
{
	Fraction frac;
	int x{ 3 }; // Uniform initialization of an integer
	Fraction six(6); // calls fraction(int , int) constructor, second parameter uses default value
	Fraction fiveThirds{ 5, 3 }; // Will call Fraction(5, 3)
	cout << frac.getNumerator() << " / " << frac.getDenominator() << "\n";
    return 0;
}

