<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;

int a[100005];
bool flag[100005];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t,n,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        fill(flag,flag+n+1,false);

        for(int i=1;i<=n;++i)
            a[i]=i;
        for(int i=1;i<=n;++i)
        {
            if(!flag[i]){
                if(i+k<=n){
                swap(a[i],a[i+k]);
                flag[i]=flag[i+k]=true;}
            }
        }
        bool ansFlag=true;
        for(int i=1;i<=n;++i)
            if(abs(a[i]-i)!=k)
        {
            ansFlag=false;
            break;
        }
        if(ansFlag)
        {
            for(int i=1;i<=n;++i)
                printf("%d ",a[i]);
        }
        else
            printf("-1");
        printf("\n");
    }
    return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;

int a[100005];
bool flag[100005];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t,n,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        fill(flag,flag+n+1,false);

        for(int i=1;i<=n;++i)
            a[i]=i;
        for(int i=1;i<=n;++i)
        {
            if(!flag[i]){
                if(i+k<=n){
                swap(a[i],a[i+k]);
                flag[i]=flag[i+k]=true;}
            }
        }
        bool ansFlag=true;
        for(int i=1;i<=n;++i)
            if(abs(a[i]-i)!=k)
        {
            ansFlag=false;
            break;
        }
        if(ansFlag)
        {
            for(int i=1;i<=n;++i)
                printf("%d ",a[i]);
        }
        else
            printf("-1");
        printf("\n");
    }
    return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
