<<<<<<< HEAD
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
char ans[10004];
long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    long long t;
    long long a,b,c,d;
    scanf(" %lld",&t);
    while(t--)
    {
        long long ans=0;
        scanf(" %lld %lld %lld %lld",&a,&b,&c,&d);
        long long g=gcd(c,d);
        ans=min(abs(a-b)%g,g-abs(a-b)%g);
        printf("%lld\n",ans);

    }
	return 0;
}
=======
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
char ans[10004];
long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    long long t;
    long long a,b,c,d;
    scanf(" %lld",&t);
    while(t--)
    {
        long long ans=0;
        scanf(" %lld %lld %lld %lld",&a,&b,&c,&d);
        long long g=gcd(c,d);
        ans=min(abs(a-b)%g,g-abs(a-b)%g);
        printf("%lld\n",ans);

    }
	return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
