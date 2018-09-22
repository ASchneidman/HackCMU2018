#include <cstdio>
#include <cstring>
using namespace std;

const char suit[4] = {'S', 'H', 'D', 'C'};
const char rank[4] = {'J', 'Q', 'K', 'A'};

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("data.in", "r", stdin);
		freopen("data.out", "w", stdout);
	#endif
	int num[4][5];
	while (true)
	{
		memset(num, 0, sizeof(num));
		for (int i = 0; i < 13; i++)
		{
			int ss;
			char r = getchar(), s = getchar();
			getchar();
			if (r == -1) return 0;
			for (int j = 0; j < 4; j++)
				if (s == suit[j]) ss = j;
			num[ss][4]++;
			for (int j = 0; j < 4; j++)
				if (r == rank[j])
					num[ss][j]++;
		}
		int goals = 0, max = 0, maxi = 0;
		bool stop[4] = {false};
		//rules 1,2,3,4
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				if (num[i][j])
				{
					goals += j + 1;
					if (j < 3 && num[i][4]+j < 4)
						goals--;
					if (j > 0 && num[i][4]+j > 3)
					  stop[i] = true;
				}
		if (goals >= 16 && stop[0] && stop[1] && stop[2] && stop[3])
		{
			puts("BID NO-TRUMP");
			continue;
		}
		for (int i = 0; i < 4; i++) 
		{
			if (num[i][4] == 2)
				goals++;
			else if (num[i][4] == 1)
				goals += 2;
			else if (num[i][4] == 0)
				goals += 2;
			if (max < num[i][4])
			{
				max = num[i][4];
				maxi = i;
			}
		}
		if (goals < 14)
		{
			puts("PASS");
			continue;
		}
		printf("BID %c\n", suit[maxi]); 
	}
	return 0;
}


