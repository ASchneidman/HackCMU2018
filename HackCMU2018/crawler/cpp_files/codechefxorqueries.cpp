#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    unsigned long a[500005],m,x,l,r,i=0,j,maxor,k,b[500005],c,y,freq,ind;
    int q;
    cin>>m;
    while(m--)
    {


    cin>>q;
    switch(q)
    {
    case 0:
       cin>>x;
       a[i++]=x;
       break;
    case 1:
        cin>>l>>r>>x;
        l--;r--;
        y=a[l];
        maxor=y^x;
        for(j=l+1;j<=r;++j)
            if(maxor<a[i]^x)
            {
              y=a[i];
              maxor=y^x;
            }
        cout<<y<<endl;
        break;
    case 2:
        cin>>k;
        i=i-k;
        break;
    case 3:
        cin>>l>>r>>x;
        l--;r--;
        freq=0;
        for(j=l;j<=r;++j)
            if(a[j]<=x)
                freq++;
        cout<<freq<<endl;
        break;
    case 4:
        cin>>l>>r>>k;
        l--;r--;
        for(j=l,c=0;j<=r;++j,++c)
            b[c]=a[j];
        sort(b,b+c);
        for(j=0;j<c;++j)
        {
            if(b[j]=b[j+1])
                continue;
            else
                ind++;
            if(ind==k)
            {

             cout<<b[k]<<endl;
             break;;
        }

        }
    }
}
return 0;
}
