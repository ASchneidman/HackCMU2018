<<<<<<< HEAD
#include<bits/stdc++.h>
#define mod 1000000007
#define prec 1.0/1000000000
using namespace std;
vector<long long>v[100005];
void calfact(long long n)
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=sqrt(i);++j)
			if(i%j==0){
                if(j*j==i)
                    v[i].push_back(j);
                else{
                    v[i].push_back(j);
                    v[i].push_back(i/j);
                }
			}
}

long long degree(long long a, long long k,long long m) {
  long long res = 1;
  long long cur = a;

  while (k) {
    if (k % 2) {
      res = (res * cur) % m;
    }
    k /= 2;
    cur = (cur * cur) % m;
  }
  return res;
}


long long F[100005],R[100005];
class FirstDig
{
    public:
    long long fx;   //floor of x
    double fractX;  //fractional part of x

    void calFirstDig()
    {
        fx=fractX=0;
    }
    void calculate(long long a,int ch)
    {
        if(ch==0)
        {
            double x=fx+fractX+log10(a)+prec;
            fx=floor(x);
            fractX=x-fx;

        }
        else
        {
            double x=fx+fractX-log10(a)+prec;
            fx=floor(x);
            fractX=x-fx;
        }
    }
    int getFirstDig()
    {
        double num=pow(10,fractX);
        int fdig=floor(num);
        return fdig;
    }

};
FirstDig *fR=new FirstDig[100005];
int main()
{

    long long n,q,r,p,f;
    scanf(" %lld",&n);
    for(long long i=0;i<n;++i)
        scanf(" %lld",&F[i]);
    calfact(n);
    for(long long i=0;i<n;++i)
    {   R[i]=1;
        fR[i].calculate(1,0);
    }
    fR[0].calculate(F[0],0);
    for(long long i=1;i<n;++i)
    {
            for(long long j=0;j<v[i].size();++j)
         {
             R[v[i][j]]*=F[i];
             fR[v[i][j]].calculate(F[i],0);
             //printf("%d\n",fR[1].getFirstDig());
             if(R[v[i][j]]>=mod)
                R[v[i][j]]%=mod;
         }
    }
    /*for(long long i=1;i<n;++i)
        printf("%lld ",R[i]);
    cout<<endl;*/
    scanf(" %lld",&q);
    int ch;
    int fdigit;
    double num,fractX,x;
    while(q--)
    {
        scanf(" %d",&ch);
        if(ch==1)
        {
            scanf(" %lld %lld",&p,&f);
            p--;
            if(p!=0){
                for(long long i=0;i<v[p].size();++i)
                {
                    R[v[p][i]]=(R[v[p][i]]*degree(F[p],mod-2,mod))%mod;
                    //if(R[*it]>=mod)
                      //  R[*it]%=mod;
                    R[v[p][i]]=(R[v[p][i]]*f)%mod;
                    //if(R[*it]>=mod)
                      //  R[*it]%=mod;
                    fR[v[p][i]].calculate(f,0);
                    fR[v[p][i]].calculate(F[p],1);

                }
                F[p]=f;
            }
            else{
                fR[p].calculate(F[p],1);
                F[p]=f;
                fR[p].calculate(F[p],0);

            }

        }
        else
        {
            scanf(" %lld",&r);
            if(r==n)
                printf("%d %lld\n",fR[0].getFirstDig(),F[0]);
            else{
                 /*x=fR[r].fx+fR[r].fractX+log10(F[0]);
                 fractX=x-floor(x);
                 num=pow(10,fractX);
                fdigit=floor(num);*/

                fR[r].calculate(F[0],0);
                printf("%d %lld\n",fR[r].getFirstDig(),(R[r]*F[0])%mod);
                fR[r].calculate(F[0],1);
            }

        }
        //cout<<fR[2].fx<<" "<<fR[2].fractX<<" "<<fR[2].getNum()<<" "<<fR[2].getFirstDig()<<endl;
    }

	return 0;
}
=======
#include<bits/stdc++.h>
#define mod 1000000007
#define prec 1.0/1000000000
using namespace std;
vector<long long>v[100005];
void calfact(long long n)
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=sqrt(i);++j)
			if(i%j==0){
                if(j*j==i)
                    v[i].push_back(j);
                else{
                    v[i].push_back(j);
                    v[i].push_back(i/j);
                }
			}
}

long long degree(long long a, long long k,long long m) {
  long long res = 1;
  long long cur = a;

  while (k) {
    if (k % 2) {
      res = (res * cur) % m;
    }
    k /= 2;
    cur = (cur * cur) % m;
  }
  return res;
}


long long F[100005],R[100005];
class FirstDig
{
    public:
    long long fx;   //floor of x
    double fractX;  //fractional part of x

    void calFirstDig()
    {
        fx=fractX=0;
    }
    void calculate(long long a,int ch)
    {
        if(ch==0)
        {
            double x=fx+fractX+log10(a)+prec;
            fx=floor(x);
            fractX=x-fx;

        }
        else
        {
            double x=fx+fractX-log10(a)+prec;
            fx=floor(x);
            fractX=x-fx;
        }
    }
    int getFirstDig()
    {
        double num=pow(10,fractX);
        int fdig=floor(num);
        return fdig;
    }

};
FirstDig *fR=new FirstDig[100005];
int main()
{

    long long n,q,r,p,f;
    scanf(" %lld",&n);
    for(long long i=0;i<n;++i)
        scanf(" %lld",&F[i]);
    calfact(n);
    for(long long i=0;i<n;++i)
    {   R[i]=1;
        fR[i].calculate(1,0);
    }
    fR[0].calculate(F[0],0);
    for(long long i=1;i<n;++i)
    {
            for(long long j=0;j<v[i].size();++j)
         {
             R[v[i][j]]*=F[i];
             fR[v[i][j]].calculate(F[i],0);
             //printf("%d\n",fR[1].getFirstDig());
             if(R[v[i][j]]>=mod)
                R[v[i][j]]%=mod;
         }
    }
    /*for(long long i=1;i<n;++i)
        printf("%lld ",R[i]);
    cout<<endl;*/
    scanf(" %lld",&q);
    int ch;
    int fdigit;
    double num,fractX,x;
    while(q--)
    {
        scanf(" %d",&ch);
        if(ch==1)
        {
            scanf(" %lld %lld",&p,&f);
            p--;
            if(p!=0){
                for(long long i=0;i<v[p].size();++i)
                {
                    R[v[p][i]]=(R[v[p][i]]*degree(F[p],mod-2,mod))%mod;
                    //if(R[*it]>=mod)
                      //  R[*it]%=mod;
                    R[v[p][i]]=(R[v[p][i]]*f)%mod;
                    //if(R[*it]>=mod)
                      //  R[*it]%=mod;
                    fR[v[p][i]].calculate(f,0);
                    fR[v[p][i]].calculate(F[p],1);

                }
                F[p]=f;
            }
            else{
                fR[p].calculate(F[p],1);
                F[p]=f;
                fR[p].calculate(F[p],0);

            }

        }
        else
        {
            scanf(" %lld",&r);
            if(r==n)
                printf("%d %lld\n",fR[0].getFirstDig(),F[0]);
            else{
                 /*x=fR[r].fx+fR[r].fractX+log10(F[0]);
                 fractX=x-floor(x);
                 num=pow(10,fractX);
                fdigit=floor(num);*/

                fR[r].calculate(F[0],0);
                printf("%d %lld\n",fR[r].getFirstDig(),(R[r]*F[0])%mod);
                fR[r].calculate(F[0],1);
            }

        }
        //cout<<fR[2].fx<<" "<<fR[2].fractX<<" "<<fR[2].getNum()<<" "<<fR[2].getFirstDig()<<endl;
    }

	return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
