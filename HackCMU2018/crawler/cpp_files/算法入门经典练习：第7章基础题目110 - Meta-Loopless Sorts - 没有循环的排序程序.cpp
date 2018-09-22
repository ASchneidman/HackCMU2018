#include <iostream>
#include <string>
#include <vector>
using namespace std;

const char var[9] = "abcdefgh";
vector<char> A;
int n;


void print_if(int cur)
{

	if (cur == n)
	{
		int j = cur; while (j--) cout << "  ";
		cout << "writeln(";
		for (int i = 0; i < n; i++)
		{
			if (i != 0) cout << ",";
			cout << A[i];			
		}
		cout << ")" << endl;
	}
	else for (int i = cur; i >= 0; i--)
	{
		int j = cur; while (j--) cout << "  ";
		if (i == cur)
			cout << "if " << A[i-1] << " < " << var[cur] << " then" << endl;
		else if (i == 0)
			cout << "else" << endl;
		else
			cout << "else if " << A[i-1] << " < " << var[cur] << " then" << endl;
		A.insert(A.begin() + i, 'a'+cur);
		print_if(cur+1);
		A.erase(A.begin() + i);
	}
}

int main()
{
	int M;
	cin >> M;
	while (M--)
	{
		cin >> n;
		cout << "program sort(input,output);\nvar" << endl;
		for (int i = 0; i < n; i++)
		{
			if (i != 0) cout << ",";
			cout << var[i];	
		}
		cout << " : integer;\nbegin\n  readln(";
		for (int i = 0; i < n; i++)
		{
			if (i != 0) cout << ",";
			cout << var[i];			
		}
		cout << ");" << endl;
		A.clear();
		A.push_back('a');
		print_if(1);
		cout << "end." << endl;
		if (M) cout << endl;
	}
	return 0;
}

