#include<bits/stdc++.h>
using namespace std;

char ch[60][60];
int a[60][60],n,m;
bool vis[60][60];
int dp[60][60],ans;
void bfs(int i,int j,int d)
{
    if(i<0 or i>=n or j<0 or j>=m)
        return;
    if(ch[i][j]=='*')
        return;
     if(ch[i][j]=='.')
     {
         bfs(i+1,j,d+1);
         bfs(i,j+1,d+1);
         bfs(i-1,j,d+1);
         bfs(i,j-1,d+1);
     }
     if(ch[i][j]=='E')
     {
            ans=min(ans,d);
            return;
     }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    scanf("%d",&t);
    while(t--)
        {
            ans=INT_MAX;
        scanf("%d %d",&n,&m);
        int x=0,ui,uj;
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j){
                dp[i][j]=-1;
                scanf(" %c",&ch[i][j]);
                if(ch[i][j]=='U')
                {
                    ui=i;
                    uj=j;
                    a[i][j]=0;
                }
                else if(ch[i][j]=='.')
                    a[i][j]=1;
                else if(ch[i][j]=='*')
                    a[i][j]=INT_MAX;
                else
                    a[i][j]=-1;
            }

        bfs(ui,uj,0);
        printf("%d\n",ans);
    }
    return 0;
}
