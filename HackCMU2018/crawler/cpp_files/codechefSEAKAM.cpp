#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long a[100005],fact[100005];
long long root(long long i)
{
    while(a[i]!=i)
    {
        a[i]=a[a[i]];
        i=a[i];
    }
    return i;
}
void factc(long long n)
{
    fact[1]=1;
    for(long long i=2;i<=n;++i)
    {
        fact[i]=fact[i-1]*i;
        if(fact[i]>=mod)
            fact[i]=fact[i]%mod;
    }
}
vector<pair<long long,long long> > v;
long long has[100005],dishas[100005];
int main()
{
    long long t,n,m;
    scanf("%lld",&t);
    factc(100003);
    while(t--)
    {
        scanf("%lld %lld",&n,&m);
        long long ans=0;
        long long x,y;
        v.clear();
        for(long long i=0;i<m;++i)
        {
            scanf("%lld %lld",&x,&y);
            v.push_back(make_pair(x,y));
        }
        long long c=(1<<m),dis,num=0,p=0,l,r,rl,rr;
        bool flag;
        for(long long x=0;x<c;++x)
        {
            for(long long i=1;i<=n;++i)
                a[i]=i;
            dis=0;
            num=0;
            p=0;
            fill(has,has+n+1,0);
            flag=false;
            for(long long j=0;j<m;++j)
            {
                if(x & (1<<j))
                {
                    num++;
                    l=v[j].first;
                    r=v[j].second;
                    if(has[l]==0)
                        p++;
                    if(has[r]==0)
                        p++;

                    has[l]++;
                    has[r]++;
                    rl=root(l);
                    rr=root(r);
                    if(rl==rr)
                    {
                        flag=true;
                        break;
                    }
                    if(has[l]>=3 or has[r]>=3)
                    {
                        flag=true;
                        break;
                    }
                    a[rl]=rr;
                }
            }
            if(flag)
                continue;
            for(long long i=1;i<=n;++i)
                if(a[i]==i and has[i]!=0)
                    dis++;

            if(dis==n)
                dis=0;

            if(num%2)
                ans=(ans-((1<<dis)*fact[n-p+dis])%mod+mod)%mod;
            else
                ans+=((1<<dis)*fact[n-p+dis]);

            if(ans>=mod)
                ans=ans%mod;

        }
        printf("%lld\n",ans);
    }
    return 0;
}
