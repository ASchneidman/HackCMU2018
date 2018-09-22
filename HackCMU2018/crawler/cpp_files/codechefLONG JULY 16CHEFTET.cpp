<<<<<<< HEAD
#include <bits/stdc++.h>
#define mod 786433
using namespace std;
long long N;
vector<long long> a,B;
long long solve(long long b,int n,bool ab,bool af)
{
    if(n==N-1 and n!=0){
        long long n1,n2,n3,n4;
        n1=n2=n3=n4=b;
        n2+=a[n];
        n3+=a[n-1];
        n4+=(a[n]+a[n-1]);
        long long b1,b2,b3,b4;
        b1=solve(n1,n-1,true,true);

        b2=solve(n2,n-1,true,false);

        b3=solve(n3,n-1,false,true);

        b4=solve(n4,n-1,false,false);
        return max(b1,max(b2,max(b3,b4)));
    }
    else if(n>0){
            //cout<<b<<endl;
        long long n1,n2,n3,n4,n5,n6,n7,n8;
        long long b1,b2,b3,b4;
        b1=b2=b3=b4=-1;
        n1=n2=n3=n4=B[n];
        if(af){
            n1+=a[n+1];
            if(n1==b)
                b1=solve(n1,n-1,true,ab);
            if(ab){
                n2+=(a[n+1]+a[n]);
                if(n2==b)
                    b2=solve(n2,n-1,true,false);
                n4+=(a[n+1]+a[n-1]+a[n]);
                if(n4==b)
                    b4=solve(n4,n-1,false,false);
            }
            n3+=(a[n+1]+a[n-1]);
            if(n3==b)
                b3=solve(n3,n-1,false,ab);
            return max(b1,max(b2,max(b3,b4)));

        }
        else{
            if(n1==b)
                b1=solve(n1,n-1,true,ab);
            if(ab){
                n2+=a[n];
                if(n2==b)
                    b2=solve(n2,n-1,true,false);
                n3+=(a[n]+a[n-1]);
                if(n3==b)
                    b3=solve(n3,n-1,false,false);
            }
            n4+=a[n-1];
            if(n4==b)
                b4=solve(n4,n-1,false,ab);
            return max(b1,max(b2,max(b3,b4)));
        }
    }
    else if(n==0){
        long long n1=B[n];

        if(ab and af){
            n1+=(a[n]+a[n+1]);
            if(n1==b)
                return b;
        }
        else if(ab and !af){
            n1+=a[n];

            if(n1==b)
                return b;
        }
        else if(!ab and af){
            n1+=a[n+1];
            if(n1==b)
                return b;
        }
        else{
            if(n1==b)
                return b;
        }
    }
}
long long dp[10004][10];
int main() {
	//code
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        a.clear();
        B.clear();
        scanf(" %lld",&N);
        long long A,b;
        for(long long i=0;i<N;++i){
            scanf(" %lld",&b);
            a.push_back(b);
        }
        for(long long i=0;i<N;++i){
            scanf(" %lld",&A);
            B.push_back(A);
        }
        if(N==1)
            printf("%lld\n",a[0]+B[0]);
        else
            printf("%lld\n",solve(B[N-1],N-1,true,true));
    }
	return 0;
}
=======
#include <bits/stdc++.h>
#define mod 786433
using namespace std;
long long N;
vector<long long> a,B;
long long solve(long long b,int n,bool ab,bool af)
{
    if(n==N-1 and n!=0){
        long long n1,n2,n3,n4;
        n1=n2=n3=n4=b;
        n2+=a[n];
        n3+=a[n-1];
        n4+=(a[n]+a[n-1]);
        long long b1,b2,b3,b4;
        b1=solve(n1,n-1,true,true);

        b2=solve(n2,n-1,true,false);

        b3=solve(n3,n-1,false,true);

        b4=solve(n4,n-1,false,false);
        return max(b1,max(b2,max(b3,b4)));
    }
    else if(n>0){
            //cout<<b<<endl;
        long long n1,n2,n3,n4,n5,n6,n7,n8;
        long long b1,b2,b3,b4;
        b1=b2=b3=b4=-1;
        n1=n2=n3=n4=B[n];
        if(af){
            n1+=a[n+1];
            if(n1==b)
                b1=solve(n1,n-1,true,ab);
            if(ab){
                n2+=(a[n+1]+a[n]);
                if(n2==b)
                    b2=solve(n2,n-1,true,false);
                n4+=(a[n+1]+a[n-1]+a[n]);
                if(n4==b)
                    b4=solve(n4,n-1,false,false);
            }
            n3+=(a[n+1]+a[n-1]);
            if(n3==b)
                b3=solve(n3,n-1,false,ab);
            return max(b1,max(b2,max(b3,b4)));

        }
        else{
            if(n1==b)
                b1=solve(n1,n-1,true,ab);
            if(ab){
                n2+=a[n];
                if(n2==b)
                    b2=solve(n2,n-1,true,false);
                n3+=(a[n]+a[n-1]);
                if(n3==b)
                    b3=solve(n3,n-1,false,false);
            }
            n4+=a[n-1];
            if(n4==b)
                b4=solve(n4,n-1,false,ab);
            return max(b1,max(b2,max(b3,b4)));
        }
    }
    else if(n==0){
        long long n1=B[n];

        if(ab and af){
            n1+=(a[n]+a[n+1]);
            if(n1==b)
                return b;
        }
        else if(ab and !af){
            n1+=a[n];

            if(n1==b)
                return b;
        }
        else if(!ab and af){
            n1+=a[n+1];
            if(n1==b)
                return b;
        }
        else{
            if(n1==b)
                return b;
        }
    }
}
long long dp[10004][10];
int main() {
	//code
    int t;
    scanf(" %d",&t);
    while(t--)
    {
        a.clear();
        B.clear();
        scanf(" %lld",&N);
        long long A,b;
        for(long long i=0;i<N;++i){
            scanf(" %lld",&b);
            a.push_back(b);
        }
        for(long long i=0;i<N;++i){
            scanf(" %lld",&A);
            B.push_back(A);
        }
        if(N==1)
            printf("%lld\n",a[0]+B[0]);
        else
            printf("%lld\n",solve(B[N-1],N-1,true,true));
    }
	return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
