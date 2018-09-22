<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
long long a[100005],ans[100005];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int t;
    long long n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(long long i=0;i<n;++i)
            scanf("%lld",&a[i]);
        ans[n-1]=1;
        bool flag=false;
        for(long long i=n-2;i>=0;--i)
        {
            if((a[i]>=0 and a[i+1]<0) or (a[i]<0 and a[i+1]>=0)){flag=false;
                ans[i]=ans[i+1]+1;}
            else
            {
                    ans[i]=1;

            }
        }
        for(long long i=0;i<n;++i)
        {
                printf("%lld ",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
long long a[100005],ans[100005];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int t;
    long long n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        for(long long i=0;i<n;++i)
            scanf("%lld",&a[i]);
        ans[n-1]=1;
        bool flag=false;
        for(long long i=n-2;i>=0;--i)
        {
            if((a[i]>=0 and a[i+1]<0) or (a[i]<0 and a[i+1]>=0)){flag=false;
                ans[i]=ans[i+1]+1;}
            else
            {
                    ans[i]=1;

            }
        }
        for(long long i=0;i<n;++i)
        {
                printf("%lld ",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
>>>>>>> 137199fba6bf1ae89e1bd0436b0ee31d0e6c270b
