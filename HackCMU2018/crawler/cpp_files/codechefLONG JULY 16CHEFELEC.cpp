<<<<<<< HEAD
#include<bits/stdc++.h>
#define mod 1000000009
using namespace std;
long long a[100005];
int main()
{
    int t;
    long long n;
    scanf(" %d",&t);
    string s;
    while(t--)
    {
        scanf(" %lld",&n);
        cin>>s;
        long long total=0;
        a[0]=0;
        for(long long i=1;i<=n;++i){
            scanf(" %lld",&a[i]);
            if(i==1)
                continue;
            total=total+a[i]-a[i-1];
        }
        a[n+1]=0;
        bool flag=false;
        long long rem=0;

        for(int i=0;i<s.length();++i){
            if(s[i]=='1' and !flag){
                flag=true;
            }
            else if(s[i]=='0' and flag){
                rem=max(rem,max(a[i+2]-a[i+1],a[i+1]-a[i]));
            }
            else if(s[i]=='1' and flag)
            {
                rem=max(rem,a[i+1]-a[i]);
                total-=rem;

                rem=0;
            }
        }
        printf("%lld\n",total);


    }
    return 0;
}
=======
#include<bits/stdc++.h>
#define mod 1000000009
using namespace std;
long long a[100005];
int main()
{
    int t;
    long long n;
    scanf(" %d",&t);
    string s;
    while(t--)
    {
        scanf(" %lld",&n);
        cin>>s;
        long long total=0;
        a[0]=0;
        for(long long i=1;i<=n;++i){
            scanf(" %lld",&a[i]);
            if(i==1)
                continue;
            total=total+a[i]-a[i-1];
        }
        a[n+1]=0;
        bool flag=false;
        long long rem=0;

        for(int i=0;i<s.length();++i){
            if(s[i]=='1' and !flag){
                flag=true;
            }
            else if(s[i]=='0' and flag){
                rem=max(rem,max(a[i+2]-a[i+1],a[i+1]-a[i]));
            }
            else if(s[i]=='1' and flag)
            {
                rem=max(rem,a[i+1]-a[i]);
                total-=rem;

                rem=0;
            }
        }
        printf("%lld\n",total);


    }
    return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
