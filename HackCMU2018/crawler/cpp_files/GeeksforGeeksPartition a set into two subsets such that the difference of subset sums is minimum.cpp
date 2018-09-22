<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
int n;
int a[100];
bool dp[3000][55];
int sum;
int solve()
{
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
    int minDif=INT_MAX;
    for(int i=0;i<=sum/2;++i)
    if(dp[i][n]){
        minDif=min(sum-2*i,minDif);
    }
    return minDif;
}
int main()
{
    int t;

    scanf(" %d",&t);
    while(t--)
    {
        sum=0;
        scanf(" %d",&n);
        for(int i=1;i<=n;++i){
            scanf(" %d",&a[i]);
            sum+=a[i];
        }
        printf("%d\n",solve());

    }

	return 0;
}
=======
#include <bits/stdc++.h>
using namespace std;
int n;
int a[100];
bool dp[3000][55];
int sum;
int solve()
{
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
    int minDif=INT_MAX;
    for(int i=0;i<=sum/2;++i)
    if(dp[i][n]){
        minDif=min(sum-2*i,minDif);
    }
    return minDif;
}
int main()
{
    int t;

    scanf(" %d",&t);
    while(t--)
    {
        sum=0;
        scanf(" %d",&n);
        for(int i=1;i<=n;++i){
            scanf(" %d",&a[i]);
            sum+=a[i];
        }
        printf("%d\n",solve());

    }

	return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
