#include<cstdio>

char disks[8][6401];
int d, s, b;
int parity;

bool valid() {
  for (int j = 0; j < s * b; j++) {
    int lost = -1, check = 0;
    for (int i = 0; i < d; i++) {
      char& c = disks[i][j];
      if (c == 'x') {
        if (lost != -1) return false;
        lost = i;
      } else if (c == '1')
        check ^= 1;
    }
    if (lost == -1 && check != parity) return false;
    if (lost != -1) disks[lost][j] = '0' + (check != parity);
  }
}

void printData() {
  int bit = 0, n = 0;
  for (int j = 0; j < b; j++) {
    for (int i = 0; i < d; i++) {
      if (j % d == i) continue;
      for (int k = 0; k < s; k++) {
        if (disks[i][j*s + k] == '1') n += 1;
        if (++bit == 4) {
          printf("%X", n);
          bit = n = 0;
        } else
          n <<= 1;
      }
    }
  }
  if (bit) printf("%X", n << (3-bit));
  putchar('\n');
}

int main() {
  #ifndef ONLINE_JUDGE
    freopen("input/uva509.in", "r", stdin);
  #endif
  int kase = 0;
  char p;
  while (scanf("%d%d%d %c", &d, &s, &b, &p) && d) {
    parity = p == 'O';
    for (int i = 0; i < d; i++) scanf("%s", disks[i]);
    printf("Disk set %d is ", ++kase);
    if (valid()) {
      printf("valid, contents are: ");
      printData();
    } else puts("invalid.");
  }
  return 0;
}
