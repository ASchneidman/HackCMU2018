<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
int lft[102],rght[102],a[102];
int main() {
	//code
	ios::sync_with_stdio(false);
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    for(int i=1;i<=n;++i)
	        cin>>a[i];
	   rght[n+1]=0;
	   for(int i=n;i>0;--i)
	    rght[i]=max(a[i],rght[i+1]);
	    lft[0]=0;
	    for(int i=1;i<=n;++i)
	        lft[i]=max(a[i],lft[i-1]);
	    int ans=0;
	    for(int i=1;i<=n;++i)
	        ans=ans+min(lft[i],rght[i])-a[i];
	    cout<<ans<<endl;
	}
	return 0;
}
=======
#include <bits/stdc++.h>
using namespace std;
int lft[102],rght[102],a[102];
int main() {
	//code
	ios::sync_with_stdio(false);
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    for(int i=1;i<=n;++i)
	        cin>>a[i];
	   rght[n+1]=0;
	   for(int i=n;i>0;--i)
	    rght[i]=max(a[i],rght[i+1]);
	    lft[0]=0;
	    for(int i=1;i<=n;++i)
	        lft[i]=max(a[i],lft[i-1]);
	    int ans=0;
	    for(int i=1;i<=n;++i)
	        ans=ans+min(lft[i],rght[i])-a[i];
	    cout<<ans<<endl;
	}
	return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
