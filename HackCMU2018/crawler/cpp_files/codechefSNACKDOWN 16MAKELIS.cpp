<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 31
#define N 100000
int c[101],d[101];
int main()
{
    int t,r,k,i,j,s,x,y,z;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&k);
        x=k;
        i=0;
        s=0;
        while(x)
        {
            d[i]=x%4;
            x=x/4;
            i++;
        }
        s=4*(i-1);
        for(j=0;j<i;j++)
        {
            //cout<<"dsc "<<s<<endl;
            if(d[j])
                s+=i-j-1;
            //cout<<"dsc 1 "<<s<<endl;
            s+=d[j];
            //cout<<"dsc 2 "<<s<<endl;
        }
        //cout<<s<<endl;
        x=s;
        y=1;
        z=0;
        for(j=0;j<i;j++)
        {
            if(d[j])
            {
                r=d[j]+i-j-1;
                //cout<<d[j]<<" fes r"<<endl;
                for(k=1;k<i-j;k++)
                    c[z+r-k]=y++;
                //cout<<c[1]<<" fgf"<<endl;
                for(k=0;k<d[j];k++)
                    c[z+k]=y++;
                //cout<<c[1]<<" fgf"<<endl;
                z+=r;
            }
            for(k=3;k>=0;k--)
                c[z+k]=x--;
            z+=4;
        }
        printf("%d\n",s);
        for(j=s-1;j>=0;j--)
            printf("%d ",c[j]);
        printf("\n");
    }
    return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 31
#define N 100000
int c[101],d[101];
int main()
{
    int t,r,k,i,j,s,x,y,z;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&k);
        x=k;
        i=0;
        s=0;
        while(x)
        {
            d[i]=x%4;
            x=x/4;
            i++;
        }
        s=4*(i-1);
        for(j=0;j<i;j++)
        {
            //cout<<"dsc "<<s<<endl;
            if(d[j])
                s+=i-j-1;
            //cout<<"dsc 1 "<<s<<endl;
            s+=d[j];
            //cout<<"dsc 2 "<<s<<endl;
        }
        //cout<<s<<endl;
        x=s;
        y=1;
        z=0;
        for(j=0;j<i;j++)
        {
            if(d[j])
            {
                r=d[j]+i-j-1;
                //cout<<d[j]<<" fes r"<<endl;
                for(k=1;k<i-j;k++)
                    c[z+r-k]=y++;
                //cout<<c[1]<<" fgf"<<endl;
                for(k=0;k<d[j];k++)
                    c[z+k]=y++;
                //cout<<c[1]<<" fgf"<<endl;
                z+=r;
            }
            for(k=3;k>=0;k--)
                c[z+k]=x--;
            z+=4;
        }
        printf("%d\n",s);
        for(j=s-1;j>=0;j--)
            printf("%d ",c[j]);
        printf("\n");
    }
    return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
