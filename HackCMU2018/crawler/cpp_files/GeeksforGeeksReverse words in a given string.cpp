<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	ios::sync_with_stdio(false);
	int t;
	string s;
	cin>>t;
	while(t--)
	{
	    cin>>s;
	    stack<char>rev;
	    string ans="";
	    for(int i=s.length()-1;i>=0;--i){
	        if(s[i]!='.')
	        {
	            rev.push(s[i]);
	        }
	        else{
	            if(!rev.empty()){
	                while(!rev.empty())
	                {
	                    ans+=rev.top();
	                    rev.pop();
	                }
	                ans+=".";
	            }
	        }
	    }
	    while(!rev.empty())
	                {
	                    ans+=rev.top();
	                    rev.pop();
	                }
	    cout<<ans<<endl;
	}
	return 0;
}
=======
#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	ios::sync_with_stdio(false);
	int t;
	string s;
	cin>>t;
	while(t--)
	{
	    cin>>s;
	    stack<char>rev;
	    string ans="";
	    for(int i=s.length()-1;i>=0;--i){
	        if(s[i]!='.')
	        {
	            rev.push(s[i]);
	        }
	        else{
	            if(!rev.empty()){
	                while(!rev.empty())
	                {
	                    ans+=rev.top();
	                    rev.pop();
	                }
	                ans+=".";
	            }
	        }
	    }
	    while(!rev.empty())
	                {
	                    ans+=rev.top();
	                    rev.pop();
	                }
	    cout<<ans<<endl;
	}
	return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
