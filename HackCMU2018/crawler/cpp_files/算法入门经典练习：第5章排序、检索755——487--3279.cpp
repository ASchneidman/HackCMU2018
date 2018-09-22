#include <iostream>
#include <string>
#include<cstdio>
#include<cstdlib>
#include<cctype>
using namespace std;

int num[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
int tel[100010] = {0};
int cmp(const void *_a, const void *_b) {
	int *a = (int*)_a;
	int *b = (int*)_b;
	return *a - *b;
}
int change(string& s) {
	int temp = 0;
	for(unsigned i = 0; i < s.size(); i++) {
		if(isdigit(s[i]))
			temp = temp*10 + s[i] - '0';
		else if(isupper(s[i]) && s[i] != 'Q' && s[i] != 'Z')
			temp = temp*10 + num[s[i]-'A'];
	}
	return temp;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n; cin >> n;
		cin.ignore();
		string temp;
		for(int i = 0; i < n; i++) {
			getline(cin, temp);
			tel[i] = change(temp);
		}
		qsort(tel, n, sizeof(tel[0]), cmp);
		int ok = 1, rep = 1;
		for(int i = 0; i < n; i++) {
			if(tel[i] == tel[i+1])
				rep++;
			else {
				if(rep > 1) {
					printf("%03d-%04d %d\n", tel[i]/10000, tel[i]%10000, rep);
					ok = 0;
				}
				rep = 1;
			}
		}
		if(ok) cout << "No duplicates." << endl;
		if(t) cout << endl;
	}
	return 0;
}