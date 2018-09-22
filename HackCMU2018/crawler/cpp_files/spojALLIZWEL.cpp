#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
vector<string> mat;
bool visit[105][105];
int r,c;
char test[]="ALLIZZWELL";
bool check(int a,int b,int l)
{
    if(l==10)
        return true;
    visit[a][b]=true;
    for(int i=-1;i<=1;++i)
        for(int j=-1;j<=1;++j)
    {
        if(i==0 and j==0)
            continue;
        int row=a+i,col=b+j;
        if(row<0 or col<0 or row>=r or col>=c or mat[row][col]!=test[l])
            continue;
        if(visit[row][col])
            continue;
        if(check(row,col,l+1))
        {
            visit[a][b]=false;
            return true;
        }
    }
    visit[a][b]=false;
    return false;
}
int main() {

    int t;
    scanf("%d",&t);
    while(t--)
    {
        mat.clear();
        string s;
        scanf("%d %d",&r,&c);
        for(int i=0;i<r;++i)
        {
            cin>>s;
            mat.push_back(s);
        }
        bool flag=false;
        for(int i=0;i<r;++i)
            for(int j=0;j<c;++j)
                if(mat[i][j]=='A' and check(i,j,1))
        {
            flag=true;
            break;
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
