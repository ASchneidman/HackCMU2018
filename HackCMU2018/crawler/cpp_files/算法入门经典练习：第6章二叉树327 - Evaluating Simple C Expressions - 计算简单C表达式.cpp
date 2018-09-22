#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

struct Type {
	char num; int after, pre;
	bool operator < (const Type& x) const {
		return num < x.num;
	}
};

void skipSpace(string& s)
{
	int i = s.size();
	while (--i >= 0)
		if (isspace(s[i]))
			s.erase(s.begin()+i);
}

int extract(string& s, int& cnt, Type* v)
{
	int i = 0, first = 1, value;
	while (true)
	{
		while (!isalpha(s[i]) && ++i)
			if (!(i < s.size())) return value;
		v[cnt].num = s[i];
		if (i>1 && s[i-1]==s[i-2])
			v[cnt].pre = (s[i-1]=='+' ? 1 : -1);
		if (i+2<s.size() && s[i+1] == s[i+2])
			v[cnt].after = (s[i+1]=='+' ? 1 : -1);
		int temp = v[cnt].num + v[cnt].pre -'a'+1;
		if (first) { first = 0; value = temp; }
		else if(s[s[i-1]==s[i-2]?i-3:i-1] == '+')
			value += temp;
		else value -= temp;
		++cnt; ++i;
	}
	return value;
}

int main()
{
	string line;
	while (getline(cin, line))
	{
		int cnt = 0;
		Type v[60] = {0};
		cout << "Expression: " << line << endl;
		skipSpace(line);
		cout << "    value = " << extract(line, cnt, v) << endl;
		sort(v, v+cnt);
		for (int i=0; i<cnt; ++i)
			cout << "    " << v[i].num << " = "
			<< v[i].num+v[i].pre+v[i].after-'a'+1 << endl;
	}
	return 0;
}
