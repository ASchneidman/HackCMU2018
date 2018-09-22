<<<<<<< HEAD
#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int mod = 1e9+7;

ll gcd(ll x,ll y) {
    if(y==0)
        return x;
    return gcd(y,x%y);
}

ll power(ll x,ll n) {
    ll ret = 1;
    while(n) {
        if(n&1)
            ret = ret*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return ret;
}


const ll inv2 = power(2,mod-2);
int a[100010];
int n;

ll p3[33];
ll prec[33];

ll Search(ll x,ll n1,ll n2,int m) {
    if(x==0)
        return n1;

    ll mid = (n1+n2);
    if(mid>=mod)
        mid-=mod;

    if(x==(1ll<<m))
        return prec[m]*mid%mod;

    if(x<=(1ll<<(m-1))) {
        return Search(x,n1,mid,m-1);
    }
    else {
        ll tmp = Search(1ll<<(m-1),n1,mid,m-1)+mod-mid;
        if(tmp>=mod) tmp-=mod;

        ll tmp2 = Search(x-(1ll<<(m-1)),mid,n2,m-1)+tmp;
        if(tmp2>=mod) tmp2-=mod;
        return tmp2;
    }
}

ll getsum(ll x,int m) {
    //cerr<<"getsum "<<x<<" "<<m<<"\n";
    if(x==0)
        return 0;
    ll lim = (x-1)/(1ll<<m);
    ll sum=0;
    for(int i=0;i<lim;i++) {
        ll tmp = prec[m]*(a[1+i]+a[2+i])%mod;
        tmp = tmp+mod-a[2+i];
        if(tmp>=mod) tmp-=mod;

        sum+=tmp;
        if(sum>=mod) sum-=mod;
    }
    //cerr<<"getsum sum: "<<sum<<"\n";
    x = (x-1)%(1ll<<m);
    ll rem = Search(x,a[1+lim],a[2+lim],m);
    //cerr<<"getsum x: "<<x<<" , rem: "<<rem<<"\n";
    return (sum+rem)%mod;
}

int main() {
    p3[0]=1;
    for(int i=1;i<=32;i++)
        p3[i]=p3[i-1]*3%mod;
    for(int i=0;i<=32;i++)
        prec[i]=inv2*(p3[i]+1)%mod;

    int t;
    scanf("%d",&t);

    while(t--) {
        int m;
        ll x,y;
        scanf("%d%d%lld%lld",&n,&m,&x,&y);

        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        ll sum1 = getsum(x-1,m);
        ll sum2 = getsum(y,m);
        ll ans = (sum2+mod-sum1)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
=======
#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int mod = 1e9+7;

ll gcd(ll x,ll y) {
    if(y==0)
        return x;
    return gcd(y,x%y);
}

ll power(ll x,ll n) {
    ll ret = 1;
    while(n) {
        if(n&1)
            ret = ret*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return ret;
}


const ll inv2 = power(2,mod-2);
int a[100010];
int n;

ll p3[33];
ll prec[33];

ll Search(ll x,ll n1,ll n2,int m) {
    if(x==0)
        return n1;

    ll mid = (n1+n2);
    if(mid>=mod)
        mid-=mod;

    if(x==(1ll<<m))
        return prec[m]*mid%mod;

    if(x<=(1ll<<(m-1))) {
        return Search(x,n1,mid,m-1);
    }
    else {
        ll tmp = Search(1ll<<(m-1),n1,mid,m-1)+mod-mid;
        if(tmp>=mod) tmp-=mod;

        ll tmp2 = Search(x-(1ll<<(m-1)),mid,n2,m-1)+tmp;
        if(tmp2>=mod) tmp2-=mod;
        return tmp2;
    }
}

ll getsum(ll x,int m) {
    //cerr<<"getsum "<<x<<" "<<m<<"\n";
    if(x==0)
        return 0;
    ll lim = (x-1)/(1ll<<m);
    ll sum=0;
    for(int i=0;i<lim;i++) {
        ll tmp = prec[m]*(a[1+i]+a[2+i])%mod;
        tmp = tmp+mod-a[2+i];
        if(tmp>=mod) tmp-=mod;

        sum+=tmp;
        if(sum>=mod) sum-=mod;
    }
    //cerr<<"getsum sum: "<<sum<<"\n";
    x = (x-1)%(1ll<<m);
    ll rem = Search(x,a[1+lim],a[2+lim],m);
    //cerr<<"getsum x: "<<x<<" , rem: "<<rem<<"\n";
    return (sum+rem)%mod;
}

int main() {
    p3[0]=1;
    for(int i=1;i<=32;i++)
        p3[i]=p3[i-1]*3%mod;
    for(int i=0;i<=32;i++)
        prec[i]=inv2*(p3[i]+1)%mod;

    int t;
    scanf("%d",&t);

    while(t--) {
        int m;
        ll x,y;
        scanf("%d%d%lld%lld",&n,&m,&x,&y);

        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        ll sum1 = getsum(x-1,m);
        ll sum2 = getsum(y,m);
        ll ans = (sum2+mod-sum1)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
