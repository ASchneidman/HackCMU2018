#include <bits/stdc++.h>
using namespace std;


bool kmp(const string &needle, vector<char> haystack) {
  int m = needle.size();
  vector<int> border(m + 1);
  border[0] = -1;
  for (int i = 0; i < m; ++i) {
    border[i+1] = border[i];
    while (border[i+1] > -1 and needle[border[i+1]] != needle[i]) {
      border[i+1] = border[border[i+1]];
    }
    border[i+1]++;
  }
 
  int n = haystack.size();
  int seen = 0;
  for (int i = 0; i < n; ++i){
    while (seen > -1 and needle[seen] != haystack[i]) {
      seen = border[seen];
    }
    if (++seen == m) {
    	return true;
      //printf("%d\n", i - m + 1);
        seen = border[m]; 
    }
  }
  return false;
}
int a[100005];
int main()
{
  int t,n;
  ios::sync_with_stdio(false);
  cin>>t;
  vector<char> range;
  string pattern;
  while(t--)
  {
    range.clear();
    cin>>n;
    for(int i=0;i<n;++i)
    {
      cin>>a[i];
      if(i!=0)
      {
        if(a[i]>a[i-1])
          range.push_back('G');
        else if(a[i] == a[i-1])
          range.push_back('E');
        else
          range.push_back('L');
      }
    }
    cin>>pattern;

    if(kmp(pattern,range))
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;

  }
  return 0;

}