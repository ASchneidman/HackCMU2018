#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
vector<int> v[200000],ag;
int dp[2015][2015];
int lcs(vector<int> a,vector<int> b)
{
    for(int i=0;i<=a.size();++i)
        for(int j=0;j<=b.size();++j)
            if(i==0 or j==0)
                dp[i][j]=0;
            else if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    return dp[a.size()][b.size()];
}
int main()
{
    int t,x,i;
    scanf("%d",&t);
    while(t--)
    {
        ag.clear();
        for(i=0;;++i)
        {
            if(i==0)
            {
                scanf(" %d",&x);
                while(x!=0)
                {
                    ag.push_back(x);
                    scanf("%d",&x);
                }
            }
            else
            {
                scanf("%d",&x);
                if(x==0)
                    break;
                v[i].clear();
                while(x!=0)
                {
                    v[i].push_back(x);
                    scanf("%d",&x);
                }
            }
        }
        int ans=0;
        for(int j=1;j<i;++j){
            ans=max(ans,lcs(ag,v[j]));
            //printf("%d\n",lcs(ag,v[j]));
        }
        printf("%d\n",ans);
    }
    return 0;
}
