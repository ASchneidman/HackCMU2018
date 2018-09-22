<<<<<<< HEAD
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int main()
{
    long long t,k;
    scanf("%lld",&t);
    while(t--)
    {
        scanf(" %lld",&k);
        k--;
        long long rem,i=0;
        char ans[30];
        if(k==0)
            ans[i++]='0';
        while(k>0)
        {

            rem=k%5;
            ans[i]=rem*2+48;
            i++;
            k=k/5;

        }
        ans[i]='\0';
        reverse(ans,ans+i);
        printf("%s\n",ans);
    }
	return 0;
}
=======
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int main()
{
    long long t,k;
    scanf("%lld",&t);
    while(t--)
    {
        scanf(" %lld",&k);
        k--;
        long long rem,i=0;
        char ans[30];
        if(k==0)
            ans[i++]='0';
        while(k>0)
        {

            rem=k%5;
            ans[i]=rem*2+48;
            i++;
            k=k/5;

        }
        ans[i]='\0';
        reverse(ans,ans+i);
        printf("%s\n",ans);
    }
	return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
