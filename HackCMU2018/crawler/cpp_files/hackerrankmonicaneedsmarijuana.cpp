#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void multiply(long long F[2][2], long long M[2][2]);

void power(long long F[2][2], long long n);
long long fib(long long n)
{
  long long F[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(F, n-1);
  return F[0][0];
}
long long mod;
/* Optimized version of power() in method 4 */
void power(long long F[2][2], long long n)
{
  if( n == 0 || n == 1)
      return;
  long long M[2][2] = {{1,1},{1,0}};

  power(F, n/2);
  multiply(F, F);

  if (n%2 != 0)
     multiply(F, M);
}

void multiply(long long F[2][2], long long M[2][2])
{
  long long x =  (F[0][0]*M[0][0] + F[0][1]*M[1][0])%mod;
  long long y =  (F[0][0]*M[0][1] + F[0][1]*M[1][1])%mod;
  long long z =  (F[1][0]*M[0][0] + F[1][1]*M[1][0])%mod;
  long long w =  (F[1][0]*M[0][1] + F[1][1]*M[1][1])%mod;

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long t,n,m;
    scanf("%lld",&t);
    while(t--)
        {
        scanf("%lld %lld",&n,&m);
        mod=m;
            printf("%lld\n",(fib(n+2)-1+mod)%mod);


    }
    return 0;
}
