<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

long long grid[102][102];
long long bot1[102][102],bot2[102][102];
long long n,m;
long long t,k1,k2;
void fillSE(long long bot[][102],long long x,long long y,long long dist,long long k){
    long long row=k;

    for(long long i=x;i<=x+k;++i){
        for(long long j=y;j<=y+row;++j){

            if(i>n or j>m)
                continue;
            if(grid[i][j]==0){
                bot[i][j]=min(bot[i][j],dist+1);
            }
        }
        row--;

    }

}
void fillSW(long long bot[][102],long long x,long long y,long long dist,long long k){
    long long row=k;

    for(long long i=x;i<=x+k;++i){
        for(long long j=y;j>=y-row;--j){

            if(i>n or j<1)
                continue;
            if(grid[i][j]==0){

                bot[i][j]=min(bot[i][j],dist+1);
            }
        }
        row--;
    }
}
void fillNE(long long bot[][102],long long x,long long y,long long dist,long long k){
    long long row=k;

    for(long long i=x;i>=x-k;--i){
        for(long long j=y;j<=y+row;++j){
            if(i<1 or j>m)
                continue;

            if(grid[i][j]==0){
                bot[i][j]=min(bot[i][j],dist+1);

            }
        }
        row--;
    }
}
void fillNW(long long bot[][102],long long x,long long y,long long dist,long long k){
    long long row=k;

    for(long long i=x;i>=x-k;--i){
        for(long long j=y;j>=y-row;--j){
            if(i<1 or j<1)
                continue;

            if(grid[i][j]==0){
                bot[i][j]=min(bot[i][j],dist+1);

            }
        }
        row--;
    }
}
int main()
{

    scanf(" %lld",&t);
    //t=10;
    while(t--)
    {
        scanf(" %lld %lld %lld %lld",&n,&m,&k1,&k2);
        //n=m=100;
        //k1=k2=10;
        for(long long i=1;i<=n;++i)
            for(long long j=1;j<=m;++j){
                scanf(" %lld",&grid[i][j]);
                //grid[i][j]=0;
             bot1[i][j]=bot2[i][j]=INT_MAX;
            }

        bot1[1][1]=0;
        for(int x=0;x<5;++x){
        for(long long i=1;i<=n;++i)
            for(long long j=1;j<=m;++j)
                if(grid[i][j]==0)
                fillSE(bot1,i,j,bot1[i][j],k1);

        for(long long i=n;i>0;--i)
            for(long long j=1;j<=m;++j)
                if(grid[i][j]==0)
                fillNE(bot1,i,j,bot1[i][j],k1);

        for(long long i=n;i>0;--i)
            for(long long j=m;j>0;--j)
                if(grid[i][j]==0)
                fillNW(bot1,i,j,bot1[i][j],k1);

        for(long long i=1;i<=n;++i)
            for(long long j=m;j>0;--j)
                if(grid[i][j]==0)
                fillSW(bot1,i,j,bot1[i][j],k1);
        }
        bot2[1][m]=0;
        for(int x=0;x<5;++x){
        for(long long i=1;i<=n;++i)
            for(long long j=m;j>0;--j)
                if(grid[i][j]==0)
                fillSW(bot2,i,j,bot2[i][j],k2);


        for(long long i=n;i>0;--i)
            for(long long j=m;j>0;--j)
                if(grid[i][j]==0)
                fillNW(bot2,i,j,bot2[i][j],k2);


        for(long long i=n;i>0;--i)
            for(long long j=1;j<=m;++j)
                if(grid[i][j]==0)
                fillNE(bot2,i,j,bot2[i][j],k2);

        for(long long i=1;i<=n;++i)
            for(long long j=1;j<=m;++j)
                if(grid[i][j]==0)
                fillSE(bot2,i,j,bot2[i][j],k2);
        }
/*
        for(long long i=1;i<=n;++i){
            for(long long j=1;j<=m;++j)
                if(bot1[i][j]==INT_MAX)
                    cout<<"-";
                else
                    cout<<bot1[i][j];
                cout<<endl;
        }
        }
        for(long long i=1;i<=n;++i){
            for(long long j=1;j<=m;++j)
                if(bot2[i][j]==INT_MAX)
                    cout<<"-";
                else
                    cout<<bot2[i][j];
                cout<<endl;
        }
        */
        long long ans=INT_MAX,cell;
        for(long long i=1;i<=n;++i){
            for(long long j=1;j<=m;++j){
                cell=max(bot1[i][j],bot2[i][j]);
                ans=min(ans,cell);
            }
        }

        if(ans==INT_MAX)
            printf("-1\n");
        else
            printf("%lld\n",ans);

    }
	return 0;
}
=======
#include <bits/stdc++.h>
using namespace std;

long long grid[102][102];
long long bot1[102][102],bot2[102][102];
long long n,m;
long long t,k1,k2;
void fillSE(long long bot[][102],long long x,long long y,long long dist,long long k){
    long long row=k;

    for(long long i=x;i<=x+k;++i){
        for(long long j=y;j<=y+row;++j){

            if(i>n or j>m)
                continue;
            if(grid[i][j]==0){
                bot[i][j]=min(bot[i][j],dist+1);
            }
        }
        row--;

    }

}
void fillSW(long long bot[][102],long long x,long long y,long long dist,long long k){
    long long row=k;

    for(long long i=x;i<=x+k;++i){
        for(long long j=y;j>=y-row;--j){

            if(i>n or j<1)
                continue;
            if(grid[i][j]==0){

                bot[i][j]=min(bot[i][j],dist+1);
            }
        }
        row--;
    }
}
void fillNE(long long bot[][102],long long x,long long y,long long dist,long long k){
    long long row=k;

    for(long long i=x;i>=x-k;--i){
        for(long long j=y;j<=y+row;++j){
            if(i<1 or j>m)
                continue;

            if(grid[i][j]==0){
                bot[i][j]=min(bot[i][j],dist+1);

            }
        }
        row--;
    }
}
void fillNW(long long bot[][102],long long x,long long y,long long dist,long long k){
    long long row=k;

    for(long long i=x;i>=x-k;--i){
        for(long long j=y;j>=y-row;--j){
            if(i<1 or j<1)
                continue;

            if(grid[i][j]==0){
                bot[i][j]=min(bot[i][j],dist+1);

            }
        }
        row--;
    }
}
int main()
{

    scanf(" %lld",&t);
    //t=10;
    while(t--)
    {
        scanf(" %lld %lld %lld %lld",&n,&m,&k1,&k2);
        //n=m=100;
        //k1=k2=10;
        for(long long i=1;i<=n;++i)
            for(long long j=1;j<=m;++j){
                scanf(" %lld",&grid[i][j]);
                //grid[i][j]=0;
             bot1[i][j]=bot2[i][j]=INT_MAX;
            }

        bot1[1][1]=0;
        for(int x=0;x<5;++x){
        for(long long i=1;i<=n;++i)
            for(long long j=1;j<=m;++j)
                if(grid[i][j]==0)
                fillSE(bot1,i,j,bot1[i][j],k1);

        for(long long i=n;i>0;--i)
            for(long long j=1;j<=m;++j)
                if(grid[i][j]==0)
                fillNE(bot1,i,j,bot1[i][j],k1);

        for(long long i=n;i>0;--i)
            for(long long j=m;j>0;--j)
                if(grid[i][j]==0)
                fillNW(bot1,i,j,bot1[i][j],k1);

        for(long long i=1;i<=n;++i)
            for(long long j=m;j>0;--j)
                if(grid[i][j]==0)
                fillSW(bot1,i,j,bot1[i][j],k1);
        }
        bot2[1][m]=0;
        for(int x=0;x<5;++x){
        for(long long i=1;i<=n;++i)
            for(long long j=m;j>0;--j)
                if(grid[i][j]==0)
                fillSW(bot2,i,j,bot2[i][j],k2);


        for(long long i=n;i>0;--i)
            for(long long j=m;j>0;--j)
                if(grid[i][j]==0)
                fillNW(bot2,i,j,bot2[i][j],k2);


        for(long long i=n;i>0;--i)
            for(long long j=1;j<=m;++j)
                if(grid[i][j]==0)
                fillNE(bot2,i,j,bot2[i][j],k2);

        for(long long i=1;i<=n;++i)
            for(long long j=1;j<=m;++j)
                if(grid[i][j]==0)
                fillSE(bot2,i,j,bot2[i][j],k2);
        }
/*
        for(long long i=1;i<=n;++i){
            for(long long j=1;j<=m;++j)
                if(bot1[i][j]==INT_MAX)
                    cout<<"-";
                else
                    cout<<bot1[i][j];
                cout<<endl;
        }
        }
        for(long long i=1;i<=n;++i){
            for(long long j=1;j<=m;++j)
                if(bot2[i][j]==INT_MAX)
                    cout<<"-";
                else
                    cout<<bot2[i][j];
                cout<<endl;
        }
        */
        long long ans=INT_MAX,cell;
        for(long long i=1;i<=n;++i){
            for(long long j=1;j<=m;++j){
                cell=max(bot1[i][j],bot2[i][j]);
                ans=min(ans,cell);
            }
        }

        if(ans==INT_MAX)
            printf("-1\n");
        else
            printf("%lld\n",ans);

    }
	return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
