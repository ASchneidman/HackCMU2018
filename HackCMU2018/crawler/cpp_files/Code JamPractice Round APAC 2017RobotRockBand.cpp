<<<<<<< HEAD
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
vector<long long> a,b,c,d;
map<long long,long long>ab,cd;
int main()
{

    int t;
    string s;
    ios::sync_with_stdio(false);
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>t;
    long long ans,n,k,x;
    for(int Case=1;Case<=t;++Case)
    {
        cin>>n>>k;
        a.clear();
        b.clear();
        c.clear();
        d.clear();
        ab.clear();
        cd.clear();
        for(int i=0;i<n;++i){
            cin>>x;
            a.push_back(x);
        }
        for(int i=0;i<n;++i){
            cin>>x;
            b.push_back(x);
        }
        for(int i=0;i<n;++i){
            cin>>x;
            c.push_back(x);
        }
        for(int i=0;i<n;++i){
            cin>>x;
            d.push_back(x);
        }
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                if(ab.find(a[i] xor b[j])==ab.end())
                    ab[a[i] xor b[j]]=1;
                else
                    ab[a[i] xor b[j]]++;
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                if(cd.find(c[i] xor d[j])==cd.end())
                    cd[c[i] xor d[j]]=1;
                else
                    cd[c[i] xor d[j]]++;
        map<long long,long long>::iterator it;
        ans=0;
        long long rem;
        for(it=ab.begin();it!=ab.end();++it){
            rem=k xor it->first;
            if(cd.find(rem)!=cd.end())
                ans=ans+((it->second)*cd[rem]);
        }
        cout<<"Case #"<<Case<<": "<<ans<<endl;

    }

	return 0;
}
=======
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
vector<long long> a,b,c,d;
map<long long,long long>ab,cd;
int main()
{

    int t;
    string s;
    ios::sync_with_stdio(false);
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>t;
    long long ans,n,k,x;
    for(int Case=1;Case<=t;++Case)
    {
        cin>>n>>k;
        a.clear();
        b.clear();
        c.clear();
        d.clear();
        ab.clear();
        cd.clear();
        for(int i=0;i<n;++i){
            cin>>x;
            a.push_back(x);
        }
        for(int i=0;i<n;++i){
            cin>>x;
            b.push_back(x);
        }
        for(int i=0;i<n;++i){
            cin>>x;
            c.push_back(x);
        }
        for(int i=0;i<n;++i){
            cin>>x;
            d.push_back(x);
        }
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                if(ab.find(a[i] xor b[j])==ab.end())
                    ab[a[i] xor b[j]]=1;
                else
                    ab[a[i] xor b[j]]++;
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                if(cd.find(c[i] xor d[j])==cd.end())
                    cd[c[i] xor d[j]]=1;
                else
                    cd[c[i] xor d[j]]++;
        map<long long,long long>::iterator it;
        ans=0;
        long long rem;
        for(it=ab.begin();it!=ab.end();++it){
            rem=k xor it->first;
            if(cd.find(rem)!=cd.end())
                ans=ans+((it->second)*cd[rem]);
        }
        cout<<"Case #"<<Case<<": "<<ans<<endl;

    }

	return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
