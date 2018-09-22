// Deque.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <deque>
using namespace std;

void showDeque(deque<int> dq)
{
	deque<int>::iterator it;
	for (it = dq.begin(); it < dq.end(); it++)
	{
		cout << *it << "\t";
	}
}

int main()
{
	deque<int> dq;
	dq.push_back(10);
	dq.push_front(20);
	dq.push_back(30);
	dq.push_front(15);
	cout << endl;
	cout << "The deque is " << endl;
	showDeque(dq);
	cout << endl;
	cout << "Size is " << dq.size() << endl;
	cout << "Front is " << dq.front() << endl;
	cout << "Back is " << dq.back() << endl;
	cout << "Pop Front ";
	dq.pop_front();
	showDeque(dq);
	cout << endl;
	cout << "Pop back ";
	dq.pop_back();
	showDeque(dq);

	// Deque Operations 
	cout << "Insert element in deque " << endl;
	deque<int> deqObj;
	deqObj.push_back(4);
	deqObj.push_back(7);

	cout << "Deque push back " << endl;
	for (int i = 0; i < deqObj.size(); i++)
	{
		cout << deqObj[i] << " ";
	}
	cout << endl;
	cout << "Deque push front " << endl;
	deqObj.push_front(2);
	deqObj.push_front(4);

	for (int i = 0; i < deqObj.size(); i++)
	{
		cout << deqObj[i] << endl;
	}

	cout << "Element in front " << endl;
	cout << deqObj.front();
	cout << "Remove from front " << endl;
	deqObj.pop_front();
	for (int i = 0; i< deqObj.size(); i++)
		std::cout << deqObj[i] << " ";

    return 0;
}

