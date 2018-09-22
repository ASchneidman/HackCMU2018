#include <iostream>
#include <cstring>
using namespace std;

int maze[300][300], w, h;
bool is_out;

void dfs(int i, int j, int& path)
{
	if (i<0 || i>=h*3 || j<0 || j>=w*3) 
	{
		is_out = true;
		return;
	}
	if (maze[i][j]) return;
	++path; maze[i][j] = 1;
	dfs(i, j-1, path);
	dfs(i, j+1, path);
	dfs(i-1, j, path);
	dfs(i+1, j, path);
}

int main()
{
	int kase = 0;
	while (cin >> w >> h && w && h)
	{
		memset(maze, 0, sizeof(maze));
		for (int i = 0; i < h; i++) for (int j = 0; j < w; j++)
		{
			char ch; cin >> ch;
			if (ch == '/')
				maze[i*3][j*3+2]=maze[i*3+1][j*3+1]=maze[i*3+2][j*3]=1;
			else
				maze[i*3][j*3]=maze[i*3+1][j*3+1]=maze[i*3+2][j*3+2]=1;
		}
		int path, k = 0, max = 0;
		for (int i=0; i<h*3; ++i) for (int j=0; j<w*3; ++j)
		{
			is_out = path = 0;
			if (!maze[i][j])
			{
				dfs(i, j, path);
				if (!is_out)
				{
					++k;
					max = max>path ? max : path;
				}
			}
		}
		cout << "Maze #" << ++kase << ":" << endl;
		if (k)
			cout << k <<" Cycles; the longest has length " << max/3 << ".";
		else
			cout << "There are no cycles.";
		cout << endl << endl;
	}
	return 0;
}
