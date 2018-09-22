#include<bits/stdc++.h>
using namespace std;
int a[10005];
vector<int> v;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

void sieve(int n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
    for(int i=2;i<=n;++i)
        if(prime[i])
            v.push_back(i);
}
int main()
{
    int t,n;
    scanf("%d",&t);
    sieve(10009);
    while(t--)
    {
        scanf("%d",&n);
        int ans,res=0,j;
        bool flag=false;
        for(int i=0;i<n;++i)
             scanf("%d",&a[i]);
        a[n]=INT_MAX;
        for(int i=n-2;i>=0;--i)
        {
            j=i;
            while(a[j]>a[j+1])
            {
                res+=(a[j]-a[j+1]);
                a[j+1]=a[j];
                j++;
            }
        }
        int maxi;
        ans=INT_MAX;
        for(int i=0;i<v.size();++i)
        {
            maxi=0;
            //cout<<v[i]<<endl;
            for(int j=0;j<n;++j)
                maxi+=((a[j]%v[i]==0)?0:(a[j]/v[i]+1)*v[i]-a[j]);
            ans=min(maxi,ans);
        }

        printf("%d\n",ans+res);

    }
    return 0;
}
