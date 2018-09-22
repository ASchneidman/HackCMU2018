#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

const int N = 52;

vector< stack<string> > piles;

bool match(string& c1, string& c2) {
	return c1[0] == c2[0] || c1[1] == c2[1];
}

void putAndMove(string& card) {
	stack<string> pile;
	pile.push(card);
	piles.push_back(pile);
	for (int i = piles.size() - 1, j; i < piles.size(); i++) {
		string cur = piles[i].top();
		j = i;
		while(j > 0) {
			if (j >= 3 && match(cur, piles[j-3].top())) j -= 3;
			else if (match(cur, piles[j-1].top())) j -= 1;
			else break;
		}
		if (j != i) {
			piles[j].push(cur);
			piles[i].pop();
			if (piles[i].empty()) piles.erase(piles.begin() + i);
			i = j;
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input/uva127.in", "r", stdin);
  #endif
	string card;
	while(cin >> card && card[0] != '#') {
		piles.clear();
		putAndMove(card);
		for (int i = 1; i < N; i++) {
			cin >> card;
			putAndMove(card);
		}
		int size = piles.size();
		string s = size > 1 ? "s" : "";
		cout << size << " pile" << s << " remaining:";
		for(int i = 0; i < size; i++) cout << " " << piles[i].size();
		cout << endl;
	}
	return 0;
}
