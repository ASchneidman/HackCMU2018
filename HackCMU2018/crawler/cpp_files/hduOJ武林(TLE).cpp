#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<iomanip>
#include<time.h>
#include<string.h>
#include<string>
using namespace std;


struct node
{
	int x,y,nei,num,wu,sheng,flag,xiang;
	char mp;
}s[1001];

int map[13][13];


int main()
{
	int cas,n,i,j,k;
	struct node a,b;
	char mp;
	cin>>cas;
	while(cas--)
	{
		memset(map,0,sizeof(map));
		cin>>n;
		if(n==0)
			n=1;
		getchar();
		 i=0;
		while(scanf("%c",&mp),mp!='0')
		{
			s[i].mp=mp;
			scanf("%d%d%d%d%d",&s[i].x,&s[i].y,&s[i].nei,&s[i].wu,&s[i].sheng);
			s[i].flag=1;
			s[i].xiang=0;
			map[s[i].x][s[i].y]++;
			getchar();
			i++;
		}
		int t=i,a1,a2;
		for(i=1;i<=12;i++)
			for(j=1;j<=12;j++)
			{
				if(map[i][j]==2)
				{
					for(k=0;k<t;k++)
						if(s[k].x==i&&s[k].y==j)
						{
							a=s[k];
							a1=k;
							break;
						} 
					for(;k<t;k++)
						if(s[k].x==i&&s[k].y==j)
						{
							b=s[k];
							a2=k;
							break;
						}
					if(a.mp!=b.mp)
					{
						double g1,g2;
						if(a.mp=='S')
							g1=(0.5*a.nei+0.5*a.wu)*(a.sheng+10)/100.0;
						if(a.mp=='W')
							g1=(0.8*a.nei+0.2*a.wu)*(a.sheng+10)/100.0;
						if(a.mp=='E')
							g1=(0.2*a.nei+0.8*a.wu)*(a.sheng+10)/100.0;
						if(b.mp=='S')
							g2=(0.5*b.nei+0.5*b.wu)*(b.sheng+10)/100.0;
						if(b.mp=='W')
							g2=(0.8*b.nei+0.2*b.wu)*(b.sheng+10)/100.0;
						if(b.mp=='E')
							g2=(0.2*b.nei+0.8*b.wu)*(b.sheng+10)/100.0;
						a.sheng-=(int)g2;
						b.sheng-=(int)g1;
						if(a.sheng<=0)
							a.flag=0;
						if(b.sheng<=0)
							b.flag=0;
						s[a1]=a;
						s[a2]=b;
					}
				}
			}
			n--;
		while(n--)
		{
			for(i=0;i<t;i++)
			{
				if(s[i].flag!=0)
				{
					if(s[i].mp=='S')
					{
						if(s[i].xiang==0)
						{
							if(s[i].x==12)
							{
								s[i].x=11;
								s[i].xiang=1;
							}
							else
								s[i].x++;
						}
						else
						{
							if(s[i].x==1)
							{
								s[i].x=2;
								s[i].xiang=0;
							}
							else
								s[i].x--;
						}

					}
					if(s[i].mp=='W')
					{
						if(s[i].xiang==0)
						{
							if(s[i].y==12)
							{
								s[i].y=11;
								s[i].xiang=1;
							}
							else
								s[i].y++;
						}
						else
						{
							if(s[i].y==1)
							{
								s[i].y=2;
								s[i].xiang=0;
							}
							else
								s[i].y--;
						}

					}
					if(s[i].mp=='E')
					{
						if((s[i].x==1&&s[i].y==12)||(s[i].x==12&&s[i].y==1))
						{
							continue;
						}
						if(s[i].xiang==0)
						{
							if(s[i].x==12)
							{
								s[i].x=11;
								s[i].xiang=1;
								s[i].y--;
							}
							else
							{
								if(s[i].y==12)
								{
									s[i].xiang=1;
									s[i].y=11;
									s[i].x--;
								}
								else
								s[i].x++,s[i].y++;
							}
						}
						else
						{
							if(s[i].x==1)
							{
								s[i].x=2;
								s[i].xiang=0;
								s[i].y++;
							}
							else
							{
								if(s[i].y==1)
								{
									s[i].xiang=0;
									s[i].y=2;
									s[i].x++;
								}
								else
								s[i].x--,s[i].y--;
							}
						}

					}
				}
			}
			memset(map,0,sizeof(map));
			for(i=0;i<t;i++)
			{
				if(s[i].flag!=0)
				map[s[i].x][s[i].y]++;
			}
			for(i=1;i<=12;i++)
			for(j=1;j<=12;j++)
			{
				if(map[i][j]==2)
				{
					int p;
					for(k=0;k<t;k++)
						if(s[k].x==i&&s[k].y==j)
						{
							a=s[k];
							a1=k;
						
							break;
						}

			for(k=t-1;k>=0;k--)
					if(s[k].x==i&&s[k].y==j)
						{
							b=s[k];
							a2=k;
							break;
						}
					if(a.mp!=b.mp)
					{
						double g1,g2;
						if(a.mp=='S')
							g1=(0.5*a.nei+0.5*a.wu)*(a.sheng+10)/100.0;
						if(a.mp=='W')
							g1=(0.8*a.nei+0.2*a.wu)*(a.sheng+10)/100.0;
						if(a.mp=='E')
							g1=(0.2*a.nei+0.8*a.wu)*(a.sheng+10)/100.0;
						if(b.mp=='S')
							g2=(0.5*b.nei+0.5*b.wu)*(b.sheng+10)/100.0;
						if(b.mp=='W')
							g2=(0.8*b.nei+0.2*b.wu)*(b.sheng+10)/100.0;
						if(b.mp=='E')
							g2=(0.2*b.nei+0.8*b.wu)*(b.sheng+10)/100.0;
						a.sheng-=(int)g2;
						b.sheng-=(int)g1;
						if(a.sheng<=0)
							a.flag=0;
						if(b.sheng<=0)
							b.flag=0;
						s[a1]=a;
						s[a2]=b;
					}
				}
			}
			
		}
		int sd,ss,wd,ws,ed,es;
		sd=ss=wd=ws=es=ed=0;
		for(i=0;i<t;i++)
		{
			if(s[i].flag!=0)
			{
				if(s[i].mp=='S')
				{sd++;ss+=s[i].sheng;}
					if(s[i].mp=='W')
				{wd++;ws+=s[i].sheng;}
						if(s[i].mp=='E')
				{ed++;es+=s[i].sheng;}
			}
		}
		printf("%d %d\n",sd,ss);
			printf("%d %d\n",wd,ws);
				printf("%d %d\n",ed,es);
				puts("***");
	}
	return 0;
}

