// BasicInheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	string m_name;
	int m_age;
	Person(string name = "", int age = 0) : m_name(name), m_age(age) { }

	string getName() const { return m_name; }
	int getAge() const { return m_age; }
};

class BaseballPlayer : public Person
{
public:
	double m_battingAverage;
	int m_homeRuns;

	BaseballPlayer(double battingAvg = 0.0, int homeRun = 0) : m_battingAverage(battingAvg), m_homeRuns(homeRun) { }

	double getPlayerName() const { return m_battingAverage; }
	int getPlayerAge() const { return m_homeRuns; }

};

class Employee : public Person
{
public:
	double m_hourlySalary;
	long m_employeeId;

	Employee(double salary = 0.0, long id = 01) : m_hourlySalary(salary), m_employeeId(id) { }

	double getHrSalary() const { return m_hourlySalary; }
	double getEmpId() const { return m_employeeId; }

};

int main()
{
	BaseballPlayer joe;
	joe.m_name = "Joe";
	joe.m_age = 22;
	joe.m_battingAverage = 44.20;
	joe.m_homeRuns = 200;

	cout << "Name is " << joe.getName() << endl;
	cout << "Age is " << joe.getAge() << endl;
	cout << "Player Name is " << joe.getPlayerName() << endl;
	cout << "Player Age is " << joe.getPlayerAge() << endl;

	Employee emp(110000.00, 400.20);
	emp.m_name = "Maverick";

	cout << "Name is " << emp.m_name << endl;
	cout << "Employee Salary is " << emp.getHrSalary() << endl;
	cout << "Employee Id " << emp.getEmpId() << endl;



    return 0;
}

