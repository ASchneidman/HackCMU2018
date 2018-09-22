#include<bits/stdc++.h>

using namespace std;

int main()

{

    int t;

    scanf("%d",&t);

    while(t--)

    {

        long long n,m;

        scanf("%lld %lld",&n,&m);

        vector<long long> v;

        for(long long i=0;i<m;++i)

        {

            long long x;

            scanf("%lld",&x);

            v.push_back(x);

        }

        sort(v.begin(),v.end());

        long long num=m,j=1,cut=0,sum=0;

        for(long long i=0;i<m;++i)

        {

            sum+=v[i];

            if(sum==num-i-2)

            {

                cut=sum;

                break;

            }

            else if(sum<num-i-2)

            {

                cut=sum;

            }

            else

            {

                sum-=v[i];

                num-=(sum+i);

                cut=sum+num-1;

                break;



            }

        }

        printf("%lld\n",cut);



    }

    return 0;

}

