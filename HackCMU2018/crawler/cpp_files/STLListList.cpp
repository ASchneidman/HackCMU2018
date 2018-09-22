// List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;

// function for printing the list
void showlist(list<int> g)
{
	list<int>::iterator it;
	for (it = g.begin(); it != g.end(); it++)
	{
		cout << "\t " << *it;
	}
	cout << endl;
}


int main()
{
	list<int> list1, list2;
	for (int i = 0; i < 10; i++)
	{
		list1.push_back(i * 2);
		list2.push_front(i * 3);
	}
	cout << "List1 is : " << endl;
	showlist(list1);
	cout << "List2 is : " << endl;
	showlist(list2);

	cout << "List front " << list1.front() << endl;
	cout << "List end " << list1.back() << endl;
	cout << "List1 Pop front ";
	list1.pop_front();
	showlist(list1);
	cout << "List2 Pop front ";
	list2.pop_front();
	showlist(list2);
	cout << "Reverse the list " << endl;
	list1.reverse();
	list2.reverse();
	showlist(list1);
	showlist(list2);
	cout << "Sort the list " << endl;
	list1.sort();
	list2.sort();
	showlist(list1);
	showlist(list2);
	cout << endl;
	cout << "List is similar to doubly linked list where data can be inserted either front or back ";
	cout << endl;
	list<int> objlist;
	objlist.push_back(4);
	objlist.push_back(3);
	objlist.push_back(2);
	objlist.push_back(1);

	list<int>::iterator it = objlist.begin();
	while (it != objlist.end())
	{
		cout << *it << endl;
		it++;
	}
	cout << endl;
	cout << "No random access of elements is possible in list because of non contiguos vectors ";
	cout << endl;

	cout << "Ways to initialize the list " << endl;
	list<int> listInt;
	for (int i = 0; i < 10; i++)
	{
		listInt.push_back(i);
	}

	for (int val : listInt)
		cout << val << " ";
	cout << endl;

	cout << "Create and intialize " << endl;
	list<int> listInt1(5, 120);
	for (int val : listInt1)
		cout << val << " ";
	cout << endl;


	list<int> list3({1, 2, 3, 4, 5, 6, 7, 8, 9, 10 });
	//Display The List
	std::copy(list3.begin(), list3.end(),
		std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	cout << "Erasing elements " << endl;
	// Iterator itList points to element next to begin
	std::list<int>::iterator itList = ++(list3.begin());

	// Erasing element represented by iterator itList i.e. 3
	itList = list3.erase(itList);

	//Display The List
	std::copy(list3.begin(), list3.end(),
		std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	cout << "Remove elements while iterating " << endl;
	list<int> list4({ 2, 3, 3, 4, 8, 9, 4, 6, 8, 3 });
	list<int>::iterator it1 = list4.begin();

	while (it1 != list4.end())
	{
		if ((*it1) % 3 == 0)
			it = list4.erase(it1);
		else
			it1++;
	}

	// Iterate over the list using for_each & Lambda Function and display contents
	std::for_each(list4.begin(), list4.end(), [](const int & val) {
		std::cout << val << ",";
	});
	std::cout << std::endl;
    return 0;
}

