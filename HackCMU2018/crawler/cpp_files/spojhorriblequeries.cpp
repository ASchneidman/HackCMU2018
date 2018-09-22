#include<bits/stdc++.h>
long long a[100003],tree[400003],lazy[400003];
void lazyinit()
{
    for(long long i=0;i<400003;++i)
        lazy[i]=tree[i]=0;
}

long long querry(long long ss,long long se, long long node, long long i, long long j)
{

    if(lazy[node]!=0)
    {
        tree[node]+=(se-ss+1)*lazy[node];
        if(ss!=se){
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];}
        lazy[node]=0;
    }

    if(ss>j or se<i)
        return 0;
    if(ss>=i and se<=j)
        return tree[node];
    long long a=querry(ss,(ss+se)/2,2*node,i,j);
    long long b=querry((ss+se)/2+1,se,2*node+1,i,j);
    return a+b;
}
void update(long long ss,long se,long long node,long long start,long long end,long long v)
{

    if(lazy[node]!=0)
    {
        tree[node]+=(se-ss+1)*lazy[node];
        if(ss!=se){
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];}
        lazy[node]=0;
    }

    if(ss>end or se<start)
        return;

    if(ss>=start and se<=end)
        {
            tree[node]+=(se-ss+1)*v;
            if(ss!=se)
            {
                lazy[2*node]+=v;
                lazy[2*node+1]+=v;
            }
            return ;
        }

    update(ss,(ss+se)/2,2*node,start,end,v);
    update((ss+se)/2+1,se,2*node+1,start,end,v);
    tree[node]=tree[2*node]+tree[2*node+1];
}

int main()
{
    long long t;
    scanf("%lld",&t);
    while(t--)
    {
        long long n;
        scanf("%lld",&n);
        lazyinit();
        long long q,a,b,c,d;
        scanf("%lld",&q);
        while(q--)
        {
            int ch;
            scanf("%d",&ch);
            if(ch==1)
            {
                scanf("%lld %lld",&a,&b);
                c=querry(1,n,1,a,b);
                printf("%lld\n",c);
            }
            else
            {
                scanf("%lld %lld %lld",&a,&b,&c);
                update(1,n,1,a,b,c);
            }
        }
    }
    return 0;
}
