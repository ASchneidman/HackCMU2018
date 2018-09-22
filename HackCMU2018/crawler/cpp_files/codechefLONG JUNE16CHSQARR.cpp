<<<<<<< HEAD
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int arr[1001][1001];
int tpow[11],tlog[1001];
//int tableMax[1001][1001][10][10];

//calculating powers of 2
void pow2()
{
    tpow[0]=1;
    for(int i=1;i<=10;++i)
        tpow[i]=2*tpow[i-1];
}

//calculating log2 of numbers
void callog()
{
    for(int i=0;i<=1000;++i)
        tlog[i]=log2(i);
}
//sparse table storing minimum element in sub matrix info
/*
void MaxPreprocess(int n,int m)
{
    //long long cnt=0;
    int ik=tlog[n];
    int jk=tlog[m];
    for(int i=0;i<=ik;++i)
        for(int j=0;j<=jk;++j)
            for(int x=0;x+tpow[i]-1<n;++x)
                for(int y=0;y+tpow[j]-1<m;++y){
                       //cnt++;
                    if(i==0 and j==0)
                        tableMax[x][y][i][j]=arr[x][y];
                    else if(i==0){
                            //cout<<x<<" "<<y<<" "<<y + (1<<(j-1))<<" "<<i<<" "<<j<<endl;
                        tableMax[x][y][i][j]=max(tableMax[x][y][i][j-1] , tableMax[x][y + tpow[j-1]][i][j-1]);
                    }
                    else if(j==0)
                        tableMax[x][y][i][j]=max(tableMax[x][y][i-1][j] , tableMax[x + tpow[i-1]][y][i-1][j]);
                    else
                        tableMax[x][y][i][j]=max(tableMax[x][y][i-1][j-1] , max(tableMax[x + tpow[i-1]][y][i-1][j-1] , max(tableMax[x][y+tpow[j-1]][i-1][j-1], tableMax[x + tpow[i-1]][y+tpow[j-1]][i-1][j-1])));

                }
                //cout<<cnt;

}
*/
vector<vector<int> > tableMax[10][10];
void MaxPreprocess(int n,int m)
{
    //long long cnt=0;
    int ik=tlog[n];
    int jk=tlog[m];
    vector<int> v;
    for(int i=0;i<=ik;++i)
        for(int j=0;j<=jk;++j)
            for(int x=0;x+tpow[i]-1<n;++x){
                for(int y=0;y+tpow[j]-1<m;++y){
                       //cnt++;
                    if(i==0 and j==0)
                        v.push_back(arr[x][y]);
                    else if(i==0){
                        v.push_back(max(tableMax[i][j-1][x][y] , tableMax[i][j-1][x][y + tpow[j-1]]));
                            //cout<<x<<" "<<y<<" "<<y + (1<<(j-1))<<" "<<i<<" "<<j<<endl;
                    }
                    else if(j==0)
                        v.push_back(max(tableMax[i-1][j][x][y] , tableMax[i-1][j][x + tpow[i-1]][y]));
                    else
                        v.push_back(max(tableMax[i-1][j-1][x][y] , max(tableMax[i-1][j-1][x + tpow[i-1]][y] , max(tableMax[i-1][j-1][x][y + tpow[j-1]], tableMax[i-1][j-1][x + tpow[i-1]][y+tpow[j-1]]))));

                }
                (tableMax[i][j]).push_back(v);
                v.clear();

            }
                //cout<<cnt;

}
//getting maximum element
int MaxQuery(int x1, int y1, int x2, int y2)
{
    int k= tlog[x2 - x1 +1];
    int l= tlog[y2 - y1 +1];
    return max(tableMax[k][l][x1][y1], max(tableMax[k][l][x2 - tpow[k] + 1][y1], max(tableMax[k][l][x1][y2 - tpow[l] + 1], tableMax[k][l][x2 - tpow[k] + 1][y2 - tpow[l] + 1])));
}

// calculate sum of sub matrix
long long sat[1001][1001];
void satInit(int n,int m)
{
    for(int i=0;i<=n;++i)
        for(int j=0;j<=m;++j)
            if(i==0 or j==0)
                sat[i][j]=0;
            else
                sat[i][j]=arr[i-1][j-1]+sat[i-1][j]+sat[i][j-1]-sat[i-1][j-1];
}
int main()
{
    int n,m;
    pow2();
    scanf(" %d %d",&n,&m);
    //n=m=1000;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j){
        scanf(" %d",&arr[i][j]);
    //    arr[i][j]=1000;
        }
    callog();
    MaxPreprocess(n,m);
    //return 0;
    satInit(n,m);

    long long sum;
    int a,b,q,maxi;
    long long ans;
    scanf(" %d",&q);
    while(q--)
    {
        ans=LONG_LONG_MAX;

        scanf(" %d %d",&a,&b);

        for(int i=0;i<=n-a;++i)
        {
            for(int j=0;j<=m-b;++j)
            {
                sum=sat[i+a][j+b] + sat[i][j] - sat[i][j+b] - sat[i+a][j];      //sum of elements of sub matrix (i,j) - (i+a,j+b)
                maxi=MaxQuery(i,j,i+a-1,j+b-1); //getting maximum element of the sub matrix
                ans=min(a*b*maxi-sum,ans);
            }
        }
           //cout<<sum<<endl;
        printf("%lld\n",ans);
    }
	return 0;
}
=======
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int arr[1001][1001];
int tpow[11],tlog[1001];
//int tableMax[1001][1001][10][10];

//calculating powers of 2
void pow2()
{
    tpow[0]=1;
    for(int i=1;i<=10;++i)
        tpow[i]=2*tpow[i-1];
}

//calculating log2 of numbers
void callog()
{
    for(int i=0;i<=1000;++i)
        tlog[i]=log2(i);
}
//sparse table storing minimum element in sub matrix info
/*
void MaxPreprocess(int n,int m)
{
    //long long cnt=0;
    int ik=tlog[n];
    int jk=tlog[m];
    for(int i=0;i<=ik;++i)
        for(int j=0;j<=jk;++j)
            for(int x=0;x+tpow[i]-1<n;++x)
                for(int y=0;y+tpow[j]-1<m;++y){
                       //cnt++;
                    if(i==0 and j==0)
                        tableMax[x][y][i][j]=arr[x][y];
                    else if(i==0){
                            //cout<<x<<" "<<y<<" "<<y + (1<<(j-1))<<" "<<i<<" "<<j<<endl;
                        tableMax[x][y][i][j]=max(tableMax[x][y][i][j-1] , tableMax[x][y + tpow[j-1]][i][j-1]);
                    }
                    else if(j==0)
                        tableMax[x][y][i][j]=max(tableMax[x][y][i-1][j] , tableMax[x + tpow[i-1]][y][i-1][j]);
                    else
                        tableMax[x][y][i][j]=max(tableMax[x][y][i-1][j-1] , max(tableMax[x + tpow[i-1]][y][i-1][j-1] , max(tableMax[x][y+tpow[j-1]][i-1][j-1], tableMax[x + tpow[i-1]][y+tpow[j-1]][i-1][j-1])));

                }
                //cout<<cnt;

}
*/
vector<vector<int> > tableMax[10][10];
void MaxPreprocess(int n,int m)
{
    //long long cnt=0;
    int ik=tlog[n];
    int jk=tlog[m];
    vector<int> v;
    for(int i=0;i<=ik;++i)
        for(int j=0;j<=jk;++j)
            for(int x=0;x+tpow[i]-1<n;++x){
                for(int y=0;y+tpow[j]-1<m;++y){
                       //cnt++;
                    if(i==0 and j==0)
                        v.push_back(arr[x][y]);
                    else if(i==0){
                        v.push_back(max(tableMax[i][j-1][x][y] , tableMax[i][j-1][x][y + tpow[j-1]]));
                            //cout<<x<<" "<<y<<" "<<y + (1<<(j-1))<<" "<<i<<" "<<j<<endl;
                    }
                    else if(j==0)
                        v.push_back(max(tableMax[i-1][j][x][y] , tableMax[i-1][j][x + tpow[i-1]][y]));
                    else
                        v.push_back(max(tableMax[i-1][j-1][x][y] , max(tableMax[i-1][j-1][x + tpow[i-1]][y] , max(tableMax[i-1][j-1][x][y + tpow[j-1]], tableMax[i-1][j-1][x + tpow[i-1]][y+tpow[j-1]]))));

                }
                (tableMax[i][j]).push_back(v);
                v.clear();

            }
                //cout<<cnt;

}
//getting maximum element
int MaxQuery(int x1, int y1, int x2, int y2)
{
    int k= tlog[x2 - x1 +1];
    int l= tlog[y2 - y1 +1];
    return max(tableMax[k][l][x1][y1], max(tableMax[k][l][x2 - tpow[k] + 1][y1], max(tableMax[k][l][x1][y2 - tpow[l] + 1], tableMax[k][l][x2 - tpow[k] + 1][y2 - tpow[l] + 1])));
}

// calculate sum of sub matrix
long long sat[1001][1001];
void satInit(int n,int m)
{
    for(int i=0;i<=n;++i)
        for(int j=0;j<=m;++j)
            if(i==0 or j==0)
                sat[i][j]=0;
            else
                sat[i][j]=arr[i-1][j-1]+sat[i-1][j]+sat[i][j-1]-sat[i-1][j-1];
}
int main()
{
    int n,m;
    pow2();
    scanf(" %d %d",&n,&m);
    //n=m=1000;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j){
        scanf(" %d",&arr[i][j]);
    //    arr[i][j]=1000;
        }
    callog();
    MaxPreprocess(n,m);
    //return 0;
    satInit(n,m);

    long long sum;
    int a,b,q,maxi;
    long long ans;
    scanf(" %d",&q);
    while(q--)
    {
        ans=LONG_LONG_MAX;

        scanf(" %d %d",&a,&b);

        for(int i=0;i<=n-a;++i)
        {
            for(int j=0;j<=m-b;++j)
            {
                sum=sat[i+a][j+b] + sat[i][j] - sat[i][j+b] - sat[i+a][j];      //sum of elements of sub matrix (i,j) - (i+a,j+b)
                maxi=MaxQuery(i,j,i+a-1,j+b-1); //getting maximum element of the sub matrix
                ans=min(a*b*maxi-sum,ans);
            }
        }
           //cout<<sum<<endl;
        printf("%lld\n",ans);
    }
	return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
