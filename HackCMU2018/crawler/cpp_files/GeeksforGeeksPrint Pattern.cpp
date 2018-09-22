<<<<<<< HEAD
/*Print a sequence of numbers starting with N, without using loop, in which  A[i+1] = A[i] - 5,  if  A[i]>0, else A[i+1]=A[i] + 5  repeat it until A[i]=N.
*/


#include <iostream>
using namespace std;
void solve(int a,int n,bool flag){
    if(a==n){
        cout<<a;
        return ;
    }
    if(flag){
        if(a>0){
            cout<<a<<" ";
            solve(a-5,n,flag);
        }
        else{
            flag=false;
            cout<<a<<" ";
            solve(a+5,n,flag);
        }
    }
    else{
            cout<<a<<" ";
            solve(a+5,n,flag);
    }
}
int main() {
	//code
	int t,n;
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
	    cin>>n;
	    cout<<n<<" ";
	    solve(n-5,n,true);
	    cout<<endl;
	}
	return 0;
}
=======
/*Print a sequence of numbers starting with N, without using loop, in which  A[i+1] = A[i] - 5,  if  A[i]>0, else A[i+1]=A[i] + 5  repeat it until A[i]=N.
*/


#include <iostream>
using namespace std;
void solve(int a,int n,bool flag){
    if(a==n){
        cout<<a;
        return ;
    }
    if(flag){
        if(a>0){
            cout<<a<<" ";
            solve(a-5,n,flag);
        }
        else{
            flag=false;
            cout<<a<<" ";
            solve(a+5,n,flag);
        }
    }
    else{
            cout<<a<<" ";
            solve(a+5,n,flag);
    }
}
int main() {
	//code
	int t,n;
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
	    cin>>n;
	    cout<<n<<" ";
	    solve(n-5,n,true);
	    cout<<endl;
	}
	return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
