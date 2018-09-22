#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long a[100005],c[100005];
long long degree(long long a, long long k) {
  long long res = 1;
  long long cur = a;

  while (k) {
    if (k % 2) {
      res = (res * cur) % mod;
    }
    k /= 2;
    cur = (cur * cur) % mod;
  }
  return res;
}
void nck(long long n)
{
	fill(c,c+100005,0);
	c[0]=1;
	for(long long i=1;i<=n;++i)
		{
			c[i]=(((c[i-1]*(n-i+1))%mod)*degree(i,mod-2))%mod;
		}
}
int main()
{
	int t;
	long long n,k;
	scanf("%d",&t);
	
	while(t--)
	{
		scanf(" %lld %lld",&n,&k);
		
		//for(long long i=0;i<=n;++i)
		//	cout<<c[i]<<" ";
		//cout<<endl;
		for(long long i=0;i<n;++i)
			scanf(" %lld",&a[i]);
		long long z=count(a,a+n,0);
		long long ans=0,l;
		if(z!=0)
		{
			n=n-z;
			nck(n);
			for(long long i=n;i>=0;--i){
				ans+=c[i];
				if(ans>=mod)
					ans=ans%mod;
			}
			printf("%lld\n",ans );
			continue;

		}
		nck(n);
		if(k>n){
			if(n%2 == k%2)
				k=n;
			else 
				k=n-1;

		}
		if(k%2==0)
			l=0;
		else
			l=1;
		

		for(long long i=k;i>=l;i-=2){
			ans+=c[i];
			//cout<<c[i]<<" "<<i<<endl;
			if(ans>=mod)
				ans=ans%mod;
		
		}
		printf("%lld\n",ans );



	}


	return 0;
}