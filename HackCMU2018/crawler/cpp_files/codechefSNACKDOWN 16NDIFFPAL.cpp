<<<<<<< HEAD
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
char ans[10004];
int main()
{
    long long t;
    long long n;
    scanf(" %lld",&t);
    while(t--)
    {

        scanf(" %lld",&n);
        int ch=0,i=0;
        for( i=0;i<n;++i)
        {
            ans[i]=ch+97;
            ch++;
            if(ch==26)
                ch=0;
        }
        ans[i]='\0';
        printf("%s\n",ans);
    }
	return 0;
}
=======
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
char ans[10004];
int main()
{
    long long t;
    long long n;
    scanf(" %lld",&t);
    while(t--)
    {

        scanf(" %lld",&n);
        int ch=0,i=0;
        for( i=0;i<n;++i)
        {
            ans[i]=ch+97;
            ch++;
            if(ch==26)
                ch=0;
        }
        ans[i]='\0';
        printf("%s\n",ans);
    }
	return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
