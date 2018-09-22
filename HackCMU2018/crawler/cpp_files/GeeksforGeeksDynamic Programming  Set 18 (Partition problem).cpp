<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
int a[102];
bool dp[100005][102];
int totalSum,n;
bool solve(int sum)
{
    memset(dp,false,sizeof dp);
    for(int i=0;i<=n;++i)
        dp[0][i]=true;
    for(int i=1;i<=sum;++i)
        dp[i][0]=false;
    for(int i=1;i<=sum;++i)
        for(int j=1;j<=n;++j)
            if(i-a[j]>=0)
                dp[i][j]=dp[i][j-1] or dp[i-a[j]][j-1];
            else
                dp[i][j]=dp[i][j-1];
    return dp[sum][n];
}
int main()
{
    int t;

    scanf(" %d",&t);
    while(t--)
    {
        totalSum=0;
        scanf(" %d",&n);
        for(int i=1;i<=n;++i){
            scanf(" %d",&a[i]);
            totalSum+=a[i];
        }
        if(totalSum%2==1)
            printf("NO\n");
        else
        {
            if(solve(totalSum/2))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }

	return 0;
}
=======
#include <bits/stdc++.h>
using namespace std;
int a[102];
bool dp[100005][102];
int totalSum,n;
bool solve(int sum)
{
    memset(dp,false,sizeof dp);
    for(int i=0;i<=n;++i)
        dp[0][i]=true;
    for(int i=1;i<=sum;++i)
        dp[i][0]=false;
    for(int i=1;i<=sum;++i)
        for(int j=1;j<=n;++j)
            if(i-a[j]>=0)
                dp[i][j]=dp[i][j-1] or dp[i-a[j]][j-1];
            else
                dp[i][j]=dp[i][j-1];
    return dp[sum][n];
}
int main()
{
    int t;

    scanf(" %d",&t);
    while(t--)
    {
        totalSum=0;
        scanf(" %d",&n);
        for(int i=1;i<=n;++i){
            scanf(" %d",&a[i]);
            totalSum+=a[i];
        }
        if(totalSum%2==1)
            printf("NO\n");
        else
        {
            if(solve(totalSum/2))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }

	return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
