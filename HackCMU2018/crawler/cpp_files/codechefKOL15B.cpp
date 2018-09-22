#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define l long

#define MAX 1003
#define MOD 1000000007

#define fin(i,a,n) for(i=a;i<=n;i++)
#define fde(i,a,n) for(i=n;i>=a;i--)

#define sd(a) scanf("%d",&a)
#define sld(a) scanf("%ld",&a)
#define slld(a) scanf("%lld",&a)
#define slf(a) scanf("%lf",&a)
#define sllf(a) scanf("%llf",&a)
#define ss(a) scanf(" %s",a)

#define pd(a) printf("%d",a)
#define pld(a) printf("%ld",a)
#define plld(a) printf("%lld",a)
#define plf(a) printf("%lf",a)
#define pllf(a) printf("%llf",a)
#define pn printf("\n")
#define ps printf(" ")

#define mp make_pair
#define pb push_back

ll c[MAX][MAX],ml[MAX][MAX],mr[MAX][MAX],md[MAX][MAX],mu[MAX][MAX];

int main()
{
    int t,n,m,i,j;
    sd(t);
    while(t--)
    {
        sd(n);
        sd(m);
        fin(i,0,n-1)
            fin(j,0,m-1)
                slld(c[i][j]);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                if(j==0)
                    ml[i][j] = c[i][j];
                else
                    ml[i][j] = min(c[i][j],ml[i][j-1]+c[i][j]);
            }
        for(i=0;i<n;i++)
            for(j=m-1;j>=0;j--)
            {
                if(j==m-1)
                    mr[i][j] = c[i][j];
                else
                    mr[i][j] = min(c[i][j],mr[i][j+1]+c[i][j]);
            }
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                if(i==0)
                    mu[i][j] = c[i][j];
                else
                    mu[i][j] = min(c[i][j],mu[i-1][j]+c[i][j]);
            }
        for(i=n-1;i>=0;i--)
            for(j=m-1;j>=0;j--)
            {
                if(i==n-1)
                    md[i][j] = c[i][j];
                else
                    md[i][j] = min(c[i][j],md[i+1][j]+c[i][j]);
            }
        ll res = LLONG_MAX;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                res = min(res,ml[i][j] + mr[i][j] + mu[i][j] + md[i][j] - 3*c[i][j]);
            }
        plld(res);
        pn;
    }
    return 0;
}
