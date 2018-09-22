#include <bits/stdc++.h>
using namespace std;


vector<int> kmp(const string &needle, const string &haystack) {
  int m = needle.size();
  vector<int> border(m + 1);
  vector<int> pos;
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
    	pos.push_back(i-m+1);
      //printf("%d\n", i - m + 1);
        seen = border[m]; 
    }
  }
  return pos;
}
int main()
{
	int t;
	ios::sync_with_stdio(false);
	cin>>t;
	string text,pattern;
	while(t--)
	{
		cin>>text>>pattern;
		vector<int> match = kmp(pattern,text);
		if(match.size() == 0)
			cout<<"Not Found"<<endl;
		else
		{
			cout<<match.size()<<endl;
			for(int i=0;i<match.size();++i)
				cout<<match[i]+1<<" ";
			cout<<endl;
		}
	}
	return 0;
}