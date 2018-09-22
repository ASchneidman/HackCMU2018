<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
bool dp[102][102];
int main() {
	//code
	int t;
	string s;
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
	    cin>>s;
        for(int i=0;i<s.length();++i)
            dp[i][i]=true;
        int maxlen=1,pos=0;
        for(int len=2;len<=s.length();++len)
            for(int i=0;i<=s.length()-len+1;++i){
                int j=i+len-1;
                if(len==2 and s[i]==s[j]){
                    dp[i][j]=true;
                    if(len>maxlen){
                        maxlen=2;
                        pos=i;
                    }

                }
                else if(s[i]==s[j] and dp[i+1][j-1]){
                    dp[i][j]=true;
                    if(len>maxlen){
                        maxlen=len;
                        pos=i;
                    }
                }
                else
                    dp[i][j]=0;
            }
            //cout<<pos<<" "<<maxlen<<endl;
            for(int i=pos;i<pos+maxlen;++i)
                cout<<s[i];
            cout<<endl;
	}
	return 0;
}
=======
#include <bits/stdc++.h>
using namespace std;
bool dp[102][102];
int main() {
	//code
	int t;
	string s;
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
	    cin>>s;
        for(int i=0;i<s.length();++i)
            dp[i][i]=true;
        int maxlen=1,pos=0;
        for(int len=2;len<=s.length();++len)
            for(int i=0;i<=s.length()-len+1;++i){
                int j=i+len-1;
                if(len==2 and s[i]==s[j]){
                    dp[i][j]=true;
                    if(len>maxlen){
                        maxlen=2;
                        pos=i;
                    }

                }
                else if(s[i]==s[j] and dp[i+1][j-1]){
                    dp[i][j]=true;
                    if(len>maxlen){
                        maxlen=len;
                        pos=i;
                    }
                }
                else
                    dp[i][j]=0;
            }
            //cout<<pos<<" "<<maxlen<<endl;
            for(int i=pos;i<pos+maxlen;++i)
                cout<<s[i];
            cout<<endl;
	}
	return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
