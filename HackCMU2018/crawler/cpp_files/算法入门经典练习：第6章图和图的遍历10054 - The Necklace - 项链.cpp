#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

const int MAX = 60;
int G[MAX][MAX], num[MAX];
int degree[MAX], T, N;

//判断图的连通性
int dfs(int u)
{
	int sum = 0;
	num[u] = 0;
	for (int v = 1; v <= 50; v++)
		if (num[v] && G[u][v])
			sum += dfs(v);
	return sum+1;
}

//判断是否存在欧拉回路
bool is_euler()
{
	for (int i = 1; i <= 50; i++)
		if (degree[i]%2)
			return false;
	return true;
}

void euler(int u)
{
	for (int v = 1; v <= 50; v++) if (G[u][v] && degree[v] && degree[u])
	{
		G[u][v]--; G[v][u]--;
		degree[u]--; degree[v]--;
		euler(v);
		cout << v << ' ' << u << endl;
	}
}

int main()
{
	cin >> T;
	int kase = 1;
	while (kase <= T)
	{
		cout << "Case #" << kase++ << endl;
		memset(G, 0, sizeof(G));
		memset(num, 0, sizeof(num));
		memset(degree, 0, sizeof(degree));
		cin >> N;
		for (int i=0; i<N; i++)
		{
			int x, y; cin >> x >> y;
			G[x][y]++; G[y][x]++;
			num[x] = num[y] = 1;
			degree[x]++; degree[y]++;
		}
		int sum = 0, en;
		for (int i = 1; i <= 50; i++)
			if (num[i]) { sum++; en = i; }
		if (dfs(en)==sum && is_euler())
			euler(en);
		else
			cout << "some beads may be lost" << endl;
		cout << endl;
	}
	return 0;
}

