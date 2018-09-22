#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<queue>
using namespace std;

const int maxn = 20 + 1;
int dir[4][2] = {
  {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

int m, n, k;
int map[maxn][maxn];
bool vis[maxn][maxn][maxn];

struct Cell {
  int x, y;
  int depth, obst;
  Cell(int x, int y, int d = 0, int b = 0): x(x), y(y), depth(d), obst(b) {}
  Cell next(int i) {
    Cell c = Cell(x + dir[i][0], y + dir[i][1], depth + 1);
    if (map[c.x][c.y]) c.obst = obst + 1;
    return c;
  }
  bool arrive() { return x == m - 1 && y == n - 1; }
  bool valid() { return x >= 0 && x < m && y >= 0 && y < n && obst <= k; }
};

int bfs() {
  queue<Cell> q;
  memset(vis, 0, sizeof(vis));
  vis[0][0][0] = true;
  q.push(Cell(0, 0));
  while (!q.empty()) {
    Cell u = q.front(); q.pop();
    if (u.arrive()) return u.depth;
    for (int i = 0; i < 4; i++) {
      Cell v = u.next(i);
      if (v.valid() && !vis[v.x][v.y][v.obst]) {
        vis[v.x][v.y][v.obst] = true;
        q.push(v);
      }
    }
  }
  return -1;
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input/uva1600.in", "r", stdin);
  #endif
	int T;
  cin >> T;
  while (T--) {
    cin >> m >> n >> k;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        cin >> map[i][j];
    cout << bfs() << endl;
  }
  return 0;
}
