// CopyCntr_DeepCopy.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class String
{
	char *s;
	int size;
public:
	String(const char *str = nullptr);

	~String() { delete[] s;	}
	
	String(const String&); // copy constructor
	
	void print()
	{
		cout << s << endl;
	}
	
	void change(const char *c);  // function to change
};

// Call to constructor and destructor explicitly 
class Test 
{
public:
	Test() { cout << "I am Test Constructor " << endl; }
	~Test() { cout << "I am Test Destructor" << endl; }
};

String::String(const char *str)
{
	size = strlen(str);
	s = new char[size + 1];
	strcpy(s, str);
}

void String::change(const char *str)
{
	delete[] s;
	size = strlen(str);
	s = new char[size + 1];
	strcpy(s, str);
}

String::String(const String& old_str)
{
	size = old_str.size;
	s = new char[size + 1];
	strcpy(s, old_str.s);
}


int main()
{
	String str1("GeeksQuiz");
	String str2 = str1;

	str1.print(); // what is printed ?
	str2.print();

	str2.change("GeeksforGeeks");

	str1.print(); // what is printed now ?
	str2.print();
	Test();
	Test t;
	t.~Test();
	return 0;
}

