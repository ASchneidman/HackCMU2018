<<<<<<< HEAD
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
char dp[1000006];
int k,l,m,big,small;
/*void solve(int n,int k)
{
    dp[1]=true;
    int big=max(k,l);
    int small=min(k,l);
    dp[big]=true;
    dp[small]=true;
    for(int i=2;i<=1000000;++i)
        dp[i]=not(dp[i-big] and dp[i-small] and dp[i-1]);


}*/
char solve(long long n)
{
    if(n<0)
        return '3';
    if(n==1 or n==big or n==small)
        return '1';
    if(dp[n]!='2')
        return dp[n];

    //cout<<n<<endl;


    char rbig=solve(n-big);
    if(rbig=='0')
    {
        dp[n]='1';
        return dp[n];
    }
    char rsmall=solve(n-small);
    if(rsmall=='0')
    {
        dp[n]='1';
        return dp[n];
    }
    char rone=solve(n-1);
    //cout<<rone<<rsmall<<rbig<<endl;
    if(rone=='0')
        dp[n]='1';
    else
        dp[n]='0';
    return dp[n];
}
int main()
{
    ios::sync_with_stdio(false);

    cin>>k>>l>>m;
    big=max(k,l);
    small=min(k,l);
    char ans[52];
    long long i=0,n;
    fill(dp,dp+1000006,'2');
    while(m--)
    {
        cin>>n;
        ans[i++]=(solve(n)=='1')?'A':'B';
    }
    ans[i]='\0';
    cout<<ans;

	return 0;
}
=======
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
char dp[1000006];
int k,l,m,big,small;
/*void solve(int n,int k)
{
    dp[1]=true;
    int big=max(k,l);
    int small=min(k,l);
    dp[big]=true;
    dp[small]=true;
    for(int i=2;i<=1000000;++i)
        dp[i]=not(dp[i-big] and dp[i-small] and dp[i-1]);


}*/
char solve(long long n)
{
    if(n<0)
        return '3';
    if(n==1 or n==big or n==small)
        return '1';
    if(dp[n]!='2')
        return dp[n];

    //cout<<n<<endl;


    char rbig=solve(n-big);
    if(rbig=='0')
    {
        dp[n]='1';
        return dp[n];
    }
    char rsmall=solve(n-small);
    if(rsmall=='0')
    {
        dp[n]='1';
        return dp[n];
    }
    char rone=solve(n-1);
    //cout<<rone<<rsmall<<rbig<<endl;
    if(rone=='0')
        dp[n]='1';
    else
        dp[n]='0';
    return dp[n];
}
int main()
{
    ios::sync_with_stdio(false);

    cin>>k>>l>>m;
    big=max(k,l);
    small=min(k,l);
    char ans[52];
    long long i=0,n;
    fill(dp,dp+1000006,'2');
    while(m--)
    {
        cin>>n;
        ans[i++]=(solve(n)=='1')?'A':'B';
    }
    ans[i]='\0';
    cout<<ans;

	return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
