#include <cstdio>
#include <algorithm>
using namespace std;

char grid[2][101][101];

bool lose(char a, char b)
{
	if (a == 'S' && b == 'R')
	  return true;
	if (a == 'P' && b == 'S')
	  return true;
	if (a == 'R' && b == 'P')
	  return true;
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif

	int kase;
	scanf("%d", &kase);
	while (kase--)
	{
		int r, c, n;
		scanf("%d%d%d", &r, &c, &n);
		for (int  i = 0; i < r; i++)
		  for (int j = 0; j < c; j++)
			scanf("\n%c", &grid[0][i][j]);
		int src = 1, des = 0;
		while (n--)
		{
			src ^= des ^= src ^= des;
			for (int  i = 0; i < r; i++)
				for (int j = 0; j < c; j++)
				{
				  if (i-1>=0 && lose(grid[src][i][j], grid[src][i-1][j])) 
				  {
					  grid[des][i][j] = grid[src][i-1][j];
					  continue;
				  }
				  if (i+1<r && lose(grid[src][i][j], grid[src][i+1][j])) 
				  {
					  grid[des][i][j] = grid[src][i+1][j];
					  continue;
				  }
				  if (j-1>=0 && lose(grid[src][i][j], grid[src][i][j-1])) 
				  {
					  grid[des][i][j] = grid[src][i][j-1];
					  continue;
				  }
				  if (j+1<c && lose(grid[src][i][j], grid[src][i][j+1])) 
				  {
					  grid[des][i][j] = grid[src][i][j+1];
					  continue;
				  }
				  grid[des][i][j] = grid[src][i][j];
			  }
		}
		for (int i = 0; i < r; i++)
		{
		  for (int j = 0; j < c; j++)
			putchar(grid[des][i][j]);
		  putchar(10);
		}
		if (kase) putchar(10);
	}
	return 0;
}
