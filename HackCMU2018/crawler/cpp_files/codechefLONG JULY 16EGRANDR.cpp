<<<<<<< HEAD
#include<bits/stdc++.h>
#define mod 1000000009
using namespace std;
int main()
{
    int t;
    long long n;
    scanf(" %d",&t);
    while(t--)
    {
        scanf(" %lld",&n);
        bool flag=true,full=false;
        double total=0;
        int grade;
        for(long long i=0;i<n;++i){
            scanf(" %d",&grade);
            total+=grade;
            if(grade==5)
                full=true;
            if(grade==2)
                flag=false;
        }
        if(full and flag and total/n>=4)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
=======
#include<bits/stdc++.h>
#define mod 1000000009
using namespace std;
int main()
{
    int t;
    long long n;
    scanf(" %d",&t);
    while(t--)
    {
        scanf(" %lld",&n);
        bool flag=true,full=false;
        double total=0;
        int grade;
        for(long long i=0;i<n;++i){
            scanf(" %d",&grade);
            total+=grade;
            if(grade==5)
                full=true;
            if(grade==2)
                flag=false;
        }
        if(full and flag and total/n>=4)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
