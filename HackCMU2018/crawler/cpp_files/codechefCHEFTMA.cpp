#include<bits/stdc++.h>
using namespace std;
struct job
{
    int a,b;
};
struct job j[100005];
int dif[100005];
multiset<int> ss;

int main()
{
    int t,n,k,m,w;
    scanf("%d",&t);
    while(t--)
    {
        ss.clear();
        scanf("%d %d %d",&n,&k,&m);
        for(int i=0;i<n;++i)
            scanf("%d",&j[i].a);
        for(int i=0;i<n;++i)
        {
            scanf("%d",&j[i].b);
            dif[i]=j[i].a-j[i].b;
        }
        for(int i=0;i<k;++i){
            scanf("%d",&w);
            ss.insert(w);}
        for(int i=0;i<m;++i){
            scanf("%d",&w);
            ss.insert(w);}
        sort(dif,dif+n);

        int sub,ans=0;
        multiset<int>::iterator it;
        for(int i=n-1;i>=0;--i)
        {
            sub=0;
            if(!ss.empty())
            {
                it=ss.end();
                it--;
                if(*it<=dif[i])
                {
                    sub=*it;
                    ss.erase(it);
                }
                else
                {
                    it=ss.lower_bound(dif[i]);
                    while(*it>dif[i] and it!=ss.begin())
                        it--;
                    if(*it<=dif[i])
                    {
                        sub=*it;
                        ss.erase(it);
                    }
                }
                dif[i]-=sub;
            }
            ans+=dif[i];
            //printf("done - %d %d\n",dif[i],sub);
        }
        printf("%d\n",ans);
    }
    return 0;
}
