#include<cstdio>
#include<cmath>

int N;
char rtype[7];
int rx[7], ry[7];

int numOfSameRow(int x, int y, int xi, int yi) {
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if (xi == rx[i] && (yi-ry[i])*(ry[i]-y) > 0)
      cnt++;
  }
  return cnt;
}

int numOfSameColumn(int x, int y, int xi, int yi) {
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if (yi == ry[i] && (xi-rx[i])*(rx[i]-x) > 0)
      cnt++;
  }
  return cnt;
}

bool checkGeneral(int x, int y, int xi, int yi) {
  return y == yi && !numOfSameColumn(x, y, xi, yi);
}

bool checkChariot(int x, int y, int xi, int yi) {
  if (y == yi && x == xi) return false;
  return y == yi && !numOfSameColumn(x, y, xi, yi)
          || x == xi && !numOfSameRow(x, y, xi, yi);
}

bool checkCannon(int x, int y, int xi, int yi) {
  if (y == yi && x == xi) return false;
  return y == yi && numOfSameColumn(x, y, xi, yi) == 1
          || x == xi && numOfSameRow(x, y, xi, yi) == 1;
}

bool checkHorse(int x, int y, int xi, int yi) {
  if (y == yi && x == xi) return false;
  int dx = std::abs(x - xi), dy = std::abs(y - yi);
  if (dx > 0 && dy > 0 && dx + dy == 3) {
    int legx, legy;
    if (dx == 1) legx = xi, legy = (y + yi) / 2;
    else legx = (x + xi) / 2, legy = yi;
    for (int i = 0; i < N; i++) {
      if (legx == rx[i] && legy == ry[i])
        return false;
    }
    return true;
  }
  return false;
}

bool checkPosition(int x, int y) {
  if (x < 1 || x > 3 || y < 4 || y > 6) return true;
  for (int i = 0; i < N; i++) {
    if (rtype[i] == 'G' && checkGeneral(x, y, rx[i], ry[i])
        || rtype[i] == 'R' && checkChariot(x, y, rx[i], ry[i])
        || rtype[i] == 'C' && checkCannon(x, y, rx[i], ry[i])
        || rtype[i] == 'H' && checkHorse(x, y, rx[i], ry[i]))
      return true;
  }
  return false;
}

int main() {
  #ifndef ONLINE_JUDGE
    freopen("input/uva1589.in", "r", stdin);
  #endif
  int x, y;
  int offset[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  while (scanf("%d%d%d", &N, &x, &y) && N) {
    for (int i = 0; i < N; i++) {
      scanf(" %c%d%d", &rtype[i], &rx[i], &ry[i]);
    }
    bool checked = true;
    for (int i = 0; i < 4; i++) {
      checked &= checkPosition(x + offset[i][0], y + offset[i][1]);
    }
    printf("%s", checked ? "YES\n" : "NO\n");
  }
  return 0;
}
