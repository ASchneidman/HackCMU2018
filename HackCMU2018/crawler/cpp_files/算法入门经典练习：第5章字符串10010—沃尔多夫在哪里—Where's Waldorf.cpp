#include<stdio.h>
#include<string.h>
#include<ctype.h>
char grid[51][51];
int m, n;

bool find(char s[], int len, int p, int q, int x, int y)
{
	int i;
	p += x;
	q += y;
	for(i = 1; i < len; i++)
	{
		if(p < 0|| q < 0 || p > m-1
		|| q > n-1 || s[i] != grid[p][q])
			break;
		p += x;
		q += y;
	}
	if(i >= len)
		return true;
	else
		return false;
}
int main()
{
	int Case;
	scanf("%d", &Case);
	while(Case--)
	{
		scanf("%d%d", &m, &n);
		for(int i = 0; i < m; i++)
		{
			scanf("%s", grid[i]);
			int len = strlen(grid[i]);
			for(int j = 0; j < len; j++)
				grid[i][j] = tolower(grid[i][j]);
		}
		int num;
		char input[51];
		scanf("%d", &num);
		for(int i = 0; i < num; i++)
		{
			int found = 0;
			scanf("%s", input);
			int len = strlen(input);
			for(int j = 0; j < len; j++)
				input[j] = tolower(input[j]);
			for(int j = 0; j < m; j++)
			{
				for(int k = 0; k < n; k++)
				{
					if(grid[j][k] == input[0])
					{
						if(find(input, len, j, k, -1, -1) || find(input, len, j, k, -1, 0)
							|| find(input, len, j, k, -1, 1) || find(input, len, j, k, 0, -1)
							|| find(input, len, j, k, 0, 1) || find(input, len, j, k, 1, -1)
							|| find(input, len, j, k, 1, 0) || find(input, len, j, k, 1, 1))
						{
							printf("%d %d\n", j+1, k+1);
							found = 1;
							break;
						}
					}
				}
				if(found)
					break;
			}
		}
		if(Case)
			printf("\n");
	}
	return 0;
}