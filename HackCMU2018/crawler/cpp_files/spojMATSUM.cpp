#include<bits/stdc++.h>
using namespace std;
int tree[1030][1030],temp[1030][1030],n;
void setmat(int x,int y,int val)
{
    int yt;
    while(x<=n)
    {
        yt=y;
        while(yt<=n)
        {
            tree[x][yt]+=val;
            yt+=(yt & (-yt));
        }
        x+=(x & (-x));
    }

}
int submat(int x,int y)
{
        int yt;
        int sum=0;
        while(x>0)
        {
            yt=y;
            while(yt>0)
            {
                sum+=tree[x][yt];
                yt-=(yt&-yt);
            }
            x-=(x&-x);
        }
        return sum;
}
int main() {

   int t;
   scanf("%d",&t);
   while(t--)
   {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				tree[i][j]=temp[i][j]=0;
        char ch[5];
        int x,y,num,a,b;
        while(1)
        {
            scanf(" %s",ch);
            if(ch[0]=='E')
                break;
            if(ch[2]=='T')
            {
                scanf(" %d %d %d",&x,&y,&num);
                if(temp[x+1][y+1]!=num)
                {
                setmat(x+1,y+1,num-temp[x+1][y+1]);
                temp[x+1][y+1]=num;
                }
            }
            else
            {
                scanf("%d %d %d %d",&x,&y,&a,&b);
                int ans=submat(a+1,b+1)-submat(a+1,y)-submat(x,b+1)+submat(x,y);
                printf("%d\n",ans);
            }
        }

   }
    return 0;
}
