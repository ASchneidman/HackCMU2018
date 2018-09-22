#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int t,n,i,j,s[100005],sum,a,b,sum1,w,f=0;
	scanf("%d",&t);
	while(t--)
	{
		sum1=sum=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&s[i]);
		for(i=1;i<=n;i++)
			if(s[i]>=0)
			{
				a=i;
				break;
			}
			if(i>n)
			{
				w=0;
				a=b=1;
				sum=s[1];
				for(i=2;i<=n;i++)
					if(sum<s[i])
					{
						j=i;
						sum=s[i];
						w=1;
					}
					if(w==1)
						a=b=j;
					printf("Case %d:\n",++f);
					printf("%d %d %d\n",sum,a,b);
					if(t!=0)
						printf("\n");
			}
			else
			{

				while(s[i]>=0&&i<=n)
				{
					sum+=s[i];
					i++;
				}
				b=i-1;
				sum1=sum;
				w=0;
				while(i<=n)
				{
					while(s[i]<0&&i<=n)
					{
						sum1+=s[i];
						i++;
					}
					if(sum1<0)
					{
						sum1=0;
						j=i;
						w=1;
					}
					while(s[i]>=0&&i<=n)
					{
						sum1+=s[i];
						i++;
					}
					if(w==0&&sum1>sum)
					{
						sum=sum1;
						b=i-1;
					}
					if(w==1&&sum1>sum)
					{
						sum=sum1;
						a=j;
						b=i-1;
						w=0;
					}
				}
				printf("Case %d:\n",++f);
				printf("%d %d %d\n",sum,a,b);
				if(t!=0)
					printf("\n");
			}
	}
	return 0;
}