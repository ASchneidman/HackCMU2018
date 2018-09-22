#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;

const int dir[8][2] = {
	{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
	{2, 1}, {-2, 1}, {2, -1}, {-2, -1}
};
int vis[9][9];

struct Square {
	int x, y, deep;
	Square(int x, int y, int d): x(x), y(y), deep(d) { }
	bool operator == (const Square& u) {
		return u.x == x && u.y == y;
	}
};

int bfs(Square& src, Square& des) {
	queue<Square> q;
	q.push(src);
	vis[src.x][src.y] = 1;
	while (!q.empty()) {
		Square cur = q.front(); q.pop();
		if (cur == des) return cur.deep;
		for (int i = 0; i < 8; i++) {
			int x = cur.x + dir[i][0];
			int y = cur.y + dir[i][1];
			if (x > 0 && x <= 8 && y > 0 && y <= 8 && !vis[x][y]) {
				q.push(Square(x, y, cur.deep+1));
				vis[x][y] = 1;
			}
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input/uva439.in", "r", stdin);
  #endif
	char x1, x2;
	int y1, y2;
	while (cin >> x1 >> y1 >> x2 >> y2) {
		memset(vis, 0, sizeof(vis));
		Square src(x1-'a'+1, y1, 0), des(x2-'a'+1, y2, 0);
		cout << "To get from " << x1 << y1 << " to "
			<< x2 << y2 << " takes " << bfs(src, des)
			<< " knight moves." << endl;
	}
	return 0;
}
