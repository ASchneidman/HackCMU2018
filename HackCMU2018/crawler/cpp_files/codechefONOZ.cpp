<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
long long a[100005],ans[100005];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int t;
    int h,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&h,&m);
        int ans=0;
        for(int i=0;i<h;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(i*11==j or j*11==i)
                    ans++;
                else if(i==j)
                {
                    if(i<10 and j<10)
                        ans++;
                    else if(i%11==0 and j%11==0)
                        ans++;
                }
            }
        }
        printf("%d\n",ans);
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
    int h,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&h,&m);
        int ans=0;
        for(int i=0;i<h;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(i*11==j or j*11==i)
                    ans++;
                else if(i==j)
                {
                    if(i<10 and j<10)
                        ans++;
                    else if(i%11==0 and j%11==0)
                        ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
>>>>>>> 137199fba6bf1ae89e1bd0436b0ee31d0e6c270b
