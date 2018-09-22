#include<stdio.h>
#include<string.h>
#define M 300
#define N 80
int main()
{
	int n;
	while(scanf("%d", &n), n)
	{
		int len1[10], len2[10];
		char find[10][N], replace[10][N], edit[M];
		getchar();
		for(int i = 0; i < n; i++)
		{
			gets(find[i]);
			gets(replace[i]);
			len1[i] = strlen(find[i]);
			len2[i] = strlen(replace[i]);
		}
		gets(edit);
		for(int i = 0; i < n; i++)
		{
			char *temp;
			while((temp = strstr(edit, find[i])))
			{
				int l = strlen(edit);
				if(len1[i]<len2[i])
				{
					for(int j = l-len1[i]+len2[i]; j >temp-edit+len1[i]; j--)
						edit[j] = edit[j-len2[i]+len1[i]];
					int j = 0;
					while(replace[i][j] != '\0')
						*temp++ = replace[i][j++];
				}
				else
				{
					int j = 0;
					while(replace[i][j] != '\0')
						*temp++ = replace[i][j++];
					while(*(temp+len1[i]-len2[i]-1) != '\0')
					{
						*temp = *(temp+len1[i]-len2[i]);
						temp++;
					}
				}
			}
		}
		puts(edit);
	}
	return 0;
}