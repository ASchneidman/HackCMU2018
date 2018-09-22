#include <cstdio>
#include <algorithm>
#include <cstring> 
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	int num[5], vis[55];
	while(true)
	{
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < 5; i++)
		{
			scanf("%d", &num[i]);
			vis[num[i]] = true;
		}
		if (!num[0])
			return 0;
		sort(num, num+3);
		sort(num+3, num+5);
		if (num[4] > num[2])
		{
			if (num[3] > num[2])
			{
				int i = 0;
				while (vis[++i]);
				printf("%d\n", i>52 ? -1 : i);
			}
			if (num[3] > num[1] && num[3] < num[2])
			{
				int i = num[1];
				while (vis[++i]);
				printf("%d\n", i>52 ? -1 : i);
			}
			if (num[3] < num[1])
			{
				int i = num[2];
				while (vis[++i]);
				printf("%d\n", i>52 ? -1 : i);
			}
		}
		else if (num[4] > num[1] && num[3] > num[1])
		{
			int i = num[1];
			while (vis[++i]);
			printf("%d\n", i>52 ? -1 : i);
		}
		else
			printf("-1\n");
	}
	return 0;
}
