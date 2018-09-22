#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include <vector>
using namespace std;

const int MAXN = 1001 * 1001;

map< int, vector<int> > G;
int sheet[MAXN];
int all, col, row;

bool dfs(int u)
{
	int sum = 0;
	for (unsigned i = 0; i < G[u].size(); i++)
	{
		if (G[G[u][i]].size() && !dfs(G[u][i])) return false;
		sum += sheet[ G[u][i] ];
	}
	sheet[u] = sum;
	G[u].clear();
	return true;
}

bool toposort()
{
	for (int u = 0; u < all; u++)
		if (G[u].size() && !dfs(u)) return false;
	return true;
}

void read(int i)
{
	string str; cin.clear();
	cin >> str; str += '+';
	unsigned j = 1, alph = 0, num = 0;
	while(j < str.size())
	{
		if(isalpha(str[j]))
			alph = alph*26 + str[j] - 'A' + 1;
		else if(isdigit(str[j]))
			num = num*10 + str[j] - '0';
		else
		{
			G[i].push_back((num-1)*col+alph-1);
			num = alph = 0;
		}
		j++;
	}
}

int main()
{
	int kase;
	cin >> kase;
	while (kase--)
	{
		cin >> col >> row;
		all = row * col;
		for (int i = 0; i < all; i++)
			if (!(cin >> sheet[i]))
				read(i);
		toposort();
		for (int i = 0; i < row; i ++ )
		{
			cout << sheet[i*col];
			for (int j = 1; j < col; j++ )
				cout << " " << sheet[i*col+j];
			cout << endl;
		}
	}
	return 0;
}

