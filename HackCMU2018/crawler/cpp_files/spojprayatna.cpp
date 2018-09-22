#include<bits/stdc++.h>
using namespace std;
bool visited[100005];
vector<long long> v[100005];
void bfs(int i)
{
	queue <int> q;
	q.push(i);
	visited[i]=1;
	while(!q.empty())
	{
		int k=q.front();
		q.pop();
		for(int j=0;j<v[k].size();j++)
		{
			if(!visited[v[k][j]])
			{
				q.push(v[k][j]);
				visited[v[k][j]]=1;
			}
		}
	}
}

int main()
{
    long long t;
    scanf("%lld",&t);
    while(t--)
    {
        long long n,e,a,b,cnt=0;
        scanf("%lld %lld",&n,&e);
        for(long long i=0;i<n;++i)
        {
            v[i].clear();
            visited[i]=false;
        }
        for(long long i=0;i<e;++i)
        {
            scanf("%lld %lld",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for(int i=0;i<n;++i)
            if(!visited[i])
        {
            cnt++;
            bfs(i);
        }
        printf("%lld\n",cnt);


    }
    return 0;
}
