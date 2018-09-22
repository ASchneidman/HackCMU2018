#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif

	char s[22];	
	while (true)
	{
		if ((s[0] = getchar()) == 'G')
		  break;
		int cur = 1;
		while ((s[cur] = getchar()) != '\n')
			if (s[cur] != ' ')
			  cur++;
		int score = 0, frame = 1;
		for (int i = 0; i < cur; )
		{
			if (frame > 10)
			  break;
			if (s[i] == 'X')
			{
				score += 10;
				if (s[i+1] == 'X')
				{
					score += 10;
					if (s[i+2] == 'X')
					  score += 10;
					else
					  score += s[i+2] - '0';
				}
				else if (s[i+2] == '/')
				{
					score += 10;
				}
				else
				{
					score += s[i+1] + s[i+2] -2*'0';
				}
				frame++; i++;
			}
			else if (s[i+1] == '/')
			{
				score += 10;
				if (s[i+2] == 'X')
					score += 10;
				else
					score += s[i+2] - '0';
				frame++; i += 2;
			}
			else
			{
				score += s[i] + s[i+1] - 2*'0';
				frame++; i += 2;
			}
		}
		printf("%d\n", score);
	}
	return 0;
}
