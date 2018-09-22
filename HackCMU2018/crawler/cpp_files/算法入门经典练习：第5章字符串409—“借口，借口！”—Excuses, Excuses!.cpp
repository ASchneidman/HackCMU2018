#include<stdio.h>
#include<string.h>
#include<ctype.h>

inline char* strlwr( char* str )
{ 
	char* orig = str; 
	for ( ; *str != '\0'; str++ ) 
		*str = tolower(*str); 
	return orig; 
}

int main()
{
	//freopen("data.in", "r", stdin);
	int m, n, num = 0;
	while(scanf("%d%d", &m, &n) == 2)
	{
		printf("Excuse Set #%d\n", ++num);
		char keyword[30][30];
		for(int i = 0; i < m; i++)
			scanf("%s", keyword[i]);
		getchar();
		char excuse[30][80];
		int count[30] = {0}, max = 0;
		for(int i = 0; i < n; i++)
		{
			fgets(excuse[i], 80, stdin);
			char temp[80], ch[80];
			int len = strlen(strcpy(temp, excuse[i]));
			strlwr(temp);
			int j = 0, num = 0;
			while(num < len)
			{
				if(isalpha(temp[num]))
					ch[j++] = temp[num];
				else
				{
					ch[j] = '\0';
					j = 0;
					int t = strlen(ch);
					if(t)
					{
						for(int k = 0; k < m; k++)
							if(!strcmp(ch, keyword[k]))
							{
								count[i]++;
								break;
							}
					}
				}
				num++;
			}
		}
		for(int i = 0; i < n; i++)
			if(count[i] > max)
				max = count[i];
		for(int i = 0; i < n; i++)
			if(count[i] == max)
				printf("%s", excuse[i]);
		printf("\n");
	}
	return 0;
}