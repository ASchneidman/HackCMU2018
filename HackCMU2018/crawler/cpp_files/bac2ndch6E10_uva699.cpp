#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int maxn = 200;
int sum[maxn];

// 输入并统计一棵子树，树根水平位置为p
void build(int p) {
  int v;
  cin >> v;
  if(v == -1) return; // 空树
  sum[p] += v;
  build(p - 1);
  build(p + 1);
}

// 边读入边统计
bool init() {
  int v;
  cin >> v;
  if(v == -1) return false;

  memset(sum, 0, sizeof(sum));
  int pos = maxn/2; // 树根的水平位置
  sum[pos] = v;
  build(pos - 1); // 左子树
  build(pos + 1); // 右子树
  return true;
}

int main() {
  #ifndef ONLINE_JUDGE
    freopen("input/uva699.in", "r", stdin);
  #endif
  int kase = 0;
  while(init()) {
    int p = 0;
    while(sum[p] == 0) p++; // 找最左边的叶子

    // 开始输出。因为要避免行末多余空格，所以稍微麻烦一点
    cout << "Case " << ++kase << ":\n" << sum[p++];
    while(sum[p] != 0) {
      cout << " " << sum[p];
      p++;
    }
    cout << "\n\n";
  }
  return 0;
}
