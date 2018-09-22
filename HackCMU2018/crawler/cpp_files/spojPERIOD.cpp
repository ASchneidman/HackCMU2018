#include <bits/stdc++.h>
using namespace std;

vector<int> build_failure_function(string pattern)
{
	int m =pattern.length();
	vector<int> failure_function(m+1);
	failure_function[0] = -1;
	for(int i=0;i<m;++i)
	{
		failure_function[i+1] =failure_function[i];
		while(failure_function[i+1] > -1 and pattern[failure_function[i+1]] != pattern[i])
		{
			failure_function[i+1] = failure_function[failure_function[i+1]];
		}
		failure_function[i+1]++;
	}
	return failure_function;
}

void solve(string s)
{
	int gcdnum;
	vector<int> failure_function = build_failure_function(s);
	//for(int i=1;i<failure_function.size();++i)
	//	cout<<failure_function[i]<<" ";
	//cout<<endl;
	for(int i=1;i<failure_function.size();++i)
	{
		//cout<<failure_function[i]<<" ";
		if(i==2 and failure_function[i]==1)
		{
			cout<<"2 2"<<endl;
		}
		else if(failure_function[i] != 0 and (i%(i - failure_function[i])==0))
		{
			cout<<i<<" "<<i/(i - failure_function[i])<<endl;
		}
	}
	//cout<<endl;
}
int main()
{
	int t,n;
	string s;
	ios::sync_with_stdio(false);
	int i=1;
	cin>>t;
	while(t--)
	{

		cin>>n>>s;
		cout<<"Test case #"<<i<<endl;
		solve(s);
		i++;
	}
}