#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int convert(char a[])
{
    int ind=9,ans=0;
    for(int i=0;i<10;++i)
    {
        if(a[i]=='1')
            ans+=pow(2,ind);
        ind--;
    }
    return ans;
}
int pic,fil[1025];
int input()
{
    int n,m;
    char s[20];
    fill(fil,fil+1025,0);
    scanf(" %s",s);
    for(int i=0;i<10;++i)
        if(s[i]=='w')
            s[i]='1';
        else
            s[i]='0';
    pic=convert(s);
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf(" %s",s);
        for(int j=0;j<10;++j)
            if(s[j]=='+')
                s[j]='1';
            else
                s[j]='0';
        m=convert(s);
        fil[m]++;
    }
    return n;
}
long long dp[1025][1025];
long long powmod(int ex)
{
    long long ans=1,base=2;
    while(ex>0)
    {
        if(ex%2==1)
            ans=(ans*base)%mod;
        ex=ex>>1;
        base=(base*base)%mod;
    }
    return ans;

}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        n=input();
        long long m,z;
        dp[0][0]=powmod(fil[0])-1;
        for(int i=1;i<1024;++i)
        {
            for(int j=0;j<1024;++j)
            {
                if(fil[i]==0)
                    dp[i][j]=dp[i-1][j];
                else
                {
                    m=powmod(fil[i]-1);
                    dp[i][j]=m*dp[i-1][j]+((i==j)?m:0) + m*dp[i-1][i xor j];
                    if(j==0)
                        dp[i][j]+=(m-1);
                    if(dp[i][j]>=mod)
                        dp[i][j]=dp[i][j]% mod;
                }
            }
        }
        long long ans=dp[1023][pic];
        if(pic==0)
            ans+=1;
        printf("%lld\n",ans% mod);
    }
    return 0;
}
