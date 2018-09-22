#include<bits/stdc++.h>
using namespace std;
long long tree[400012];
bool lazy[400012];
void create()
{
    for(long long i=0;i<400012;++i)
    {
        tree[i]=0;
        lazy[i]=false;
    }
}
void update(long long ss,long long se,long long node,long long start,long long end)
{
    if(lazy[node])
    {
        lazy[node]=!lazy[node];
        tree[node]=se-ss+1-tree[node];
        if(ss<se)
        {
            lazy[2*node]=!lazy[2*node];
            lazy[2*node+1]=!lazy[2*node+1];
        }

    }
    if(ss>se or ss>end or se<start)
        return ;
    if(ss>=start and se<=end)
    {
        tree[node]=se-ss+1-tree[node];
        if(ss<se)
        {
            lazy[2*node]=!lazy[2*node];
            lazy[2*node+1]=!lazy[2*node+1];

        }
        return ;
    }
    update(ss,(ss+se)/2,2*node,start,end);
    update((ss+se)/2+1,se,2*node+1,start,end);
    if(ss<se)
        tree[node]=tree[2*node]+tree[2*node+1];
}
long long querry(long long ss,long long se,long long node,long long start,long long end)
{
    if(ss>end or se<start)
        return 0;
    if(lazy[node])
    {
        lazy[node]=!lazy[node];
        tree[node]=se-ss+1-tree[node];
        if(ss<se)
        {
            lazy[2*node]=!lazy[2*node];
            lazy[2*node+1]=!lazy[2*node+1];
        }

    }
    if(ss>=start and se<=end)
        return tree[node];
    long long a=querry(ss,(ss+se)/2,2*node,start,end);
    long long b=querry((ss+se)/2+1,se,2*node+1,start,end);
    return a+b;
}
int main()
{
    long long n,m;
    scanf("%lld %lld",&n,&m);
    int ch;
    long long start,end;
    create();
    while(m--)
    {
        scanf("%d %lld %lld",&ch,&start,&end);
        if(ch==0)
            update(1,n,1,start,end);
        else
        {
            long long ans=querry(1,n,1,start,end);
            printf("%lld\n",ans);
        }
    }


}
