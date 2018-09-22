#include<bits/stdc++.h>
using namespace std;
vector<int> List[10003];
int dist[10003];
bool visited[10003];
void bfs(int i)
{
	queue <int> q;
	q.push(i);
	visited[i]=1;
	dist[i]=0;
	while(!q.empty())
	{
		int k=q.front();
		q.pop();
		for(int j=0;j<List[k].size();j++)
		{
			if(visited[List[k][j]]==0)
			{
				q.push(List[k][j]);
				visited[List[k][j]]=1;
				dist[List[k][j]]=dist[k]+1;
			}
		}
	}
}



int main(){
    int n,u,v;
    scanf("%d",&n);
    for(int i=0;i<n-1;++i)
    {
        scanf("%d %d",&u,&v);
        List[u].push_back(v);
        List[v].push_back(u);
    }
    bfs(1);
    int el,maxi=-1;
    for(int i=1;i<=n;++i){
        visited[i]=false;
        if(dist[i]>maxi)
        {
            maxi=dist[i];
            el=i;
        }
        dist[i]=0;
    }
   // cout<<el<<" "<<maxi<<endl;
    bfs(el);
    cout<<*max_element(dist,dist+n+1);

	return 0;
}
