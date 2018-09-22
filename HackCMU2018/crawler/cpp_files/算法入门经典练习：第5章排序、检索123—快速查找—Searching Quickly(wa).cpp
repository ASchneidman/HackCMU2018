#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char ignore[100][50], title[500][10010], keyword[1000][1000];
char temp[1000];
int kw = 0, n_i = -1, n_t = -1;

int cmp(void const* _a,void const* _b)
{
    char *a=(char *)_a;
    char *b=(char *)_b;
    return strcmp(a,b);
}

char* getword(char *s)
{
	while(!(isalpha(*s) || *s == '\0'))
		s++;
	if(*s == '\0')
		return NULL;
	int n = 0;
	while(isalpha(*s))
	{
		temp[n++] = *s;
		s++;
	}
	temp[n] = '\0';
	return s;
}

void getstr(char *s)
{
	do
	{
		s = getword(s);
		int ok = 0;
		for(int i = 0; i < n_i; i++)
			if(!strcmp(temp, ignore[i]))
			{
				ok = 1;
				break;
			}
		if(ok)
			continue;
		strcpy(keyword[kw++], temp);
	}while(s != NULL);
	return;
}

int main()
{
	while(scanf("%s", ignore[++n_i]) == 1)
		if(ignore[n_i][0] == ':')
			break;
	getchar();
	while(gets(title[++n_t]) != NULL)
		for(int i = 0; title[n_t][i] != '\0'; i++)
			title[n_t][i] = tolower(title[n_t][i]);
	for(int i = 0; i < n_t; i++)
		getstr(title[i]);
	qsort(keyword, kw, sizeof(keyword[0]), cmp);
	for(int i = 0; i < kw; i++)
	{
		if(i && !strcmp(keyword[i], keyword[i-1]))
			continue;
		for(int j = 0; j < n_t; j++)
		{
			int len = strlen(keyword[i]);
			char *s = strstr(title[j], keyword[i]);
			while(s != NULL)
			{
				if(isalpha(*(s-1)) || isalpha(s[len]))
				{
					s = strstr(s + 1, keyword[i]);
					continue;
				}
				for(char *p = title[j]; *p != '\0'; p++)
					if(p >= s && p <=s + len - 1)
						putchar(toupper(*p));
					else
						putchar(*p);
				putchar(10);
				s = strstr(s + 1, keyword[i]);
			}
		}
	}
	return 0;
}