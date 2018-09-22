#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long a[100005],power[100005];
void poww()
{
    power[0]=1;
    int i=0;
    while(i<=100009)
    {
        power[i+1]=(power[i]*2)%mod;
        i++;
    }
}

int main()
{
    int t;
    long long n;
    scanf("%d",&t);
    poww();
    while(t--)
    {
        scanf("%lld",&n);
        for(long long i=0;i<n+1;++i)
            scanf("%lld",&a[i]);
        long long add,ans=0,x;
        if(n==1)
        {
            printf("%lld\n",(2*a[0]*a[1])%mod);
            continue;
        }
        add=power[n-1]*a[n]%mod;
        x=power[n-1];
        for(int i=n-1;i>=0;--i)
        {
            ans+=(a[i]*add);
            if(i==1)
                add+=(x*2)*a[i];
            else
                add=((add*500000004)%mod+(x*a[i])%mod)%mod;

            if(add>=mod)
                add=add%mod;
            if(ans>=mod)
                ans=ans%mod;
        }
        printf("%lld\n",ans%mod);
    }
    return 0;
}
