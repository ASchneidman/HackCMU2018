#include "stdafx.h"
#include "Account.h"

// only use in cpp files not in header
using namespace std;

Account::Account(void) :balance(0) { }

vector<string> Account::Report()
{
	vector<string> report;
	report.push_back("Balance is " + to_string(balance));
	report.push_back("Transactions: ");
	for (auto t : log)
	{
		report.push_back(t.Report());
	}
	report.push_back("--------------------------------");
	return report;
}

bool Account::Deposit(int amt)
{
	if (amt >= 0)
	{
		balance += amt;
		log.push_back(Transaction(amt, "Deposit"));
		return true;
	}
	else
	{
		return true;
	}
}

bool Account::Withdraw(int amt)
{
	if (amt >= 0)
	{
		if (balance >= amt)
		{
			balance -= amt;
			log.push_back(Transaction(amt, "Withdraw"));
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}