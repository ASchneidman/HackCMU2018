<<<<<<< HEAD
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int lookup[100005][20];
int arr[100005];

void preprocess( int n)
{

    for (int i = 0; i < n; i++)
        lookup[i][0] = i;


    for (int j=1; (1<<j)<=n; j++)
    {
        for (int i=0; (i+(1<<j)-1) < n; i++)
        {
            if (arr[lookup[i][j-1]] < arr[lookup[i + (1<<(j-1))][j-1]])
                lookup[i][j] = lookup[i][j-1];
            else
                lookup[i][j] = lookup[i + (1 << (j-1))][j-1];
        }
    }
}

int query(int L, int R)
{

    int j = (int)log2(R-L+1);

    if (arr[lookup[L][j]] <= arr[lookup[R-(int)pow(2,j)+1][j]])
        return arr[lookup[L][j]];

   else return arr[lookup[R-(int)pow(2,j)+1][j]];
}
int main()
{
    long long n;
    scanf(" %lld",&n);
    for(long long i=0;i<n;++i)
        scanf(" %d",&arr[i]);
    preprocess(n);
    long long q;
    int l,r;
    scanf(" %lld",&q);
    while(q--)
    {
        scanf(" %d %d",&l,&r);
        printf("%d\n",query(l,r));
    }
	return 0;
}
=======
#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int lookup[100005][20];
int arr[100005];

void preprocess( int n)
{

    for (int i = 0; i < n; i++)
        lookup[i][0] = i;


    for (int j=1; (1<<j)<=n; j++)
    {
        for (int i=0; (i+(1<<j)-1) < n; i++)
        {
            if (arr[lookup[i][j-1]] < arr[lookup[i + (1<<(j-1))][j-1]])
                lookup[i][j] = lookup[i][j-1];
            else
                lookup[i][j] = lookup[i + (1 << (j-1))][j-1];
        }
    }
}

int query(int L, int R)
{

    int j = (int)log2(R-L+1);

    if (arr[lookup[L][j]] <= arr[lookup[R-(int)pow(2,j)+1][j]])
        return arr[lookup[L][j]];

   else return arr[lookup[R-(int)pow(2,j)+1][j]];
}
int main()
{
    long long n;
    scanf(" %lld",&n);
    for(long long i=0;i<n;++i)
        scanf(" %d",&arr[i]);
    preprocess(n);
    long long q;
    int l,r;
    scanf(" %lld",&q);
    while(q--)
    {
        scanf(" %d %d",&l,&r);
        printf("%d\n",query(l,r));
    }
	return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
