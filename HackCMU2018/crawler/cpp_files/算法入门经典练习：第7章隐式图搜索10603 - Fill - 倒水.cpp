#include <iostream>
#include<string>
#include <queue>
#include <cstring>
using namespace std;

const int MAXN = 200;
int cap[3], all;
int vis[MAXN][MAXN];

struct State
{
	int v[3];
	int amount;
	bool operator<(const State& x) const
	{
		return x.amount < amount;
	}	
};

void bfs()
{
	priority_queue<State> q;
	State init = { 0, 0, cap[2], 0};
	q.push(init);
	vis[0][0] = 1;
	while (!q.empty())
	{
		State u = q.top(); q.pop();
		if (u.v[0] == all || u.v[1] == all || u.v[2] == all)
		{
			cout << u.amount << ' ' << all << endl;
			return;
		}
		for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) if (i != j)
		{
			int pour = min(u.v[i], cap[j] - u.v[j]);
			State v = u;
			v.v[i] -= pour;
			v.v[j] += pour;
			v.amount += pour;
			if (!vis[v.v[0]][v.v[1]])
			{
				vis[v.v[0]][v.v[1]] = 1;
				q.push(v);
			}
		}
	}
}

int main()
{
	int kase;
	cin >> kase;
	while (kase--)
	{
		cin >> cap[0] >> cap[1] >> cap[2] >> all;
		memset(vis, 0, sizeof(vis));
		bfs();
	}
	return 0;
}