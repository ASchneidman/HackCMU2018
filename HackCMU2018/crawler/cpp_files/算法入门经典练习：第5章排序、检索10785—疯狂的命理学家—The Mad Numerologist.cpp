#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s[27] = "AJSBKTCLUDMVENWFOXGPYHQZIR";
int mark[26];

int cmp(const void *_a, const void *_b)
{
	char *a = (char*)_a;
	char *b = (char*)_b;
	return *a - *b;
}

bool isvowel(char ch)
{
	if(ch == 'A' || ch == 'E' ||ch == 'I' ||ch == 'O' || ch == 'U')
		return true;
	return false;
}

int main()
{
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		printf("Case %d: ", i+1);
		memset(mark, 0, sizeof(mark));
		int n, v = 0, c = 0;
		char namev[300], namec[300];
		scanf("%d", &n);
		for(int j = 0; j < n; j++)
		{
			if(j%2)
			{
				int find = 0;
				while(mark[find] >= 5 || isvowel(s[find])) find++;
				mark[find]++;
				namec[c++] = s[find];
			}
			else
			{
				int find = 0;
				while(mark[find] >= 21 || !isvowel(s[find])) find++;
				mark[find]++;
				namev[v++] = s[find];
			}
		}
		namec[c] = '\0';
		namev[v] = '\0';
		qsort(namec, c, sizeof(namec[0]), cmp);
		qsort(namev, v, sizeof(namev[0]), cmp);
		int pc = 0, pv = 0;
		for(int j = 0; j < n; j++)
		{
			if(j%2)
				putchar(namec[pc++]);
			else
				putchar(namev[pv++]);
		}
		putchar(10);
	}
	return 0;
}