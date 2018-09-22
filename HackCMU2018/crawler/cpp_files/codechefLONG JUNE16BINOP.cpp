<<<<<<< HEAD
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int main()
{
    long long t,k;
    scanf("%lld",&t);
    string a,b;
    while(t--)
    {
        cin>>a>>b;
        long long o=0,z=0,mat=0;
        for(long long i=0;i<a.length();++i){
            if(a[i]!=b[i]){
                if(b[i]=='1')
                    o++;
                else
                    z++;
            }
            else
                mat++;
        }
        if((count(a.begin(),a.end(),'0')==0 and z>0 ) or(count(a.begin(),a.end(),'1')==0 and o>0) )
            printf("Unlucky Chef\n");
        else
            printf("Lucky Chef\n%lld\n",max(o,z));

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
    string a,b;
    while(t--)
    {
        cin>>a>>b;
        long long o=0,z=0,mat=0;
        for(long long i=0;i<a.length();++i){
            if(a[i]!=b[i]){
                if(b[i]=='1')
                    o++;
                else
                    z++;
            }
            else
                mat++;
        }
        if((count(a.begin(),a.end(),'0')==0 and z>0 ) or(count(a.begin(),a.end(),'1')==0 and o>0) )
            printf("Unlucky Chef\n");
        else
            printf("Lucky Chef\n%lld\n",max(o,z));

    }
	return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
