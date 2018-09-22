#include<bits/stdc++.h>
using namespace std;
pair<long long,long long > x[100005],y[100005];
map<pair<long long,long long> , int> m;
int main()
{
    int t;
    long long n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        m.clear();
        long long a,b;
        for(long long i=0;i<n;++i)
        {
            scanf("%lld %lld",&a,&b);
            x[i].first=a;
            y[i].first=b;
            x[i].second=b;
            y[i].second=a;
            m[make_pair(a,b)]=i+1;

        }
        sort(x,x+n);
        sort(y,y+n);
        if(m[make_pair(x[0].first,y[0].first)])
            printf("1\n%lld NE",m[make_pair(x[0].first,y[0].first)]);
        else if(m[make_pair(x[n-1].first,y[n-1].first)])
            printf("1\n%lld SE",m[make_pair(x[n-1].first,y[n-1].first)]);
        else if(m[make_pair(x[n-1].first,y[0].first)])
            printf("1\n%lld NW",m[make_pair(x[n-1].first,y[0].first)]);
        else if(m[make_pair(x[0].first,y[n-1].first)])
            printf("1\n%lld SW",m[make_pair(x[0].first,y[n-1].first)]);
        else
        {
            a=m[make_pair(y[0].second,y[0].first)];
            b=m[make_pair(y[1].second,y[1].first)];
            if(y[0].second > y[1].second){
                printf("2\n%lld NW",a);
                printf("\n%lld NE",b);}
            else{
                printf("2\n%lld NE",a);
                printf("\n%lld NW",b);
            }
        }
        printf("\n");
    }
    return 0;
}
