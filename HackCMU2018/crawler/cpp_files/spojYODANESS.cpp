#include<bits/stdc++.h>
#define mod 1000000007
#define maxi 30003
using namespace std;
long nw;
long bit[maxi];
long query(long idx)
{
    long sum=0;
    while(idx>0)
    {

        sum+=bit[idx];
        idx-=(idx&-idx);
    }
    return sum;
}
void update(long idx,long val)
{
    while(idx<=nw)
    {
        bit[idx]+=val;
        idx+=(idx&-idx);
    }
}
long v[maxi];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {

        long rnk;
        fill(v,v+maxi,0);
        fill(bit,bit+maxi,0);
        scanf("%ld",&nw);
        string s;
        map<string,long > m,n;
        for(long i=0;i<nw;++i)
        {
            cin>>s;
            m[s]=i+1;
        }
         for(long i=0;i<nw;++i)
        {
            cin>>s;
            v[i]=m[s];
        }
        long inv=0,x;
        for(long i=nw-1;i>=0;--i)
        {
            inv+=query(v[i]-1);
            update(v[i],1);
        }
        printf("%ld\n",inv);

        //cout<<a<<endl<<b;

    }

    return 0;

}
