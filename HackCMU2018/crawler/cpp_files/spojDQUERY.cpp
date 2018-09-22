#include<bits/stdc++.h>
using namespace std;
int cnt[1000006],n,q,cur_ans,ans[200002],arr[30003],bs;
pair<pair<int,int> , int> qr[200002];
inline bool mo_cmp(const pair<pair<int,int>,int> &x,const pair<pair<int,int>,int> &y)
{
    int bl_x=x.first.first/bs,bl_y=y.first.first/bs;
    if(bl_x!=bl_y)
        return bl_x<bl_y;
    return x.first.second<y.first.second;
}
inline void add(int x)
{
    if(cnt[x]==0)
    {
        cur_ans++;
    }
    cnt[x]++;
}
inline void remove(int x)
{
    if(cnt[x]==1)
    {
        cur_ans--;
    }
    cnt[x]--;
}
int main()
{
    scanf("%d",&n);
    bs=sqrt(n);
    for(int i=0;i<n;++i)
        scanf("%d",&arr[i]);
    scanf("%d",&q);
    for(int i=0;i<q;++i)
    {
        scanf("%d %d",&qr[i].first.first,&qr[i].first.second);
        qr[i].second=i;
        qr[i].first.first--;
        qr[i].first.second--;

    }
    sort(qr,qr+q,mo_cmp);
    int mo_r=-1,mo_l=0,l,r;
    for(int i=0;i<q;++i)
    {
        l=qr[i].first.first;
        r=qr[i].first.second;
        while(mo_r<r)
        {
            mo_r++;
            add(arr[mo_r]);
        }
        while(mo_r>r)
        {
            remove(arr[mo_r]);
            mo_r--;
        }
        while(mo_l<l)
        {
            remove(arr[mo_l]);
            mo_l++;
        }
        while(mo_l>l)
        {
            mo_l--;
            add(arr[mo_l]);
        }
        ans[qr[i].second]=cur_ans;
    }
    for(int i=0;i<q;++i)
        printf("%d\n",ans[i]);

    return 0;
}
