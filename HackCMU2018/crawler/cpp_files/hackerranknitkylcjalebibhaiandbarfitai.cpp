#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define mod 1000000007
vector<int> v;
bool sieve[10000001];
int comb[670000][11];
void create_sieve(int n)
{
    fill(sieve,sieve+n,true);
    for(int p=2;p*p<=n;++p)
        if(sieve[p])
            for(int j=2*p;j<=n;j+=p)
                sieve[j]=false;
     for(int p=2;p<=n;++p)
        if(sieve[p]){
            v.push_back(p);}

      for(int i=0;i<670000;++i)
        {

            for(int j=0;j<11;++j)
                {
                if(i<j)
                    continue;
                if(i==j or j==0 )
                    comb[i][j]=1;
                else
                    comb[i][j]=comb[i-1][j-1]+comb[i-1][j];
                if(comb[i][j]>=mod)
                    comb[i][j]=comb[i][j]%mod;
            }
    }

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q,l,r,k;
    scanf(" %d",&q);

    create_sieve(10000000);

    while(q--)
        {
        scanf("%d %d %d",&l,&r,&k);
        int ans=0;
        vector<int>::iterator lp=lower_bound(v.begin(),v.end(),l);
        vector<int>::iterator rp=lower_bound(v.begin(),v.end(),r);
        ans=rp-lp;
        if(*rp==r)
            ans++;

        printf("%d\n",comb[ans][k]);
    }
    return 0;
}
