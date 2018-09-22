<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
long long a[100007];
int main() {
	//code
	ios::sync_with_stdio(false);
	int t;
	long long n,k;
	cin>>t;
	while(t--){
	    cin>>n;
	    int x;
	    for(int i=0;i<100007;++i)
	        a[i]=-1;
	    for(int i=0;i<n;++i){
	        cin>>x;
	        a[x]=i;
	    }
	   cin>>k;
	   cout<<a[k]<<endl;
	}

	return 0;
}
=======
#include <bits/stdc++.h>
using namespace std;
long long a[100007];
int main() {
	//code
	ios::sync_with_stdio(false);
	int t;
	long long n,k;
	cin>>t;
	while(t--){
	    cin>>n;
	    int x;
	    for(int i=0;i<100007;++i)
	        a[i]=-1;
	    for(int i=0;i<n;++i){
	        cin>>x;
	        a[x]=i;
	    }
	   cin>>k;
	   cout<<a[k]<<endl;
	}

	return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
