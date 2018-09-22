#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
vector<int> adj[3003];
bool visited[3003];
int parent[3003];
int depth[3003];
int dfsdepth[3003];
bool cutPoint[3003];
int depthCount=0;
void dfs(int n)
{
    visited[n]=true;
    int child=0;
    depth[n]=dfsdepth[n]=(++depthCount);
    for(int i=0;i<adj[n].size();++i)
    {
        if(dfsdepth[adj[n][i]]==-1)
        {
            parent[adj[n][i]]=n;
            child++;
            dfs(adj[n][i]);

            depth[n]=min(depth[n],depth[adj[n][i]]);
            if(parent[n]==-1 and child>1 and !cutPoint[n]){
                cutPoint[n]=true;
            }
            else if(parent[n]!=-1 and depth[adj[n][i]]>=dfsdepth[n] and !cutPoint[n]){
                cutPoint[n]=true;
                //cout<<n<<" ";
            }

        }
        else if(parent[n]!=adj[n][i])
        {
            depth[n]=min(depth[n],dfsdepth[adj[n][i]]);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int n,m,k;
    while(t--)
    {
        for(int i=0;i<3003;++i)
            adj[i].clear();
        fill(visited,visited+3003,false);
        fill(depth,depth+3003,-1);
        fill(parent,parent+3003,-1);
        fill(dfsdepth,dfsdepth+3003,-1);
        fill(cutPoint,cutPoint+3003,false);
        cin>>n>>m>>k;
        int a,b;
        for(int i=0;i<m;++i)
        {
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        depthCount=0;
        dfs(0);
        cout<<count(cutPoint,cutPoint+3003,true)*k<<endl;

    }

    return 0;
}
