#include<bits/stdc++.h>
#define gc getchar_unlocked
#define pc(x) putchar_unlocked(x);
    void writeint (long long n)
    {
        long long N = n, rev, count = 0;
        rev = N;
        if (N == 0) { pc('0'); pc('\n'); return ;}
        while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
        rev = 0;
        while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
        while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
        while (count--) pc('0');
    }
using namespace std;
long long a[100003]={},tree[400003][4]={},ans;
void scanint(long long &x)
{
    register long long c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
void create(long long ss,long long se,long long node)
{
    if(ss==se)
    {
        tree[node][0]=1;
        tree[node][1]=tree[node][2]=0;
    }
    else{
    create(ss,(ss+se)/2,2*node);
    create((ss+se)/2+1,se,2*node+1);
    tree[node][0]=tree[2*node][0]+tree[2*node+1][0];
    tree[node][1]=tree[2*node][1]+tree[2*node+1][1];
    tree[node][2]=tree[2*node][2]+tree[2*node+1][2];
    }
}
void querry(long long ss,long long se, long long node, long long i, long long j)
{
    if(tree[node][3]!=0)
    {
        long long ch=tree[node][3];
        if(ch%3==0);
        else if(ch%3==1)
        {
            long long temp=tree[node][0];
            tree[node][0]=tree[node][2];
            tree[node][2]=tree[node][1];
            tree[node][1]=temp;
        }
        else
        {
            long long temp=tree[node][0];
            tree[node][0]=tree[node][1];
            tree[node][1]=tree[node][2];
            tree[node][2]=temp;
        }
        if(ss!=se)
		{
			tree[2*node][3]+=tree[node][3];
			tree[2*node+1][3]+=tree[node][3];
		}
        tree[node][3]=0;
    }
    if(ss>j or se<i)
        return ;
    if(ss>=i and se<=j)
        ans+=tree[node][0];
    else{
    querry(ss,(ss+se)/2,2*node,i,j);
    querry((ss+se)/2+1,se,2*node+1,i,j);
    }

}
void update(long long ss,long se,long long node,long long start,long long end)
{

    if(tree[node][3]!=0)
    {
        long long ch=tree[node][3];
        if(ch%3==0);
        else if(ch%3==1)
        {
            long long temp=tree[node][0];
            tree[node][0]=tree[node][2];
            tree[node][2]=tree[node][1];
            tree[node][1]=temp;
        }
        else
        {
            long long temp=tree[node][0];
            tree[node][0]=tree[node][1];
            tree[node][1]=tree[node][2];
            tree[node][2]=temp;
        }
        if(ss!=se)
		{
			tree[2*node][3]+=tree[node][3];
			tree[2*node+1][3]+=tree[node][3];
		}
        tree[node][3]=0;
    }
    if(ss>end or se<start)
        return;
    if(ss>=start and se<=end)
        {
        int temp=tree[node][1];
		tree[node][1]=tree[node][0];
		tree[node][0]=tree[node][2];
		tree[node][2]=temp;
            if(ss!=se)
            {
                tree[2*node][3]++;
                tree[2*node+1][3]++;
            }
        }
    else
    {
    update(ss,(ss+se)/2,2*node,start,end);
    update((ss+se)/2+1,se,2*node+1,start,end);
    tree[node][0]=tree[2*node][0]+tree[2*node+1][0];
    tree[node][1]=tree[2*node][1]+tree[2*node+1][1];
    tree[node][2]=tree[2*node][2]+tree[2*node+1][2];

    }
}

int main()
{

        long long n;
     //   scanf("%lld",&n);
      scanint(n);
        long long q,a,b,c,d;
   //     scanf("%lld",&q);
        scanint(q);
        create(1,n,1);
        while(q--)
        {
            int ch;
            scanf("%d",&ch);
            if(ch==1)
            {
                ans=0;
        //        scanf("%lld %lld",&a,&b);
                scanint(a);
                scanint(b);
                querry(1,n,1,a+1,b+1);
                //printf("%lld\n",ans);
                writeint(ans);
                printf("\n");
            }
            else
            {
                //scanf("%lld %lld",&a,&b);
                scanint(a);
                scanint(b);
                update(1,n,1,a+1,b+1);
            }
            //for(long long i=1;i<=8;++i)
              //  cout<<tree[i][0]<<" "<<tree[i][1]<<" "<<tree[i][2]<<endl;
        }

    return 0;
}
