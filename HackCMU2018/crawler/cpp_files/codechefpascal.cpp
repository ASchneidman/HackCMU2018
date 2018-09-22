#include<stdio.h>
unsigned int comb(unsigned int n,unsigned int r)
{
	if(r==0)
		return 1;
	return n*comb(n-1,r-1)/r;

}


int main()
{
	unsigned int N,t,sum,i,k,a[100000],len;
	char ch[100005];
	scanf(" %u %u",&N,&t);
	while(t--)
	{

		scanf(" %[^\n]s",ch);
		len=0;
		for(i=0,k=0;ch[i]!='\0';++i,len++)
		{
			if(i==0)
			{
				a[k]=ch[i]-48;
				continue;
			}
			if(ch[i]==' ')
            {
                k++;
                a[k]=0;
            }
            else
                a[k]=a[k]*10+(ch[i]-48);
		}
		if(a[0]>N)
		{
			printf("-1 ");
			continue;
		}
		sum=0;
		i=1;
		int flag=1;
		while(i<=k)
			{
			    if(a[i]>a[0])
                {
                    printf("-1 ");
                    flag=0;
                    break;
                }
			    sum+=comb(a[0],a[i]);
                i++;
			}
        if(flag)
            if(ch[len]==' ')
            printf("%u ",sum-1);
            else
                printf("%u ",sum);
	}
	return 0;
}



