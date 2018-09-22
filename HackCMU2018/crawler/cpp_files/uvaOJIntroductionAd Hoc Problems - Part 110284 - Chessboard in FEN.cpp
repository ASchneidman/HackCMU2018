#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;

const int dirN[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
						{2, 1}, {2, -1}, {-2, 1}, {-2, -1}}; 

bool isout(int x, int y)						
{
	if (x < 0 || x > 7 || y < 0 || y > 7)
	  return true;
	return false;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif

	while (true)
	{
		char board[8][8] = {0}, tmp;
		int cur = 0, curLine = 0;
		while (true)
		{
			tmp = getchar();
			if (tmp == '\n' || tmp == EOF)
			  break;
			else if (isdigit(tmp))
				while (tmp-- > '0')
				  board[curLine][cur++] = 0;	
			else if (isalpha(tmp))
			  board[curLine][cur++] = tmp;
			if (cur >= 8)
			{
				curLine++;
				cur = 0;
			}
		}
		if (curLine < 8) break;
		for (int i = 0; i < 8; i++)
		{
		  for (int j  = 0; j < 8; j++)
		  {
			  int x, y;
			  switch(board[i][j])
			  {
				case 'p':
					if (!isout(i+1, j+1) && !board[i+1][j+1]) board[i+1][j+1] = 'a';
					if (!isout(i+1, j-1) && !board[i+1][j-1]) board[i+1][j-1] = 'a';
					break;
				case 'P':
					if (!isout(i-1, j+1) && !board[i-1][j+1]) board[i-1][j+1] = 'a';
					if (!isout(i-1, j-1) && !board[i-1][j-1]) board[i-1][j-1] = 'a';
					break;
				case 'n': case 'N':
					for (int k = 0; k < 8; k++) 	
					  if (!isout(i+dirN[k][0], j+dirN[k][1]) && !board[i+dirN[k][0]][j+dirN[k][1]])
						board[i+dirN[k][0]][j+dirN[k][1]] = 'a';
					break;
				case 'b': case 'B':
					x = i, y = j;
					while (!isout(++x, ++y) && (!board[x][y] || board[x][y]=='a'))
						board[x][y] = 'a';
					x = i; y = j;
					while (!isout(++x, --y) && (!board[x][y] || board[x][y]=='a'))
						board[x][y] = 'a';
					x = i; y = j;
					while (!isout(--x, ++y) && (!board[x][y] || board[x][y]=='a'))
						board[x][y] = 'a';
					x = i; y = j;
					while (!isout(--x, --y) && (!board[x][y] || board[x][y]=='a'))
						board[x][y] = 'a';
					break;
				case 'r': case 'R':
					x = i; y = j;
					while (!isout(++x, y) && (!board[x][y] || board[x][y]=='a'))
						board[x][y] = 'a';
					x = i; y = j;
					while (!isout(--x, y) && (!board[x][y] || board[x][y]=='a'))
						board[x][y] = 'a';
					x = i; y = j;
					while (!isout(x, ++y) && (!board[x][y] || board[x][y]=='a'))
						board[x][y] = 'a';
					x = i; y = j;
					while (!isout(x, --y) && (!board[x][y] || board[x][y]=='a'))
						board[x][y] = 'a';
					break;
				case 'q': case 'Q':
					x = i; y = j;
					while (!isout(++x, ++y) && (!board[x][y] || board[x][y]=='a'))
						board[x][y] = 'a';
					x = i; y = j;
					while (!isout(++x, --y) && (!board[x][y] || board[x][y]=='a'))
						board[x][y] = 'a';
					x = i; y = j;
					while (!isout(--x, ++y) && (!board[x][y] || board[x][y]=='a'))
						board[x][y] = 'a';
					x = i; y = j;
					while (!isout(--x, --y) && (!board[x][y] || board[x][y]=='a'))
						board[x][y] = 'a';
					x = i; y = j;
					while (!isout(++x, y) && (!board[x][y] || board[x][y]=='a'))
						board[x][y] = 'a';
					x = i; y = j;
					while (!isout(--x, y) && (!board[x][y] || board[x][y]=='a'))
						board[x][y] = 'a';
					x = i; y = j;
					while (!isout(x, ++y) && (!board[x][y] || board[x][y]=='a'))
						board[x][y] = 'a';
					x = i; y = j;
					while (!isout(x, --y) && (!board[x][y] || board[x][y]=='a'))
						board[x][y] = 'a';
					break;
				case 'k': case 'K':	
					if (!isout(i-1, j-1) && !board[i-1][j-1]) board[i-1][j-1] = 'a';
					if (!isout(i-1, j) && !board[i-1][j]) board[i-1][j] = 'a';
					if (!isout(i-1, j+1) && !board[i-1][j+1]) board[i-1][j+1] = 'a';
					if (!isout(i, j+1) && !board[i][j+1]) board[i][j+1] = 'a';
					if (!isout(i+1, j+1) && !board[i+1][j+1]) board[i+1][j+1] = 'a';
					if (!isout(i+1, j) && !board[i+1][j]) board[i+1][j] = 'a';
					if (!isout(i+1, j-1) && !board[i+1][j-1]) board[i+1][j-1] = 'a';
					if (!isout(i, j-1) && !board[i][j-1]) board[i][j-1] = 'a';
					break;
				}
		  }
		}
		int num = 0;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				if (!board[i][j])
					num++;
		printf("%d\n", num);
	}
	return 0;
}
