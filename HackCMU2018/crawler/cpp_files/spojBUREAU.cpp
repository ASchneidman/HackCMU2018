#include<bits/stdc++.h>
using namespace std;
bool law[100003];
int can[100003];
int nextint(){
	char r;
	bool start=false,neg=false;
    int ret=0;
	while(true){
		r=getchar();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){
			break;
		}
		if(start)ret*=10;
		start=true;
		if(r=='-')neg=true;
		else ret+=r-'0';
	}
	if(!neg)
		return ret;
	else
		return -ret;
}
int main(){
    int t,n,x;
    t=nextint();
    char str[50];
    while(t--)
    {
        //fill(law,law+100003,true);
        n=nextint();
        law[0]=false;
        for(int i=1;i<=n;++i)
        {
            scanf(" %s",str);
            law[i]=true;
            if(str[0]=='c')
                    can[i]=nextint();
            else
                can[i]=0;
        }
        for(int i=n;i>0;--i)
            if(can[i] and law[i])
                law[can[i]]=false;
        int ans=count(law,law+n+1,true);
        printf("%d\n",ans);
        for(int i=1;i<=n;++i)
            if(law[i])
                printf("%d ",i);
        printf("\n");

    }
    return 0;
}
