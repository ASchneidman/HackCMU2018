#include <cstdio>
#include <algorithm>
#include <cstring> 
#include <cstring>
using namespace std;

const int MAX = 1000000 + 10;
int player[MAX]; 
int map[100];

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
		memset(map, 0, sizeof(map));
		int pnum, snum, dnum;
		scanf("%d%d%d", &pnum, &snum, &dnum);
		for (int i = 0; i < pnum; i++)
		  player[i] = 1;
		for (int i = 0; i < snum; i++)
		{
			int s, e;
			scanf("%d%d", &s, &e);
			map[s] = e;
		}
		int cur = 0, isover = 0;
		for (int i = 0; i < dnum; i++) 
		{
			int roll;
			scanf("%d", &roll);
			if (!isover)
			{
				player[cur] += roll;	
				if (map[player[cur]])
					player[cur] = map[player[cur]];
				if (player[cur] >= 100)					//注意超过100游戏结束
				{
					player[cur] = 100;
					isover = 1;
				}
				if (cur < pnum-1) cur++;
				else cur = 0;
			}
		}
		for (int i = 0; i < pnum; i++)
			printf("Position of player %d is %d.\n", i+1, player[i]);
	}
	return 0;
}
