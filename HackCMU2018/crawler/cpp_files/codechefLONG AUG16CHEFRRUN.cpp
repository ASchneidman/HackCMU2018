#include <bits/stdc++.h>
using namespace std;
vector<long long>circle,adj[100005];

bool visited[100005],recStack[100005];
bool duplicate[100005];
bool dfs(bool visited[],bool recStack[],long long v)
{
    //cout<<"hi";
    visited[v]=true;
    recStack[v]=true;

    //cout<<v;
    for(int i=0;i<adj[v].size();i++)
    {
        int temp=adj[v][i];
        if(recStack[temp]){

                if(!duplicate[temp]){
                duplicate[temp]=true;
                circle.push_back(temp);
                }
            return true;
        }
        if(!visited[temp]&&dfs(visited,recStack,temp))
            return true;
    }

    recStack[v]=false;
    return false;
}
long long countVertex(int start,int u)
{
    duplicate[u]=true;
    long long v=adj[u][0];
    if(start==v)
        return 1;
    if(!duplicate[v])
        return 1+countVertex(start,v);
    return LONG_LONG_MIN;
}
int main() {
	//code
	ios::sync_with_stdio(false);
	int t;
	long long a,n;
    cin>>t;
	while(t--)
	{
	    circle.clear();
	    cin>>n;
	    for(long long i=0;i<n;++i)
            adj[i].clear();
	    for(long long i=0;i<n;++i){
            cin>>a;
            adj[i].push_back((i+a+1)%n);
            visited[i]=false;
            recStack[i]=false;
            duplicate[i]=false;
	    }

        bool x;
	    for(long long i=0;i<n;++i)
        {
                if(!visited[i])
                {
                    //cout<<endl<<i<<"hello"<<endl;
                    x=dfs(visited,recStack,i);
                    //cout<<endl<<i<<"end"<<endl;
                }

	    }
        //cout<<circle.size();
	    long long ans=0;
        fill(duplicate,duplicate+n,false);
	    for(long long i=0;i<circle.size();++i)
            {

                a=countVertex(circle[i],circle[i]);
                ans=ans+((a>0)?a:0);
                //cout<<circle[i]<<" "<<ans<<endl;
            }
        cout<<ans<<endl;


	}
	return 0;
}
