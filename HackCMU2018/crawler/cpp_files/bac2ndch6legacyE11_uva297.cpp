#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int build_tree1(int p, string& s) {
	if (s[0] == 'e') {
		s = s.substr(1, s.size()-1);
		return 0;
	} else if (s[0] == 'f') {
		s = s.substr(1, s.size()-1);
		return p;
	} else if (s[0] == 'p') {
		int sum = 0;
		s = s.substr(1, s.size()-1);
		sum += build_tree1(p/4, s);
		sum += build_tree1(p/4, s);
		sum += build_tree1(p/4, s);
		sum += build_tree1(p/4, s);
		return sum;
	}
}

int build_tree2(int p, string& s1, string& s2) {
	char ch1 = s1[0], ch2 =  s2[0];
	s1 = s1.substr(1, s1.size()-1);
	s2 = s2.substr(1, s2.size()-1);
	if (ch1 == 'p' && ch2 == 'p') {
		int sum = 0;
		sum += build_tree2(p/4, s1, s2);
		sum += build_tree2(p/4, s1, s2);
		sum += build_tree2(p/4, s1, s2);
		sum += build_tree2(p/4, s1, s2);
		return sum;
	} else if (ch1 <= 'f' && ch2 <= 'f') {
		if (ch1=='f' || ch2=='f')
			return p;
		else
			return 0;
	} else if (ch1 == 'p') {
		s1 = 'p' + s1;
		int num = build_tree1(p, s1);
		return ch2=='e' ? num : p;
	}	else {
		s2 = 'p' + s2;
		int num = build_tree1(p, s2);
		return ch1=='e' ? num : p;
	}
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input/uva297.in", "r", stdin);
  #endif
	int N;
	cin >> N;
	while (N--) {
		string gr1, gr2;
		cin >> gr1 >> gr2;
		cout << "There are " << build_tree2(1024, gr1, gr2)
			<< " black pixels." << endl;
	}
	return 0;
}
