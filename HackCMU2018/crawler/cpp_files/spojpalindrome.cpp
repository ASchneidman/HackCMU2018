#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string ToStr( char c ) {
   return string( 1, c );
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t,n,b;
    cin>>t;
    while(t--)
    {

       cin>>n;
       b=2;
       while(1)
       {

       string check;
       int num,i,rem;
       num=n;
       i=0;
       char ch;
       while(num>0)
       {
           rem=num%b;
           if(rem<10)
                ch=rem+48;
           else
            ch=87+rem;

           check.insert(i,ToStr(ch));
           num=num/b;
           i++;
       }
       //cout<<check<<endl;
       if(check==string(check.rbegin(),check.rend()))
       {
           cout<<b<<endl;
           break;
       }
       b++;


    }
    }
    return 0;
}
