#include<bits/stdc++.h>
using namespace std;
long long bit[200005];
long long n;

void update(long long idx,long long val)
{
    while(idx<=n)
    {
        bit[idx]+=val;
        idx+=(idx&-idx);
    }
}
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
long long check(long long num)
{
    if(num<0)
        return 0;
    if(num<10)
        return 1;
    long long fi,la;
    fi=num%10;
    while(num>0)
    {
        la=num%10;
        num=num/10;
    }
    if(fi==la)
        return 1;
    else
        return 0;
}
long long a[200005];
int main()
{
    long long q,fi,la,rem;
    scanf("%lld %lld",&n,&q);
    for(long long i=0;i<n;++i)
    {
            scanf("%lld",&a[i]);
            if(check(a[i]))
                update(i+1,1);
    }
    long long ch,l,r,ans;
    while(q--)
    {
        scanf("%lld %lld %lld",&ch,&l,&r);
        if(ch==1)
        {
            ans=query(r)-query(l-1);
            printf("%lld\n",ans);
        }
        else
        {
            if(check(a[l-1]))
                update(l,-1);
            a[l-1]=r;
            if(check(r))
                update(l,1);

        }
    }

    return 0;

}
