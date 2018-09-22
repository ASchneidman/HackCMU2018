#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

#define REP(i, n) for (int i=0; i<(n); ++i)
const int dir[6][3] = {{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};
int L, R, C;
char maze[30][30][30];
bool vis[30][30][30];

struct Cell {
	int x, y, z, deep;
	Cell(int _x, int _y, int _z, int _deep)
	{ x = _x; y = _y; z = _z; deep = _deep;}
	bool operator == (const Cell& u) {
		return u.x==x && u.y==y && u.z==z;
	}
};

int bfs(const Cell& start)
{
	queue<Cell> q;
	q.push(start);
	vis[start.x][start.y][start.z] = true;
	while (!q.empty())
	{
		Cell cur = q.front(); q.pop();
		if (maze[cur.x][cur.y][cur.z] == 'E')
			return cur.deep;
		for (int i=0; i<6; ++i)
		{
			int x = cur.x + dir[i][0];
			int y = cur.y + dir[i][1];
			int z = cur.z + dir[i][2];
			if (x>=0 && y>=0 && z>=0 && x<L && y<R && z<C 
				&& maze[x][y][z]!='#' && !vis[x][y][z])
			{
				q.push(Cell(x, y, z, cur.deep+1));
				vis[x][y][z] = true;
			}
		}
	}
	return -1;
}

int main()
{
	int time;
	while (cin >> L >> R >> C && L && R && C)
	{
		memset(vis, 0, sizeof(vis));
		REP(i, L) REP(j, R) REP(k, C)
			cin >> maze[i][j][k];
		REP(i, L) REP(j, R) REP(k, C)
			if (maze[i][j][k] == 'S')
			{
				time = bfs(Cell(i, j, k, 0));
				break;
			}
		if (time != -1)
			cout << "Escaped in " << time << " minute(s)." << endl;
		else
			cout << "Trapped!" << endl;
	}
	return 0;
}
