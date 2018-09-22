#include<cstdio>
#include<cstring>

int H[10][10], V[10][10];
bool found;

bool hasH(int x, int y, int size) {
  int start = y, end = y + size;
  for (int i = start; i < end; i++) {
    if (!H[x][i]) return false;
  }
  return true;
}

bool hasV(int x, int y, int size) {
  int start = x, end = x + size;
  for (int i = start; i < end; i++) {
    if (!V[i][y]) return false;
  }
  return true;
}

bool findSquare(int size, int n) {
  int cnt = 0;
  bool needNext = false;
  for (int i = 1; i <= n - size; i++) {
    for (int j = 1; j <= n - size; j++) {
      if (!hasH(i, j, size)) continue;
      needNext = true;
      if (!hasH(i + size, j, size)) continue;
      if (!hasV(i, j, size)) continue;
      if (!hasV(i, j + size, size)) continue;
      cnt++, found = true;
    }
  }
  if (cnt) printf("%d square (s) of size %d\n", cnt, size);
  return needNext;
}

int main() {
  #ifndef ONLINE_JUDGE
    freopen("input/uva201.in", "r", stdin);
  #endif
  int kase = 0, n, m, numV = 0, numH = 0; 
  while (scanf("%d%d", &n, &m) == 2) {
    if (kase) printf("\n**********************************\n\n");
    printf("Problem #%d\n\n", ++kase);
    found = false;
    memset(H, 0, sizeof(H));
    memset(V, 0, sizeof(V));
    for (int i = 0; i < m; i++) {
      char dir;
      int x, y;
      scanf(" %c%d%d", &dir, &x, &y);
      if (dir == 'H') H[x][y] = 1, numH++;
      else V[y][x] = 1, numV++;
    }
    for (int i = 1; i <= n; i++) {
      if (m/4 < i || numH/2 < i || numV/2 < i) break;
      if (!findSquare(i, n)) break;
    }
    if (!found) puts("No completed squares can be found.");
  }
  return 0;
}
