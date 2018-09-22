#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;

int G[30][30], alph[30];
int into[30], out[30];

//判断图的连通性
int dfs(int u) {
	int sum = 0;
	alph[u] = 0;
	for (int v = 0; v < 26; v++)
		if (alph[v] && G[u][v])
			sum += dfs(v);
	return sum + 1;
}

//判断是否存在欧拉回路
bool euler() {
	int single = 0, degree = 0;
	for (int i = 0; i < 26; i++) {
		if (into[i] != out[i]) {
		  ++single;
			degree += into[i] - out[i];
		}
		if (abs(into[i] - out[i]) > 1 || single > 2)
			return false;
		if (single == 2 && degree != 0) return false;
	}
	return true;
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input/uva10129.in", "r", stdin);
  #endif
	int kase, n, sum, en;
	cin >> kase;
	while (kase--) {
		memset(G, 0, sizeof(G));
		memset(into, 0, sizeof(into));
		memset(out, 0, sizeof(out));
		cin >> n; cin.ignore();
		for (int i=0; i<n; i++) {
			string word;
			getline(cin, word);
			int front = word[0]-'a', rear = word[word.size()-1]-'a';
			G[front][rear] = G[rear][front] = 1;
			alph[front] = alph[rear] = 1;
			out[front]++; into[rear]++;
		}
		sum=0;
		for (int i = 0; i < 26; i++)
			if (alph[i]) { sum++; en = i; }
		if (dfs(en) == sum && euler())
			cout << "Ordering is possible." << endl;
		else
			cout << "The door cannot be opened." << endl;		
	}
	return 0;
}

