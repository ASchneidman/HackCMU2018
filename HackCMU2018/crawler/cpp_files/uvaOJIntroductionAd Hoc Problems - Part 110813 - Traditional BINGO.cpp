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

	int kase;
	scanf("%d", &kase);
	while (kase--)
	{
		int row[5] = {0,0,1,0,0}, col[5] = {0,0,1,0,0}, l = 1, r = 1;
		int mark[80];
		memset(mark, -1, sizeof(mark));
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				int tmp;
				scanf("%d", &tmp);
				if (i == 2 && j == 2) j++;		//continue dont work
				mark[tmp] = i*5 +j;
			}
		}
		bool over = false;
		for (int i = 0; i < 75; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			if (over) continue;
			int n = mark[tmp];
			if (n == -1) continue;
			if (++row[n/5] == 5)
				over = true;
			if (++col[n%5] == 5)
			  over = true;
			if (n/5 - n%5 == 0 && ++l == 5)
			  over = true;
			if (n/5 + n%5 == 4 && ++r == 5)
			  over = true;
			if (over)
				printf("BINGO after %d numbers announced\n", i+1);
		}
	}
	return 0;
}
