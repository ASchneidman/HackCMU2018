<<<<<<< HEAD
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long dp[100005];
int main() {
	//code
	int t;
	long long n;
	scanf(" %d",&t);
	while(t--)
	{
	    scanf(" %lld",&n);
	    dp[1]=0;
	    dp[2]=1;
	    dp[3]=2;
	    for(int i=4;i<=n;++i){
	        dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
	        //printf("%lld %d\n",dp[i],i);
	        if(dp[i]>=mod)
	            dp[i]%=mod;
	    }
	    printf("%lld\n",dp[n]);
	}
	return 0;
}
=======
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long dp[100005];
int main() {
	//code
	int t;
	long long n;
	scanf(" %d",&t);
	while(t--)
	{
	    scanf(" %lld",&n);
	    dp[1]=0;
	    dp[2]=1;
	    dp[3]=2;
	    for(int i=4;i<=n;++i){
	        dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
	        //printf("%lld %d\n",dp[i],i);
	        if(dp[i]>=mod)
	            dp[i]%=mod;
	    }
	    printf("%lld\n",dp[n]);
	}
	return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
