#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int lps[1000006];
void lpsCalc(string pat,int m)
{
    int len=0,i=1;
    lps[0]=0;
    while(i<m)
    {
        if(pat[i]==pat[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len=lps[len-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
}
int main()
{
    int t;
    string s;
    scanf("%d",&t);
    int len;
    for(int x=1;x<=t;++x)
    {
        cin>>s;
        len=s.length();
        lpsCalc(s,len);
        /*for(int i=0;i<s.length();++i)
            cout<<lps[i]<<" ";
        cout<<endl;
        for(int i=1;i<=s.length();++i)
            cout<<i<<" ";
        cout<<endl;*/
        cout<<"Test Case #"<<x<<endl;
        for(int i=1;i<len;++i)
        {

            if(lps[i]==(i+1)/2 and (i+1)%2==0)
            {
                printf("%d %d\n",i+1,2);
                int j=i+lps[i],k=3;

                while(j<len)

                {
                    if(lps[j]%lps[i]==0 and lps[j]!=0)
                    {
                        printf("%d %d\n",j+1,k);
                        k++;
                        j+=lps[i];
                    }
                    else{
                        i=j;
                        break;
                    }
                }

            }

        }
    }
	return 0;
}
