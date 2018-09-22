#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

struct Node{
	int x, y;
	int color, dir, time;
	bool operator< (const Node& x) const {
		return time > x.time;
	}
};
const int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
char grid[30][30];
int vis[30][30][4][5];
int M, N;

int bfs(int x, int y)
{
	priority_queue<Node> q;
	Node start = {x, y, 0, 0, 0};
	vis[x][y][0][0] = 1;
	q.push(start);
	while (!q.empty())
	{
		Node temp, cur = q.top(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.x + dir[i][0];
			int ny = cur.y + dir[i][1];
			if (nx>=0 && nx<M && ny>=0 && ny<N && grid[nx][ny]!='#')
			{
				temp.dir = i;
				if (cur.dir == i)
				{
					temp.x = nx; temp.y = ny;
					temp.time = cur.time + 1;
					temp.color = (cur.color+1)%5;
				}
				else
				{
					if (abs(cur.dir-i) == 2)
						temp.time = cur.time+2;
					else
						temp.time = cur.time+1;
					temp.x = cur.x; temp.y = cur.y;
					temp.color = cur.color;
				}
				if (!vis[temp.x][temp.y][i][temp.color])
				{
					if (grid[temp.x][temp.y] == 'T' && temp.color == 0)
						return temp.time;
					q.push(temp);
					vis[temp.x][temp.y][i][temp.color] = 1;
				}
			}
		}
	}
	return 0;
}

int main()
{
	int kase = 1, sx, sy;
	while (cin >> M >> N && M && N)
	{
		memset(vis, 0, sizeof(vis));
		if (kase != 1) cout << endl;
		cout << "Case #" << kase++ << endl;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				cin >> grid[i][j];
				if (grid[i][j] == 'S') {
					sx = i; sy = j;
				}
			}
		}
		int time = bfs(sx, sy);
		if (time)
			cout << "minimum time = " << time << " sec" << endl;
		else
			cout << "destination not reachable" << endl;
	}
	return 0;
}