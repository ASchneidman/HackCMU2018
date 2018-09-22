#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

const int maxn = 100 + 1;

int NP, NT, NF;
int P[maxn];
vector<int> TI[maxn], TO[maxn];

void display() {
  cout << "Places with tokens:";
  for (int i = 0; i < NP; i++) {
    if (P[i]) {
      cout << " " << i + 1 << " (" << P[i] << ")";
    }
  }
  cout << endl << endl;
}

bool transit() {
  for (int i = 0; i < NT; i++) {
    vector<int> &ti = TI[i], &to = TO[i];
    int j = 0;
    for (; j < ti.size(); j++) if (--P[ti[j]] < 0) break;
    if (j == ti.size()) {
      for (int k = 0; k < to.size(); k++) P[to[k]]++;
      return true;
    } else {
      while (j >= 0) P[ti[j--]]++;
    }
  }
  return false;
}

void solve() {
  for (int i = 0; i < NF; i++) {
    if (!transit()) {
      cout << "dead after " << i << " transitions" << endl;
      display();
      return;
    }
  }
  cout << "still live after " << NF << " transitions" << endl;
  display();
  return;
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input/uva804.in", "r", stdin);
  #endif
  int kase = 0;
	while (cin >> NP && NP) {
    for (int i = 0; i < NP; i++) cin >> P[i];
    cin >> NT;
    for (int i = 0; i < NT; i++) {
      int t;
      TI[i].clear(); TO[i].clear();
      while (cin >> t && t) {
        if (t < 0) TI[i].push_back(-t - 1);
        else TO[i].push_back(t - 1);
      }
    }
    cout << "Case " << ++kase << ": ";
    cin >> NF;
    solve();
  }
  return 0;
}
