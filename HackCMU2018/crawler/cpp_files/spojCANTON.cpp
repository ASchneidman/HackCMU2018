#include<bits/stdc++.h>
#define mod 1000000007
#define maxi 10000005
using namespace std;

vector<long long> sum;
int main()
{
    int t;
    scanf("%d",&t);
    long long n;
    while(t--)
    {
        scanf("%lld",&n);
        sum.push_back(1);
        long long i=1,sum=0,prev=1;
        while(sum<n)
        {
            sum=sum+prev;
            prev++;
        }
        long long dia=(-1+sqrt(1+8*sum))/2;
        long long num,den;
        if(dia&1)
        {
            num=1;
            den=dia;
            while(sum!=n)
            {
                sum--;
                num++;
                den--;
            }
        }
        else
        {
            num=dia;
            den=1;
            while(sum!=n)
            {
                sum--;
                num--;
                den++;
            }
        }
        printf("TERM %lld IS %lld/%lld\n",n,num,den);



    }
    return 0;

}
