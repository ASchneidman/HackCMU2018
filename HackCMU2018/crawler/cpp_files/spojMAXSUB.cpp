#include<bits/stdc++.h>
using namespace std;
long long a[500005];
#define mod 1000000009
int main() {

   int t;
   long long n,sum,no,cnt;
   scanf("%d",&t);
   while(t--)
   {
       scanf("%lld",&n);
       sum=no=cnt=0;
       long long mini=0;
       bool flag=true;
       for(long long i=0;i<n;++i)
       {
           scanf("%lld",&a[i]);
           if(a[i]>0)
           {
               sum+=a[i];
               flag=false;

           }
           else if(a[i]==0)
           {
               flag=false;
               no++;
           }

       }

       if(sum==0)
       {
           if(flag)
           {
               sum=*max_element(a,a+n);
               cnt=count(a,a+n,sum);
           }
           else
           {
                mini=1;
                for(int i=0;i<no;++i)
                    mini=(mini*2)%mod;
                cnt=mini-1;
           }
       }
       else
       {
           mini=1;
           for(int i=0;i<no;++i)
                mini=(mini*2)%mod;
        cnt=mini;

       }
        printf("%lld %lld\n",sum,cnt%mod);

   }
    return 0;
}
