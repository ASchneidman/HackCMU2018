<<<<<<< HEAD
/*In the Lazy Spelling Bee, a contestant is given a target word W to spell. The contestant's answer word A is acceptable if it is the same length as the target word, and the i-th letter of A is either the i-th, (i-1)th, or (i+1)th letter of W, for all i in the range of the length of A. (The first letter of A must match either the first or second letter of W, since the 0th letter of W doesn't exist. Similarly, the last letter of A must match either the last or next-to-last letter of W.) Note that the target word itself is always an acceptable answer word.

You are preparing a Lazy Spelling Bee, and you have been asked to determine, for each target word, how many distinct acceptable answer words there are. Since this number may be very large, please output it modulo 1000000007 (109 + 7).
*/



#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main()
{

    int t;
    string s;
    ios::sync_with_stdio(false);
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>t;
    long long ans;
    for(int n=1;n<=t;++n)
    {
        ans=0;
        cin>>s;
        ans=1;
        map<char,int> m;
        int cnt=0;
        if(s.length()!=1){
            for(int i=0;i<s.length();++i)
                if(i==0){
                    if(s[i]!=s[i+1])
                        ans*=2;
                }
                else if(i==s.length()-1){
                    if(s[i]!=s[i-1])
                        ans=(ans*2+mod)%mod;
                }
                else
                {
                    m.clear();
                    cnt=0;
                    if(m.find(s[i])==m.end())
                    {
                        cnt++;
                        m[s[i]]=1;
                    }
                    if(m.find(s[i-1])==m.end()){
                        cnt++;
                        m[s[i-1]]=1;
                    }
                    if(m.find(s[i+1])==m.end()){
                        cnt++;
                        m[s[i+1]]=1;
                    }
                    ans*=cnt;
                    if(ans>=mod)
                        ans=ans%mod;
                }
        }
        cout<<"Case #"<<n<<": "<<ans<<endl;

    }

	return 0;
}
=======
/*In the Lazy Spelling Bee, a contestant is given a target word W to spell. The contestant's answer word A is acceptable if it is the same length as the target word, and the i-th letter of A is either the i-th, (i-1)th, or (i+1)th letter of W, for all i in the range of the length of A. (The first letter of A must match either the first or second letter of W, since the 0th letter of W doesn't exist. Similarly, the last letter of A must match either the last or next-to-last letter of W.) Note that the target word itself is always an acceptable answer word.

You are preparing a Lazy Spelling Bee, and you have been asked to determine, for each target word, how many distinct acceptable answer words there are. Since this number may be very large, please output it modulo 1000000007 (109 + 7).
*/



#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main()
{

    int t;
    string s;
    ios::sync_with_stdio(false);
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>t;
    long long ans;
    for(int n=1;n<=t;++n)
    {
        ans=0;
        cin>>s;
        ans=1;
        map<char,int> m;
        int cnt=0;
        if(s.length()!=1){
            for(int i=0;i<s.length();++i)
                if(i==0){
                    if(s[i]!=s[i+1])
                        ans*=2;
                }
                else if(i==s.length()-1){
                    if(s[i]!=s[i-1])
                        ans=(ans*2+mod)%mod;
                }
                else
                {
                    m.clear();
                    cnt=0;
                    if(m.find(s[i])==m.end())
                    {
                        cnt++;
                        m[s[i]]=1;
                    }
                    if(m.find(s[i-1])==m.end()){
                        cnt++;
                        m[s[i-1]]=1;
                    }
                    if(m.find(s[i+1])==m.end()){
                        cnt++;
                        m[s[i+1]]=1;
                    }
                    ans*=cnt;
                    if(ans>=mod)
                        ans=ans%mod;
                }
        }
        cout<<"Case #"<<n<<": "<<ans<<endl;

    }

	return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
