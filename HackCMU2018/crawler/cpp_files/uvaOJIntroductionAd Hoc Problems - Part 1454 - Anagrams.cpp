#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
using namespace std;
const int MAXN = 100 + 10;
char word[MAXN][21], done[MAXN][21];

int cmp_char(const void *_a, const void *_b)
{
	char *a = (char*)_a;
	char *b = (char*)_b;
	return *a - *b;
}

int cmp_word(const void *_a, const void *_b)
{
	char *a = (char*)_a;
	char *b = (char*)_b;
	return strcmp(a, b);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif

	int kase;
	scanf("%d\n", &kase);
	while (kase--)
	{
		int x = 0;
		while (true)
		{
			int y = 0;
			while ((word[x][y] = getchar()) != '\n' && word[x][y] != EOF)
					y++;
			word[x][y] = '\0';
			if (word[x][0] == '\0')
				break;
			x++;
		}
		qsort(word, x, sizeof(word[0]), cmp_word);
		for (int i = 0; i < x; i++)
		{
			int j = 0, k = 0, len = strlen(word[i]);
			while (k <= len)
			  if (isspace(word[i][k++]))
				done[i][j++] = word[i][k-1];
			done[i][j] = '\0';
			qsort(done[i], strlen(done[i]), sizeof(char), cmp_char);
		}
		for(int i = 0; i < x; i++)
			for (int j = i+1; j < x; j++)
				if (!strcmp(done[i], done[j]))
					printf("%s = %s\n", word[i], word[j]);
		if (kase)
			putchar(10);
	}
	return 0;
}
