#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int a[1001][1001],l[1001][1001],r[1001][1001],up[1001][1001],down[1001][1001];
int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        char x;
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
            {
                scanf(" %c",&x);
                if(x=='*')
                    a[i][j]=1;
                else
                    a[i][j]=0;
                //cout<<i<<j<<endl;
            }
        //right
        bool flag;
        int ufar,lfar,rfar,dfar;
        //cout<<"right";
        flag=false;
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
            {
                if(a[i][j] and flag==false)
        {
            ufar=i;
            flag=true;
            for(int k=0;k<m;++k)
                up[i][k]=0;
        }
                if(flag)
                    up[i][j]=i-ufar;
                else
                    up[i][j]=-1;
            }

        flag=false;
        for(int i=n-1;i>=0;--i)
            for(int j=0;j<m;++j){
            if(a[i][j] and flag==false)
        {
            dfar=i;
            flag=true;
            for(int k=0;k<m;++k)
                down[i][k]=0;
        }
            if(flag)
                down[i][j]=dfar-i;
            else
                down[i][j]=-1;
            }
            flag=false;
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j){
            if(a[j][i] and flag==false)
        {
            lfar=i;
            flag=true;
            for(int k=0;k<n;++k)
                l[k][i]=0;
        }
            if(flag)
                l[j][i]=i-lfar;
            else
                l[j][i]=-1;
            }
            flag=false;
        for(int i=m-1;i>=0;--i)
            for(int j=n-1;j>=0;--j){
                if(a[j][i] and flag==false)
        {
            rfar=i;
            flag=true;
            for(int k=0;k<n;++k)
                r[k][i]=0;
        }
            if(flag)
                r[j][i]=rfar-i;
            else
                r[j][i]=-1;
            }

        //answer
        int ans=INT_MAX,lev;
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
        {
            lev=max(l[i][j],max(r[i][j],max(up[i][j],down[i][j])));
            //printf("%d %d %d %d\n",l[i][j],r[i][j],up[i][j],down[i][j]);
            lev++;
            ans=min(ans,lev);
        }
        printf("%d\n",ans);

    }
    return 0;
}
