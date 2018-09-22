#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char grid[60][60];


void dfs2(int i, int j)
{
	if (grid[i][j]!='X') return;
	grid[i][j] = '*';			
	dfs2(i, j-1);
	dfs2(i, j+1);
	dfs2(i-1, j);
	dfs2(i+1, j);	
}

int dfs1(int i, int j)
{
	if (grid[i][j]!='*' && grid[i][j]!='X') return 0;
	int dots = 0;
	if (grid[i][j] == 'X')
	{
		++dots;
		grid[i][j] = '*';
		dfs2(i, j-1);
		dfs2(i, j+1);
		dfs2(i-1, j);
		dfs2(i+1, j);
	}
	grid[i][j] = '.';
	dots += dfs1(i, j-1);
	dots +=	dfs1(i, j+1);
	dots +=	dfs1(i-1, j);
	dots +=	dfs1(i+1, j);
	return dots;
}

int main()
{
	int kase = 0, m, n;
	while (cin >> n >> m && m)
	{
		memset(grid, 0, sizeof(grid));
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				cin >> grid[i+1][j+1];
		int cnt = 0, dots[100];
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				if (grid[i][j]=='*' || grid[i][j]=='X')
					dots[cnt++] = dfs1(i, j);
		cout << "Throw " << ++kase << endl;
		sort(dots, dots+cnt);
		cout << dots[0];
		for (int i=1; i<cnt; ++i)
			cout << ' ' << dots[i];
		cout << endl << endl;
	}
	return 0;
}
