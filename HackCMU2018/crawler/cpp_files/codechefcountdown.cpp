#include<iostream>
#include<algorithm>
long long pos(long long a,long long b)
{
    if(a-b>0)
        return a-b;
    else
        return b-a;
}
using namespace std;
int main()
{
    long t;
    cin>>t;
    while(t--)
    {
        long long a,b,days=0,i,j,dif;
        cin>>a>>b;
        long long arr[a];
        arr[0]=a;
        arr[1]=b;
        dif=pos(a,b);
        if(dif==a||dif==b);

        else
            {

                arr[2]=dif;
                days++;


            for(i=0;i<days+2;++i)
            {

                    for(j=i+1;j<days+2;++j)
                        dif=pos(arr[i],arr[j]);
                        if(arr[i]!=arr[j]&&(count(arr,arr+days+2,dif)==0))
                    {

                    arr[days+2]=dif;
                    days++;
                    }

            }
            }

        cout<<days<<endl;

    }
}
