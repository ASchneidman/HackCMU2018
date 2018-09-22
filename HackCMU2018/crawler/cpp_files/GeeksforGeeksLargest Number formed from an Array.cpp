<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
int a[1003];
bool cmp(const int &a,const int &b)
{
    string ab=to_string(a)+to_string(b);
    string ba=to_string(b)+to_string(a);
    int f=stoi(ab);
    int s=stoi(ba);
    if(ab>=ba)
        return true;
    return false;
}
int main() {
	//code
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    for(int i=0;i<n;++i)
	        cin>>a[i];
	    sort(a,a+n,cmp);
	    for(int i=0;i<n;++i)
	        cout<<a[i];
	   cout<<endl;
	}
	return 0;
}
=======
#include <bits/stdc++.h>
using namespace std;
int a[1003];
bool cmp(const int &a,const int &b)
{
    string ab=to_string(a)+to_string(b);
    string ba=to_string(b)+to_string(a);
    int f=stoi(ab);
    int s=stoi(ba);
    if(ab>=ba)
        return true;
    return false;
}
int main() {
	//code
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    for(int i=0;i<n;++i)
	        cin>>a[i];
	    sort(a,a+n,cmp);
	    for(int i=0;i<n;++i)
	        cout<<a[i];
	   cout<<endl;
	}
	return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
