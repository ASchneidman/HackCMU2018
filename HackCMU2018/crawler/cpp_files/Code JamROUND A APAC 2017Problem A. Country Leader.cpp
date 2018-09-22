<<<<<<< HEAD
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
map<long long,double>m;
map<long long,double>temp;
bool cmp(const pair<int,string> &a,const pair<int,string> &b){
    if(a.first>b.first)
        return true;
    else if(a.first==b.first)
    {
        if(a.second<b.second)
            return true;
    }
    return false;
}
int main()
{

    int t;

    ios::sync_with_stdio(false);
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>t;
    int n;
    pair<int,string> p[101];
    char ch[26];
    string s;
    int cnt;
    for(int Case=1;Case<=t;++Case)
    {
        cin>>n;
        for(int i=0;i<=n;++i)
        {
            fill(ch,ch+26,0);

            getline(cin,s);
            cnt=0;

            for(int j=0;j<s.length();++j){
                if(s[j]==' ')
                    continue;
                if(ch[s[j]-'A']==0)
                {
                    cnt++;
                    ch[s[j]-'A']=1;
                }
            }
            //cout<<s<<cnt<<endl;
            p[i]=make_pair(cnt,s);

        }
        sort(p+1,p+n+1,cmp);

        //printf("Case #%d: %s\n",Case,p[n-1].second);
        cout<<"Case #"<<Case<<": "<<p[1].second<<endl;
    }

	return 0;
}
=======
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
map<long long,double>m;
map<long long,double>temp;
bool cmp(const pair<int,string> &a,const pair<int,string> &b){
    if(a.first>b.first)
        return true;
    else if(a.first==b.first)
    {
        if(a.second<b.second)
            return true;
    }
    return false;
}
int main()
{

    int t;

    ios::sync_with_stdio(false);
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>t;
    int n;
    pair<int,string> p[101];
    char ch[26];
    string s;
    int cnt;
    for(int Case=1;Case<=t;++Case)
    {
        cin>>n;
        for(int i=0;i<=n;++i)
        {
            fill(ch,ch+26,0);

            getline(cin,s);
            cnt=0;

            for(int j=0;j<s.length();++j){
                if(s[j]==' ')
                    continue;
                if(ch[s[j]-'A']==0)
                {
                    cnt++;
                    ch[s[j]-'A']=1;
                }
            }
            //cout<<s<<cnt<<endl;
            p[i]=make_pair(cnt,s);

        }
        sort(p+1,p+n+1,cmp);

        //printf("Case #%d: %s\n",Case,p[n-1].second);
        cout<<"Case #"<<Case<<": "<<p[1].second<<endl;
    }

	return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
