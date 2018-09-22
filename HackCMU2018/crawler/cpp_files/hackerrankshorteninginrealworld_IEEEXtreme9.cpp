#include<bits/stdc++.h>
using namespace std;
vector<int> v,t;
long long power(int p)
{
    long long res=1;
    while(p--)
        res=res*16;
    return res;
}

int main(){
    string base,tar;
    int n;
    cin>>base;
    scanf("%d",&n);
    for(int i=0;i<base.length();++i)
        v.push_back(base[i]);
    while(n--)
    {
        cin>>tar;
        int j=0;
        t.clear();
        for(int i=0;i<tar.length();++i)
        {
            t.push_back(tar[i]^v[j++]);
            if(j==base.length())
                j=0;
        }
        int cnt=8,ind=0,x,a;
        j=tar.length()-1;
        long long num=0;
        while(cnt--)
            {
                    x=t[j];
                    a=2;
                    while(a--)
                    {
                        num=num+(x%16)*power(ind);
                        ind++;
                        x=x/16;
                    }
                    j--;
            }
            string res;
            while(num)
            {
                x=num%62;
                if(x<=9)
                    res.push_back(x+48);
                else if(x<=35)
                    res.push_back(x+87);
                else
                    res.push_back(x+29);
                num=num/62;
            }
            cout<<base+'/'+string(res.rbegin(),res.rend())<<endl;

    }
    return 0;
}
