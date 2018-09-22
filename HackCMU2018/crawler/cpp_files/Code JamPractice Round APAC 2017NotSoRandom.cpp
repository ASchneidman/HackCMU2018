<<<<<<< HEAD
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
map<long long,double>m;
map<long long,double>temp;
int main()
{

    int t;

    ios::sync_with_stdio(false);
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>t;
    long long n,k,x;
    double ans;
    double a,b,c;
    long long AND,OR,XOR;
    for(int Case=1;Case<=t;++Case)
    {
        cin>>n>>x>>k>>a>>b>>c;
        m.clear();
        temp.clear();
        map<long long,double>::iterator it;
        for(int i=0;i<n;++i)
        {
            if(i==0){
                AND=x & k;
                OR=x | k;
                XOR=x ^ k;
                //cout<<AND<<" "<<OR<<" "<<XOR;
                m[AND]=m[OR]=m[XOR]=0;
                m[AND]+=(a/100);
                m[OR]+=(b/100);
                m[XOR]+=(c/100);

            }
            else{

                for(it=m.begin();it!=m.end();++it){
                    x=it->first;
                    AND=x & k;
                    OR=x | k;
                    XOR=x ^ k;
                    if(temp.find(AND)==temp.end())
                        temp[AND]=(a/100)*(it->second);
                    else
                        temp[AND]+=(a/100*(it->second));
                    if(temp.find(OR)==temp.end())
                        temp[OR]=(b/100)*(it->second);
                    else
                        temp[OR]+=((b/100)*(it->second));
                    if(temp.find(XOR)==temp.end())
                        temp[XOR]=(c/100)*(it->second);
                    else
                        temp[XOR]+=((c/100)*(it->second));


                }
                m.clear();
                m=temp;
                temp.clear();

            }
        }
        ans=0;
        for(it=m.begin();it!=m.end();++it){
            ans=ans+((it->first) * (it->second));
            //cout<<it->first<<" "<<it->second<<endl;
        }
        //cout<<"Case #"<<Case<<": "<<ans<<endl;
        printf("Case #%d: %.10lf\n",Case,ans);
    }

	return 0;
}
=======
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
map<long long,double>m;
map<long long,double>temp;
int main()
{

    int t;

    ios::sync_with_stdio(false);
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>t;
    long long n,k,x;
    double ans;
    double a,b,c;
    long long AND,OR,XOR;
    for(int Case=1;Case<=t;++Case)
    {
        cin>>n>>x>>k>>a>>b>>c;
        m.clear();
        temp.clear();
        map<long long,double>::iterator it;
        for(int i=0;i<n;++i)
        {
            if(i==0){
                AND=x & k;
                OR=x | k;
                XOR=x ^ k;
                //cout<<AND<<" "<<OR<<" "<<XOR;
                m[AND]=m[OR]=m[XOR]=0;
                m[AND]+=(a/100);
                m[OR]+=(b/100);
                m[XOR]+=(c/100);

            }
            else{

                for(it=m.begin();it!=m.end();++it){
                    x=it->first;
                    AND=x & k;
                    OR=x | k;
                    XOR=x ^ k;
                    if(temp.find(AND)==temp.end())
                        temp[AND]=(a/100)*(it->second);
                    else
                        temp[AND]+=(a/100*(it->second));
                    if(temp.find(OR)==temp.end())
                        temp[OR]=(b/100)*(it->second);
                    else
                        temp[OR]+=((b/100)*(it->second));
                    if(temp.find(XOR)==temp.end())
                        temp[XOR]=(c/100)*(it->second);
                    else
                        temp[XOR]+=((c/100)*(it->second));


                }
                m.clear();
                m=temp;
                temp.clear();

            }
        }
        ans=0;
        for(it=m.begin();it!=m.end();++it){
            ans=ans+((it->first) * (it->second));
            //cout<<it->first<<" "<<it->second<<endl;
        }
        //cout<<"Case #"<<Case<<": "<<ans<<endl;
        printf("Case #%d: %.10lf\n",Case,ans);
    }

	return 0;
}
>>>>>>> 1cef6792d706b1e8b7eab9954b86478c9c79e871
