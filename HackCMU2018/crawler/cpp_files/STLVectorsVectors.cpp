// Vectors.cpp : Defines the entry point for the console application.
// Performance: It Performs better if insertion and deletion is in end only 
// and gives worst performance if insertion / deletion is at middle or at starting of vector. 

// Why Should I use std::vector ?
// std::vector give same kind of fast performance in indexing and iterations as arrays.
// But it dont have a Fixed Size limitaton like Arrays.You dont need to provide the fixed 
// size for std::vector in advance.Just start inserting elements in std::vector and it will automatically expand its size.

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <iostream>
using namespace std;

struct Sample
{
	Sample(){}
	Sample(const Sample &obj)
	{
		cout << "Sample copy constructor " << endl;
	}
};

int main()
{
	vector<int> v1;
	vector<int>::iterator i;
	vector<int>::reverse_iterator ri;
	vector<int> vectInts;

	// It increases based on the size.
	for (int i = 0; i < 10; i++)
	{
		vectInts.push_back(i);
	}
	vector<int>::iterator it = vectInts.begin();
	while (it != vectInts.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	cout << "........................." << endl;
	for (int i = 0; i != 5; i++)
	{
		v1.push_back(i); 
	}

	// Initializing with default value
	vector<int> vec(5);
	vector<string> vecStr5(5, "Hi");
	
	cout << "Initialize the vector with an array " << endl;
	string str[] = { "first", "Second", "third", "fourth" };
	vector<string> vecStr2(str, str + sizeof(str)/sizeof(string));

	// Intialize vector with list 
	cout << "Initialize string with list " << endl;
	list<string> listStr;
	listStr.push_back("first");
	listStr.push_back("Second");
	listStr.push_back("third");
	listStr.push_back("fourth");
	listStr.push_back("five");
	listStr.push_back("size");

	vector<string> vecStr3(listStr.begin(), listStr.end());
	for (std::string str : vecStr3)
		std::cout << str << std::endl;

	// Initialize with another vector 
	vector<string> vecStr1;
	vecStr1.push_back("Hi");
	vecStr1.push_back("Hello");
	vecStr1.push_back("Hey");
	vecStr1.push_back("Hiiiii");
	vector<string> vecst3(vecStr1);

	for (i = v1.begin(); i != v1.end(); i++)
	{
		cout << *i << endl;
	}
	cout << endl;
	cout << "Reverse " << endl;
	for (ri = v1.rbegin(); ri != v1.rend(); ri++)
	{
		cout << *ri << "\t";
	}
	cout << endl;
	cout << "Size " << v1.size() << endl;
	cout << "Max Size " << v1.max_size() << endl;
	cout << "Capacity " << v1.capacity() << endl;

	cout << "Accessing elements " << endl;
	vector<int> v2;
	vector<int>::iterator vi;
	for (int i = 0; i < 10; i++)
	{
		v2.push_back(i * 10);
	}
	for (vi = v2.begin(); vi < v2.end(); vi++)
	{
		cout << *vi << "\t ";
	} 
	cout << endl;
	cout << "Reference Operator v2[2] " << v2[2] << endl;
	cout << "At v2.at(2) " << v2.at(2) << endl;
	cout << "Front " << v2.front() << endl;
	cout << "Back " << v2.back() << endl;

	cout << ".................................................." << endl;
	cout << "Vector capacity using struct " << endl;

	vector<Sample> vecObj;
	cout << "Capacity :: " << vecObj.capacity() << endl;
	cout << "Size :: " << vecObj.size() << endl;

	int capcity = vecObj.capacity();
	
	for (int i = 0; i < capcity + 1; i++)
		vecObj.push_back(Sample());
	cout << "After insertion " << endl;
	cout << "Capacity :: " << vecObj.capacity() << endl;
	cout << "Size :: " << vecObj.size() << endl;
	cout << "After insertion + 1 " << endl;
	for (int i = 0; i < capcity + 1; i++)
		vecObj.push_back(Sample());
	cout << "Capacity :: " << vecObj.capacity() << endl;
	cout << "Size :: " << vecObj.size() << endl;

	cout << "Adding element in vector using Push Back " << endl;
	vector<string> vectStr;
	cout << "Size of vector " << vectStr.size() << endl;
	vectStr.push_back("AAAA");
	vectStr.push_back("BBBB");
	vectStr.push_back("CCCC");
	vectStr.push_back("DDDD");
	
	cout << "Size of vector after inserting string " << vectStr.size() << endl;

	for (string data : vectStr)
		cout << data << endl;
	
	return 0;
}

