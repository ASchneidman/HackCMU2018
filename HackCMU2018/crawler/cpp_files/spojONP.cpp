#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
       string inp,out;
       cin>>inp;
       stack<char> s;
       for(int i=0;i<inp.length();++i)
       {
           if(inp[i]=='(')
                s.push(inp[i]);
           else if(inp[i]>=97 and inp[i]<=122)
            out=out+inp[i];
            else if(inp[i]=='^')
            {
                while(s.top()!='(')
                   {
                           if(s.top()=='*' || s.top()=='/'||s.top()=='+' || s.top()=='-' ||s.top()=='^')
                               {
                                   out=out+s.top();
                                   s.pop();
                               }
                           else
                               break;
                   }
                  s.push(inp[i]);
            }
            else if(inp[i]=='+' || inp[i]=='-')
                {
                   while(s.top()!='(')
                   {
                           if(s.top()=='*' || s.top()=='/'||s.top()=='+' || s.top()=='-')
                               {
                                   out=out+s.top();
                                   s.pop();
                               }
                           else
                               break;
                   }
                  s.push(inp[i]);
                 }
        else if(inp[i]=='*' || inp[i]=='/')
                {
                   while(s.top()!='(')
                   {
                           if(s.top()=='/' || s.top()=='*')
                               {
                                   out=out+s.top();
                                   s.pop();
                               }
                           else
                               break;
                   }
                  s.push(inp[i]);
                }
           else
           {
               while(s.top()!='(')
               {
                   out=out+s.top();
                   s.pop();
               }
               s.pop();

           }
          /* stack<char> temp=s;
           while(!temp.empty()){
            cout<<temp.top()<<" ";
            temp.pop();}
            cout<<endl<<out<<endl;*/
       }
       cout<<out<<endl;
    }

    return 0;
}
