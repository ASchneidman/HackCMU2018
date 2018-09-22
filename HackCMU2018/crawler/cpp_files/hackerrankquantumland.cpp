#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define l long

#define MAX 100003
#define MOD 1000000007

#define fin(i,a,n) for(i=a;i<=n;i++)
#define fde(i,a,n) for(i=n;i>=a;i--)

#define sd(a) scanf("%d",&a)
#define sld(a) scanf("%ld",&a)
#define slld(a) scanf("%lld",&a)
#define slf(a) scanf("%lf",&a)
#define sllf(a) scanf("%llf",&a)

#define pd(a) printf("%d",a)
#define pld(a) printf("%ld",a)
#define plld(a) printf("%lld",a)
#define plf(a) printf("%lf",a)
#define pllf(a) printf("%llf",a)
#define pn printf("\n")
#define ps printf(" ")

#define mp make_pair
#define pb push_back

pair<int,int> adjList[100005];
bool visited[100005];
int loop[100005];
double ans = 0;
double cur[100005];
int dfs(int i,double curr)
{
    if(visited[i])
    {
    	if(loop[i]==1)
    	{
    		//pd(i);
    		//printf("f");
    		//pn;
    		return 1;
    	}
    	else if(loop[i]==0)
    	{
    		//printf("here2");
    		//pd(i);
    		//pn;
    		ans += curr/cur[i];
    		//printf("%d %.2lf\n",i,ans);
    		return 1;
    	}
    	else
    	{
    		return 2;
    	}
    }

    visited[i] = true;
    cur[i] = curr;
    int k;

    if(adjList[i].second == -1)
    	{
    		return 2;
    	}

    curr = (curr * adjList[i].second)/100.0;
    int a = dfs(adjList[i].first,curr);
    loop[adjList[i].first] = a;
    return a;
}

int main()
{
        memset(visited,false,sizeof(visited));
        memset(loop,0,sizeof(loop));
        int n,i,m,q;
        sd(n);
        fin(i,1,n)
        {
            sd(m);
            sd(q);
            if(q==0)
            	adjList[i] = mp(-1,-1);
            else
            	adjList[i] = mp(m,q);
        }

        fin(i,1,n)
        {
            if(!visited[i])
            {
               	int a = dfs(i,1.0);
               	loop[i] = a;
               	/*fin(j,1,n)
               	{
               		pd(j);
               		ps;
               		pd(loop[j]);
               		pn;
               	}*/
            }
    	}
    	ans=floor(ans*100+0.5)/100.0;
    	printf("%.2lf",ans);
    return 0;
}
