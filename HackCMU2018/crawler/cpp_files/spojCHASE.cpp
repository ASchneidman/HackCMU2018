#include <bits/stdc++.h>
#define mod 1000000007
#define twoInv 500000004
using namespace std;

vector<pair<int,int> > v;
double slopeHash[3000];

int main()
{
    ios::sync_with_stdio(false);
    int t,k;
    cin>>t;
    int x,y;
    while(t--)
    {
        v.clear();
        cin>>k;

        for(int i=0;i<k;++i)
        {
            cin>>x>>y;
            v.push_back(make_pair(x,y));
        }
        int ans=0,inf,cnt,sameSl;
        for(int i=0;i<k;++i)
        {
            x=v[i].first;
            y=v[i].second;
            inf=cnt=sameSl=0;
            for(int j=i+1;j<k;++j)
            {
                if(v[j].first==x)
                    inf++;
                else
                    slopeHash[cnt++]=(double)(v[j].second-y)/(double)(v[j].first-x);

            }
            ans=max(ans,inf);
            sort(slopeHash,slopeHash+cnt);
            //for(int j=0;j<cnt;++j)
              //  cout<<slopeHash[j]<<" ";
            //cout<<endl;
            for(int j=0;j<cnt;++j){
                if(j==0 or slopeHash[j]>slopeHash[j-1])
                    sameSl=1;
                else
                    sameSl++;
                ans=max(ans,sameSl);
            }
            //cout<<ans<<endl;
        }
        cout<<ans<<endl;

    }

	return 0;
}
