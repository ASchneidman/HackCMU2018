#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

const int maxn = 64 + 1;
const int dir[5][2] = {{0, 0}, {0, 0}, {0, 1}, {1, 0}, {1, 1}};
const int base5[8] = {1, 5, 25, 125, 625, 3125, 15625, 78125};

int n;
char img[maxn][maxn];
vector<int> ans;

bool dfs(int r, int c, int len, int x, int dep) {
  if (len == 1) {
    if (img[r][c] == '1') { ans.push_back(x); return true; }
    else return false;
  }
  bool allBlack = true;
  len >>= 1;
  for (int i = 1; i <= 4; i++)
    allBlack &= dfs(r + len * dir[i][0], c + len * dir[i][1], len, x + i * base5[dep], dep + 1);
  if (allBlack) {
    for (int i = 1; i <= 4; i++) ans.pop_back();
    ans.push_back(x);
    return true;
  }
  return false;
}

void print() {
  int cnt = 0;
  sort(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    if (cnt) cout << ' ';
    cout << ans[i];
    if (++cnt == 12) {
      cnt = 0;
      cout << endl;
    }
  }
  if (cnt) cout << endl;
  cout << "Total number of black nodes = " << ans.size() << endl;
}

int fill(int x) {
  int r = 0, c = 0, len = n;
  while (x) {
    int sec = x % 5;
    x /= 5;
    len >>= 1;
    r += len * dir[sec][0];
    c += len * dir[sec][1];
  }
  for (int i = r; i < r + len; i++)
    for (int j = c; j < c + len; j++)
      img[i][j] = 1;
}

void display() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << (img[i][j] ? '*' : '.');
    cout << endl;
  }
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input/uva806.in", "r", stdin);
  #endif
  int kase = 0, x;
	while (cin >> n && n) {
    if (kase) cout << endl;
    cout << "Image " << ++kase << endl;
    if (n > 0) {
      for (int i = 0; i < n; i++) scanf("%s", img[i]);
      ans.clear();
      dfs(0, 0, n, 0, 0);
      print();
    } else {
      n = -n;
      memset(img, 0, sizeof(img));
      while (cin >> x && x != -1) fill(x);
      display();
    }
    
  }
  return 0;
}
