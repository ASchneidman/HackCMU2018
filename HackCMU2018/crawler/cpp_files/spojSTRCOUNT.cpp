<<<<<<< HEAD
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long dp[65][65];
int main()
{
    ios::sync_with_stdio(false);
    for(int i=0;i<65;++i)
        for(int j=0;j<65;++j)
            dp[i][j]=0;
    dp[0][0]=1;

    for(int i=1;i<=63;++i)
    {
        dp[i][0]=1;
        dp[i][i]=1;
        cout<<"1 ";
        for(int j=1;j<i;++j)
        {
            dp[i][j]=dp[i-1][j];

            for(int k=0;k<=j;++k)
                dp[i][j]+=dp[i-j-1][k];

            for(int k=1;k<j;++k)
                    dp[i][j]+=dp[i-k-1][j];

            cout<<dp[i][j]<<" ";
        }
        cout<<"1";
        cout<<endl;
    }

	return 0;
}
=======
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long dp[65][65];
int main()
{
    ios::sync_with_stdio(false);
    for(int i=0;i<65;++i)
        for(int j=0;j<65;++j)
            dp[i][j]=0;
    dp[0][0]=1;

    for(int i=1;i<=63;++i)
    {
        dp[i][0]=1;
        dp[i][i]=1;
        cout<<"1 ";
        for(int j=1;j<i;++j)
        {
            dp[i][j]=dp[i-1][j];

            for(int k=0;k<=j;++k)
                dp[i][j]+=dp[i-j-1][k];

            for(int k=1;k<j;++k)
                    dp[i][j]+=dp[i-k-1][j];

            cout<<dp[i][j]<<" ";
        }
        cout<<"1";
        cout<<endl;
    }

	return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
