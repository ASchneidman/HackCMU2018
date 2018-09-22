<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
long long dp[1003][1003];
long long a[1003];
long long nonZeroCol[1003];
long long zeroCol[1003];
int main() {
	//code
    long long t;
    long long n;
    scanf(" %lld",&t);
    while(t--)
    {
        scanf(" %lld",&n);
        for(long long i=1;i<=n;++i)
            scanf(" %lld",&a[i]);
            //a[i]=i;
        for(long long i=0;i<=n;++i)
            for(long long j=0;j<=n;++j)
                dp[i][j]=0;
        long long ans=0;
        long long ij;
        long long hZ;
        fill(nonZeroCol,nonZeroCol+1003,0);
        fill(zeroCol,zeroCol+1003,0);
        for(long long i=1;i<=n;++i)
        {
            hZ=0;
            for(long long j=1;j<=n;++j){
                if(j<=i or a[i]==a[j]){
                    dp[i][j]=0;
                    nonZeroCol[j]=0;
                }
                else{
                    nonZeroCol[j]++;
                    long long k=j-1;
                    ij=nonZeroCol[j];
                    long long mini=nonZeroCol[j];
                    while(nonZeroCol[k]!=0){
                        mini=min(mini,nonZeroCol[k]);
                        ij+=mini;
                        k--;
                    }
                    dp[i][j]=ij;
                    ans+=ij;


                }
            }
        }
        /*
        for(long long i=1;i<=n;++i){
            for(long long j=1;j<=n;++j){
                cout<<dp[i][j]<<" ";

            }
            cout<<endl;
        }
    */
        printf("%lld\n",ans);

    }
	return 0;
}
=======
#include <bits/stdc++.h>
using namespace std;
long long dp[1003][1003];
long long a[1003];
long long nonZeroCol[1003];
long long zeroCol[1003];
int main() {
	//code
    long long t;
    long long n;
    scanf(" %lld",&t);
    while(t--)
    {
        scanf(" %lld",&n);
        for(long long i=1;i<=n;++i)
            scanf(" %lld",&a[i]);
            //a[i]=i;
        for(long long i=0;i<=n;++i)
            for(long long j=0;j<=n;++j)
                dp[i][j]=0;
        long long ans=0;
        long long ij;
        long long hZ;
        fill(nonZeroCol,nonZeroCol+1003,0);
        fill(zeroCol,zeroCol+1003,0);
        for(long long i=1;i<=n;++i)
        {
            hZ=0;
            for(long long j=1;j<=n;++j){
                if(j<=i or a[i]==a[j]){
                    dp[i][j]=0;
                    nonZeroCol[j]=0;
                }
                else{
                    nonZeroCol[j]++;
                    long long k=j-1;
                    ij=nonZeroCol[j];
                    long long mini=nonZeroCol[j];
                    while(nonZeroCol[k]!=0){
                        mini=min(mini,nonZeroCol[k]);
                        ij+=mini;
                        k--;
                    }
                    dp[i][j]=ij;
                    ans+=ij;


                }
            }
        }
        /*
        for(long long i=1;i<=n;++i){
            for(long long j=1;j<=n;++j){
                cout<<dp[i][j]<<" ";

            }
            cout<<endl;
        }
    */
        printf("%lld\n",ans);

    }
	return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
