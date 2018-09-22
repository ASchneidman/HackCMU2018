#include<bits/stdc++.h>
#define mod 1000000007
#define maxi 10000005
using namespace std;
long long nw;
long long bit[maxi];
long long query(long long idx)
{
    long long sum=0;
    while(idx>0)
    {

        sum+=bit[idx];
        idx-=(idx&-idx);
    }
    return sum;
}
void update(long long idx,long long val)
{
    while(idx<=nw)
    {
        bit[idx]+=val;
        idx+=(idx&-idx);

    }
}
long long v[maxi];
int main()
{
    long long t;
    scanf("%lld",&t);
    while(t--)
    {

        long long inv=0,n;
        fill(v,v+maxi,0);
        fill(bit,bit+maxi,0);
        scanf("%lld",&n);
        nw=0;
        for(long long i=0;i<n;++i)
        {
            scanf("%lld",&v[i]);
            nw=max(v[i],nw);
        }
        for(long long i=n-1;i>=0;--i)
        {
            inv+=query(v[i]-1);
            update(v[i],1);
        }
        printf("%lld\n",inv);

        //cout<<a<<endl<<b;

    }

    return 0;

}
