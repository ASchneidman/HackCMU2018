// VoidFunctions.cpp 

#include "stdafx.h"
#include <iostream>
using namespace std;

void test()
{
	cout << "Hello from void " << endl;
	return (void)"Doesn't print";
}
void fun()
{
	cout << "Hello" << endl;
	return;
}

void work()
{
	cout << "The void function has returned "
		" a void() !!! \n";
}

void test1()
{
	// Returning void function
	return work();
}

int main()
{
	test();
	fun();
	test1();
    return 0;
}

