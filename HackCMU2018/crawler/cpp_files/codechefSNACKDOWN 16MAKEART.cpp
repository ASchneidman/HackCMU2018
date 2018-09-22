<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		long long a[100006];
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		int flag = 0;
		for(int i=2;i<n;i++)
		{
			if(a[i]==a[i-1]&&a[i]==a[i+1])
			{
				flag = 1;
				break;
			}
		}
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
}
=======
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		long long a[100006];
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		int flag = 0;
		for(int i=2;i<n;i++)
		{
			if(a[i]==a[i-1]&&a[i]==a[i+1])
			{
				flag = 1;
				break;
			}
		}
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
