// MyArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

namespace Animals
{
	enum Animals
	{
		CHICKEN,
		DOG,
		CAT,
		ELEPHANT,
		DUCK,
		SNAKE,
		MAX_ANIMALS
	};
}

int main()
{
	short m_aPrime[6];  // hold the first 5 elements
	m_aPrime[0] = 2;
	m_aPrime[1] = 3;
	m_aPrime[2] = 5;
	m_aPrime[3] = 7;
	m_aPrime[4] = 11; 
	
	cout << "The lowest prime number is: " << m_aPrime[0] << "\n";
	cout << "The Sum of the first 5 primes is: " << m_aPrime[0] + m_aPrime[1] + m_aPrime[2] + m_aPrime[3] + m_aPrime[4] << "\n";
	cout << "The array element which are not initialized, they are default set to 0" << m_aPrime[5] << endl;

	// Array of type double
	double m_aMyArray[3];  // Allocate 3 variables
	m_aMyArray[0] = 2.0;
	m_aMyArray[1] = 3.0;
	m_aMyArray[2] = 4.3;

	cout << "The average is of m_aMyArray " << (m_aMyArray[0] + m_aMyArray[1] + m_aMyArray[2]) / 3 << endl;
	
	// Passing enum  to initialize array
	int legs[Animals::MAX_ANIMALS] = { 2, 4, 4, 4, 2, 0 };
	cout << "An elephant has " << legs[Animals::ELEPHANT] << " legs. \n";

	








	return 0;
}

