<<<<<<< HEAD
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[100];
bool isPrime(int n)
    {
    for(int i=2;i<=sqrt(n);++i)
        if(n%i==0)
            return false;
     return true;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t,n;
    scanf("%d",&t);
    while(t--)
        {
        scanf("%d",&n);
        dp[1]=dp[2]=dp[3]=1;
        dp[4]=2;
        dp[5]=3;
        dp[6]=4;
        dp[7]=5;
        for(int i=8;i<=n;++i)
            dp[i]=dp[i-1]+dp[i-4];
        int ans=0;
        for(int i=2;i<=dp[n];++i)
            if(isPrime(i))
                ans++;
        printf("%d\n",ans);
    }
    return 0;
}
=======
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[100];
bool isPrime(int n)
    {
    for(int i=2;i<=sqrt(n);++i)
        if(n%i==0)
            return false;
     return true;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t,n;
    scanf("%d",&t);
    while(t--)
        {
        scanf("%d",&n);
        dp[1]=dp[2]=dp[3]=1;
        dp[4]=2;
        dp[5]=3;
        dp[6]=4;
        dp[7]=5;
        for(int i=8;i<=n;++i)
            dp[i]=dp[i-1]+dp[i-4];
        int ans=0;
        for(int i=2;i<=dp[n];++i)
            if(isPrime(i))
                ans++;
        printf("%d\n",ans);
    }
    return 0;
}
>>>>>>> 137199fba6bf1ae89e1bd0436b0ee31d0e6c270b
