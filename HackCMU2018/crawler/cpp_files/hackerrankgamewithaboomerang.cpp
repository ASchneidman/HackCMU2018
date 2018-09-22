#include<bits/stdc++.h>
using namespace std;
map<long long,long long> dp;
long long solve(long long n)
{
    long long k,x;
    if(dp.find(n)!=dp.end())
        return dp[n];
    if(n&1)
                {
                k=n/2+3;
                if(dp.find(n/2)!=dp.end())
                    x=dp[n/2];
                else
                    x=solve(n/2);
                if(k&1){
                    if(k+2*(x-1)>n)
                        dp[n]=(k+2*(x-1))%n;
                    else
                        dp[n]=k+2*(x-1);
                }
                else
                {
                    if(k+2*(x-1)>n-1)
                        dp[n]=(k+2*(x-1))%(n-1);
                    else
                        dp[n]=(k+2*(x-1));

                }
            }
        else
            {
            k=n/2+2;
            if(dp.find(n/2)!=dp.end())
                x=dp[n/2];
            else
                x=solve(n/2);
            if(k&1){
                if(k+2*(x-1)>n)
                    dp[n]=(k+2*(x-1))%n;
                else
                    dp[n]=k+2*(x-1);
            }
            else{
                if(k+2*(x-1)>n)
                    dp[n]=(k+2*(x-1))%n-1;
                else
                    dp[n]=(k+2*(x-1));
            }
        }
        return dp[n];

}
int main(){
    long long t,n;
    scanf(" %lld",&t);
    while(t--)
        {
            dp.clear();
            dp[1]=1;
            dp[2]=1;
            dp[3]=2;
            dp[4]=4;
            dp[5]=5;
        scanf(" %lld",&n);
        printf("%lld\n",solve(n));
    }
    return 0;
}
