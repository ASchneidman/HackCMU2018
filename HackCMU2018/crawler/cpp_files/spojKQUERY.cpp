#include <bits/stdc++.h>
long long a,tree[30003],n,res[200002];
void update(long long pos,long long val)
{
        while(pos<=30002)
        {
            tree[pos]+=val;
            pos+=(pos & -pos);
        }
}
long long query(long long pos)
{
    long long sum=0;
    while(pos>0)
    {
        sum+=tree[pos];
        pos-=(pos & -pos);
    }
    return sum;
}
using namespace std;
struct range
{
    long long i,j,k,pos;
};
bool cmp(const range &a , const range &b){
    return a.k > b.k;}
map<long long , pair<long long,long long> > m;
vector<pair<long long, long long > > v;
vector <range> que;
int main()
{
    scanf("%lld",&n);
    for(long long i=1;i<=n;++i)
    {
        scanf(" %lld",&a);
        v.push_back(make_pair(a,i));
    }
    sort(v.begin(),v.end());
    long long q,b,c;
    scanf(" %lld",&q);
    range r;
    for(long long i=0;i<q;++i)
    {
        scanf("%lld%lld%lld",&r.i,&r.j,&r.k);
        r.pos=i;
        que.push_back(r);
    }
    sort(que.begin(),que.end(),cmp);
    long long x=n-1;
    for(long long i=0;i<q;++i)
    {
        while(x>=0 and v[x].first > que[i].k)
        {
            update(v[x].second,1);
            x--;
        }
        res[que[i].pos]=query(que[i].j)-query(que[i].i-1);
    }
    for(long long i=0;i<q;++i)
        printf("%lld\n",res[i]);
    return 0;
}
