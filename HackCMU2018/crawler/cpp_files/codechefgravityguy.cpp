#include<bits/stdc++.h>
using namespace std;


int main()
{
   long long t;
   string a,b;
   scanf("%lld",&t);
   while(t--)
   {
       cin>>a>>b;
       long long len=a.length(),i;
       bool dp[len+1];
       if(a[0]=='#' and b[0]=='#')
       {
           printf("No\n");
           continue;
       }
    long long k=0,l=0;
    while(a[k]=='.')
        k++;
    while(b[l]=='.')
        l++;
    if(k>l)
        {
            long long x=k;
            i=k;
            while(x--)
                dp[x]=true;

        }
    else
    {
        long long x=l;
        i=k;
        while(x--)
            dp[x]=false;
    }
        bool flag=true;
       for(;i<len;++i)
       {
           if(dp[i-1])
           {
               if(a[i]=='.')
                    dp[i]=true;
               else
                    if(b[i]=='.')
                        dp[i]=false;
                    else
                    {
                        printf("No\n");
                        flag=false;
                        break;
                    }
           }
           else
           {
               if(b[i]=='.')
                    dp[i]=false;
               else
                    if(a[i]=='.')
                        dp[i]=true;
                    else
                    {
                        printf("No\n");
                        flag=false;
                        break;
                    }

           }
    }
    if(flag){
    long long ans=0;
    for(int i=1;i<len;++i)
        if(dp[i-1]!=dp[i])
            ans++;
    printf("Yes\n%lld\n",ans);
    }
   }
    return 0;
}
