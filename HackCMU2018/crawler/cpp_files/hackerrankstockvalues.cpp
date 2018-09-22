#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int n;
int getstock(vector<int> val)
{
    int stock=0;
    for(int i=1;i<=n/2;++i)
        stock=stock+(abs(val[i]-val[n-i+1]));
    return stock;
}

int max_stock(vector<int> val,int i,int j)
{
    vector<int> v=val;
    if(i==j)
    {
        return getstock(val);
    }
    bool flag=false;
    if(v[i-1]%2==0 and v[i+1]%2==0){flag=true;
            v[i]=(v[i-1]+v[i+1])/2;}
    //for(int i=1;i<=n;++i)
      //  printf("%d ",v[i]);
    //printf("\n");
    if(flag)
        return max(max_stock(val,i+1,j),max_stock(v,i+1,j));
    else
        return max_stock(val,i+1,j);
}
int main() {
   int t;
   scanf("%d",&t);

   while(t--)
   {
       vector<int> val;
       scanf("%d",&n);
       int va;
       val.push_back(0);
       for(int i=1;i<=n;++i)
       {
            scanf("%d",&va);
            val.push_back(va);
       }
       int ans=max_stock(val,2,n);
        printf("%d\n",ans);


   }
    return 0;
}
