<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
long long c;
long long gcd(long long a,long long b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}
long long solve(long long one,long long two,long long ans,long long a,long long b){

    //cout<<one<<" "<<two<<endl;
    if(one==c or two==c)
        return ans;
    long long x;
    if(one==0)
        x=solve(a,two,ans+1,a,b);
    else if(two==b)
        x=solve(one,0,ans+1,a,b);
    else{
        if(one>=b-two)
            x=solve(one-(b-two),b,ans+1,a,b);
        else
            x=solve(0,one+two,ans+1,a,b);

    }
    return x;


}

int main() {

    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long a,b;
        scanf(" %lld %lld %lld",&a,&b,&c);
        if(a<b)
            swap(a,b);
        long long ans;
        if(c>a and c>b)
            ans=-1;
        else{
            long long g=gcd(a,b);
            if(c%g!=0)
                ans= -1;
            else{
                ans=min(solve(0,0,0,a,b),solve(0,0,0,b,a));
            }

        }

        printf("%lld\n",ans);

    }

    return 0;
}
=======
#include<bits/stdc++.h>
using namespace std;
long long c;
long long gcd(long long a,long long b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}
long long solve(long long one,long long two,long long ans,long long a,long long b){

    //cout<<one<<" "<<two<<endl;
    if(one==c or two==c)
        return ans;
    long long x;
    if(one==0)
        x=solve(a,two,ans+1,a,b);
    else if(two==b)
        x=solve(one,0,ans+1,a,b);
    else{
        if(one>=b-two)
            x=solve(one-(b-two),b,ans+1,a,b);
        else
            x=solve(0,one+two,ans+1,a,b);

    }
    return x;


}

int main() {

    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long a,b;
        scanf(" %lld %lld %lld",&a,&b,&c);
        if(a<b)
            swap(a,b);
        long long ans;
        if(c>a and c>b)
            ans=-1;
        else{
            long long g=gcd(a,b);
            if(c%g!=0)
                ans= -1;
            else{
                ans=min(solve(0,0,0,a,b),solve(0,0,0,b,a));
            }

        }

        printf("%lld\n",ans);

    }

    return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
