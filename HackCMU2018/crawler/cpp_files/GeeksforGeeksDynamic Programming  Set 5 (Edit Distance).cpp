<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

int dp[102][102];
string a,b;
int solve(int i,int j)
{
    if(i==0)
        return j;
    if(j==0)
        return i;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(a[i-1]==b[j-1])
        dp[i][j]=solve(i-1,j-1);
    else
        dp[i][j]=1+min(solve(i-1,j),min(solve(i,j-1),solve(i-1,j-1)));
    return dp[i][j];
}
int main()
{
    int t;
    int p,q;
    scanf(" %d",&t);
    while(t--)
    {
        scanf(" %d %d",&p,&q);
        memset(dp,-1,sizeof dp);
        cin>>a>>b;
        printf("%d\n",solve(p,q));



    }

	return 0;
}
=======
#include <bits/stdc++.h>
using namespace std;

int dp[102][102];
string a,b;
int solve(int i,int j)
{
    if(i==0)
        return j;
    if(j==0)
        return i;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(a[i-1]==b[j-1])
        dp[i][j]=solve(i-1,j-1);
    else
        dp[i][j]=1+min(solve(i-1,j),min(solve(i,j-1),solve(i-1,j-1)));
    return dp[i][j];
}
int main()
{
    int t;
    int p,q;
    scanf(" %d",&t);
    while(t--)
    {
        scanf(" %d %d",&p,&q);
        memset(dp,-1,sizeof dp);
        cin>>a>>b;
        printf("%d\n",solve(p,q));



    }

	return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
