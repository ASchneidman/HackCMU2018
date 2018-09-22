#include<bits/stdc++.h>
using namespace std;
int n,a[100];
void max_heapify(int a[],int i)
{
    int left=2*i,right=2*i+1,largest=i;
    if(left<=n and a[left]>a[largest])
        largest=left;
    if(right<=n and a[right]>a[largest])
        largest=right;
    if(largest!=i)
    {
        swap(a[largest],a[i]);
        max_heapify(a,largest);
    }
}
void build_heap(int a[])
{
    for(int i=n/2;i>0;--i)
        max_heapify(a,i);
}
void delete_heap(int a[],int d)
{
    int pos;
    for(int i=1;i<=n;++i)
        if(a[i]==d)
    {
        pos=i;
        break;
    }
    swap(a[pos],a[n]);
    n--;
    max_heapify(a,pos);
}
void insert_heap(int a[],int d)
{
    a[++n]=d;
    build_heap(a);
}
void display(int a[])
{
    int j,lev=0;
    bool flag=true;
    while(flag)
    {
        j=pow(2,lev);
        while(j<pow(2,lev+1))
        {
            printf("%d ",a[j++]);
            if(j>n)
            {
                flag=false;
                break;
            }
        }
        printf("\n");
        lev++;
    }
    printf("\n");
    for(int i=1;i<=n;++i)
        printf("%d ",a[i]);
}
int main(){
    bool flag=true;
    int ch;
    while(flag)
    {
        printf("\n 1.insert\n 2.delete \n 3.display\n 4.exit \n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            scanf("%d",&ch);
            insert_heap(a,ch);
            break;
        case 2:
            scanf("%d",&ch);
            delete_heap(a,ch);
            break;
        case 3:
            display(a);
            break;
        case 4:
            flag=false;
            break;
        }
    }
    return 0;
}
