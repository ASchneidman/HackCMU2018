<<<<<<< HEAD
#include<bits/stdc++.h>
#define prec 1.0/100000000000
using namespace std;
long long c[102];
int m;
double findVal(double r){
    double ans=0;
    for(int i=0;i<=m;++i)
        if(i==0)
            ans=ans-c[i]*pow(1+r,m-i);
        else
            ans=ans+c[i]*pow(1+r,m-i);
    return ans;
}
int main(){
	int t;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	double ans;
	for(int Case=1;Case<=t;++Case){
        ans=0;
        scanf(" %d",&m);
        for(int i=0;i<=m;++i)
            scanf(" %lld",&c[i]);
        double l=-1,r=1,mid,val;
        int cnt=0;
        while(l<=r){
            mid=(l+r)/2;
            val=findVal(mid);
            //printf(" %.10f  : %.10f",val,mid);
            //if(mid==0)
              //  break;
            if(val<=0)
                r=mid;
            else
                l=mid;

            cnt++;
            if(cnt==303)
                break;
        }
		printf("Case #%d: %.12lf\n",Case,l+prec);
	}
	return 0;
}
=======
#include<bits/stdc++.h>
#define prec 1.0/100000000000
using namespace std;
long long c[102];
int m;
double findVal(double r){
    double ans=0;
    for(int i=0;i<=m;++i)
        if(i==0)
            ans=ans-c[i]*pow(1+r,m-i);
        else
            ans=ans+c[i]*pow(1+r,m-i);
    return ans;
}
int main(){
	int t;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	double ans;
	for(int Case=1;Case<=t;++Case){
        ans=0;
        scanf(" %d",&m);
        for(int i=0;i<=m;++i)
            scanf(" %lld",&c[i]);
        double l=-1,r=1,mid,val;
        int cnt=0;
        while(l<=r){
            mid=(l+r)/2;
            val=findVal(mid);
            //printf(" %.10f  : %.10f",val,mid);
            //if(mid==0)
              //  break;
            if(val<=0)
                r=mid;
            else
                l=mid;

            cnt++;
            if(cnt==303)
                break;
        }
		printf("Case #%d: %.12lf\n",Case,l+prec);
	}
	return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
