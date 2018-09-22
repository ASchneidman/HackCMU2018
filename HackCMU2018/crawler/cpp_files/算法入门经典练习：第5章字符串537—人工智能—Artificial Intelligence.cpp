	#include<stdio.h>
	#include<string.h>
	#define MAXN 100
	int main()
	{
		int n, m = 0;
		scanf("%d", &n);
		getchar();
		while(n--)
		{
			char s[MAXN];
			gets(s);
			char *temp1 = strchr(s, '=') + 1;
			char *temp2 = strchr(temp1, '=') + 1;
			double p_value = -1, u_value = -1, i_value = -1;
			char pre;
			if(*(temp1-2) == 'P')
			{
				sscanf(temp1,"%lf%c", &p_value, &pre);
				switch(pre)
				{
				case 'm': p_value *= 1e-3;break;
				case 'k': p_value *= 1e3;break;
				case 'M': p_value *= 1e6;break;
				}
			}
			else if(*(temp1-2) == 'U')
			{
				sscanf(temp1,"%lf%c", &u_value, &pre);
				switch(pre)
				{
				case 'm': u_value *= 1e-3;break;
				case 'k': u_value *= 1e3;break;
				case 'M': u_value *= 1e6;break;
				}
			}
			else
			{
				sscanf(temp1,"%lf%c", &i_value, &pre);
				switch(pre)
				{
				case 'm': i_value *= 1e-3;break;
				case 'k': i_value *= 1e3;break;
				case 'M': i_value *= 1e6;break;
				}
			}
			if(*(temp2-2) == 'P')
			{
				sscanf(temp2,"%lf%c", &p_value, &pre);
				switch(pre)
				{
				case 'm': p_value *= 1e-3;break;
				case 'k': p_value *= 1e3;break;
				case 'M': p_value *= 1e6;break;
				}
			}
			else if(*(temp2-2) == 'U')
			{
				sscanf(temp2,"%lf%c", &u_value, &pre);
				switch(pre)
				{
				case 'm': u_value *= 1e-3;break;
				case 'k': u_value *= 1e3;break;
				case 'M': u_value *= 1e6;break;
				}
			}
			else
			{
				sscanf(temp2,"%lf%c", &i_value, &pre);
				switch(pre)
				{
				case 'm': i_value *= 1e-3;break;
				case 'k': i_value *= 1e3;break;
				case 'M': i_value *= 1e6;break;
				}
			}
			printf("Problem #%d\n", ++m);
			if(p_value == -1)
				printf("P=%.2fW\n\n", u_value*i_value);
			else if(u_value == -1)
				printf("U=%.2fV\n\n", p_value/i_value);
			else
				printf("I=%.2fA\n\n", p_value/u_value);
		}
		return 0;
	}