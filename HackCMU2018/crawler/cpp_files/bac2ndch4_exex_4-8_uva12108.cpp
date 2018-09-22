#include<cstdio>

int n, sleep;
int A[10], B[10], C[10], AB[10];

int gcd(int a, int b) {
  if (a % b == 0) return b;
  return gcd(b, a % b);
}

int lcm(int a, int b) {
  return a * b / gcd(a, b);
}

void printStatus(int sleep) {
  for (int i = 0; i < n; i++) {
    if (C[i] <= A[i]) putchar('.');
    else putchar('O');
  }
  putchar(' ');
  for (int i = 0; i < n; i++) printf("%d", C[i]);
  putchar(' ');
  for (int i = 0; i < n; i++) printf("%d", A[i]);
  putchar(' ');
  for (int i = 0; i < n; i++) printf("%d", AB[i]);
  printf(" %d\n", sleep);
}

int getAwakeTime(int cycle) {
  int sleep = 0;
  for (int i = 0; i < n; i++) if (C[i] > A[i]) sleep++; 
  for (int t = 1; t <= cycle + 1; t++) {
    // printStatus(sleep);
    if (sleep == 0) return t;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      C[i]++;
      if (C[i] == AB[i] + 1) C[i] = 1, --cnt;
      else if (C[i] == A[i] + 1){
        if (sleep <= n - sleep) C[i] = 1;
        else cnt++;
      }
    }
    sleep += cnt;
  }
  return -1;
}

int main() {
  #ifndef ONLINE_JUDGE
    freopen("input/uva12108.in", "r", stdin);
  #endif
  int kase = 0;
  while (scanf("%d", &n) && n) {
    int cycle = 1;
    for (int i = 0; i < n; i++) {
      scanf("%d%d%d", &A[i], &B[i], &C[i]);
      AB[i] = A[i] + B[i];
      cycle = lcm(cycle, AB[i]);
    }
    printf("Case %d: %d\n", ++kase, getAwakeTime(cycle));
  }
  return 0;
}
