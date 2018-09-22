#include<bits/stdc++.h>
//absurd spoj.. complete when u see
using namespace std;
long long absurd(long long x)
{
        while(x%10==0)
            x=x/10;
        long long num=x,a=0,d=x%10;
        while(num)
        {
            a++;
            num=num/10;
        }
        if(d==5)
            return 2*a-1;
        else
            return 2*a;
}
string itos(long long n)
    {
        string s="";
        while(n) s=char(n%10+'0') + s,n/=10;
        return s;
    }
long long stoi(string s)
    {
        long long tmp=0;
        for(long long i=0;i<s.size();i++) tmp=tmp*10+(s[i]-'0');
        return tmp;
    }
int main(){
    long long t,c;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&c);
        long long low=0.95*c,high=1.05*c;
        long long abdc=absurd(c),abdhigh=absurd(high);
        bool flag=true;
        string s=itos(high);
        string temp=s;
        for(int i=temp.size()-1;i>=1;--i)
        {
            char x=temp[i];
            if(temp[i]>='5')
            {

                temp[i]='5';
                if(stoi(temp)>=low+1)
                    abdhigh=absurd(stoi(temp));
                else
                {
                    temp[i]=x;
                    break;
                }

            }
            if(temp[i]>='0')
            {
                temp[i]='0';
                if(stoi(temp)>=low+1)
                    abdhigh=absurd(stoi(temp));
                else
                {
                    temp[i]=x;
                    break;
                }
            }
        }
        if(abdhigh<abdc)
            printf("absurd\n");
        else
            printf("not absurd\n");

    }

    return 0;
}
