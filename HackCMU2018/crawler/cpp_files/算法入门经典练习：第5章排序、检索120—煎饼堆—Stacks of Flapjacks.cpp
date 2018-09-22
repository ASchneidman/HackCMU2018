#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int cmp(const void *_a, const void *_b)
{
	int *a = (int*)_a;
	int *b = (int*)_b;
	return *a - *b;
}

void reserve(int *pan, int n)
{
	for(int i = 0; i < n/2; i++)
	{
		int temp = pan[i];
		pan[i] = pan[n-i-1];
		pan[n-i-1] = temp;
	}
	return;
}

int main()
{
	char s[100];
	while(gets(s) != NULL)
	{
		puts(s);
		int pan[30] = {0}, sub = 0, done[30] = {0};
		for(int i = 0; s[i] != '\0'; i++)
		{
			if(isdigit(s[i]))
				pan[sub] = pan[sub]*10 + s[i] - '0';
			else 
				sub++;
		}
		memcpy(done, pan, sizeof(done));
		qsort(done, sub+1, sizeof(int), cmp);
		for(int i = sub; i >= 0; i--)
		{
			if(memcmp(pan, done, sizeof(pan)))
			{
				if(pan[i] == done[i])
					continue;
				else if(pan[0] == done[i])
				{
					reserve(pan, i+1);
					printf("%d ", sub +1 - i);
				}
				else
				{
					for(int j = 1; j < i; j++)
					{
						if(pan[j] == done[i])
						{
							reserve(pan, j+1);
							printf("%d ", sub +1 - j);
							reserve(pan, i+1);
							printf("%d ", sub +1 - i);
							break;
						}
					}
				}
			}
			else
			{
				printf("0\n");
				break;
			}
		}
	}
	return 0;
}