#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

bool G[110][110], vis[110];
int value[110], rest[110];

bool bfs(int u, int des)
{
	memset(vis, 0, sizeof(vis));
	queue<int> q; q.push(u);
	vis[u] = true;
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (int v = 1; v <= des; v++)
			if (G[cur][v] && !vis[v])
			{
				if (v == des) return true;
				q.push(v);
				vis[v] = true;
			}
	}
	return false;
}

bool dfs(int u, int des, int energy)
{
	if (u == des) return true;
	for (int v=1; v<=des; v++)
		if (G[u][v] && energy+value[v] > 0)
		{
			if (!rest[v])
			{
				rest[v] = energy+value[v];
				if (dfs(v, des, rest[v])) return true;
			}
			else if (energy+value[v] > rest[v] && bfs(v, des))
				return true;
		} 
	return false;
}

int main()
{
	int n, doors, to;
	while (cin >> n && n != -1)
	{
		memset(rest, 0, sizeof(rest));
		memset(G, 0, sizeof(G));
		for (int i=1; i<=n; i++)
		{
			cin >> value[i] >> doors;
			for (int j = 0; j < doors && cin >> to; j++)
				 G[i][to] = true;
		}
		cout << (dfs(1, n, 100) ? "winnable" : "hopeless") << endl;
	} 
	return 0;
}
