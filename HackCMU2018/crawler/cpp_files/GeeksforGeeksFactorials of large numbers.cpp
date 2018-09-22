<<<<<<< HEAD
#include <bits/stdc++.h>

using namespace std;
vector<int> ans;
void multiply(int a){
    int carry=0,prod;
    for(int i=0;i<ans.size();++i){
        prod=ans[i]*a+carry;
        ans[i]=prod%10;
        carry=prod/10;
    }
    while(carry){
        ans.push_back(carry%10);
        carry=carry/10;
    }
}
int main() {
	//code
	int t,n;
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
	    cin>>n;
	    ans.clear();
	    ans.push_back(1);
	    for(int i=2;i<=n;++i)
	        multiply(i);
	   for(int i=ans.size()-1;i>=0;--i)
	    cout<<ans[i];
	    cout<<endl;
	}
	return 0;
}
=======
#include <bits/stdc++.h>

using namespace std;
vector<int> ans;
void multiply(int a){
    int carry=0,prod;
    for(int i=0;i<ans.size();++i){
        prod=ans[i]*a+carry;
        ans[i]=prod%10;
        carry=prod/10;
    }
    while(carry){
        ans.push_back(carry%10);
        carry=carry/10;
    }
}
int main() {
	//code
	int t,n;
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
	    cin>>n;
	    ans.clear();
	    ans.push_back(1);
	    for(int i=2;i<=n;++i)
	        multiply(i);
	   for(int i=ans.size()-1;i>=0;--i)
	    cout<<ans[i];
	    cout<<endl;
	}
	return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
