#include<cstdio>

const int dir[][2] = {0, 1, 1, 1, 1, 0, 1, -1, 0, -1, -1, -1, -1, 0, -1, 1};
bool hasLegal;
char board[9][12], cmd, cur, opp;
int W, B;

void changePlayer() {
  if (opp == 'W') cur = 'W', opp = 'B';
  else if (opp == 'B') cur = 'B', opp = 'W';
}

int outOfBox(int x, int y) {
  return x < 1 || x > 8 || y < 1 || y > 8;
}

bool isLegal(int x, int y) {
  for (int i = 0; i < 8; i++) {
    int tmpx = x, tmpy = y;
    while (!outOfBox(tmpx+dir[i][0], tmpy+dir[i][1]) 
        && board[tmpx+=dir[i][0]][tmpy+=dir[i][1]] == opp)
      ;
    if (board[tmpx][tmpy] == cur 
        && (tmpx != x + dir[i][0] || tmpy != y + dir[i][1])) {
      if (hasLegal) putchar(' ');
      printf("(%d,%d)", x, y);
      return true;
    }
  }
  return false;
}

void list() {
  hasLegal = false;
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      if (board[i][j] == '-')
        hasLegal |= isLegal(i, j);
    }
  }
  if (!hasLegal) {
    puts("No legal move.");
    changePlayer();
  } else {
    putchar('\n');
  }
}

void move() {
  char xc, yc;
  scanf(" %c %c", &xc, &yc);
  int x = xc - '0', y = yc - '0';
  board[x][y] = cur;
  if (cur == 'W') W++; else B++;
  for (int i = 0; i < 8; i++) {
    int tmpx = x, tmpy = y;
    while (!outOfBox(tmpx+dir[i][0], tmpy+dir[i][1]) 
        && board[tmpx+=dir[i][0]][tmpy+=dir[i][1]] == opp)
     ;
    if (board[tmpx][tmpy] == cur && (tmpx != x || tmpy != y)) {
      while ((tmpx-=dir[i][0]) != x | (tmpy-=dir[i][1]) != y) {
        board[tmpx][tmpy] = cur;
        if (cur == 'W') W++, B--; else B++, W--;
      }
    }
  }
  printf("Black - %2d White - %2d\n", B, W);
  changePlayer();
}

void readConfig() {
  W = B = 0;
  for (int i = 1; i <= 8; i ++)
    scanf(" %s ", board[i] + 1);
  for (int i = 1; i <= 8; i++)
    for (int j = 1; j <= 8; j++)
      if (board[i][j] == 'W') W++;
      else if (board[i][j] == 'B') B++;
  scanf(" %c ", &opp);
  changePlayer();
}

void printBoard() {
  for (int i = 1; i <= 8; i++) puts(board[i] + 1);
}

int main() {
  #ifndef ONLINE_JUDGE
    freopen("input/uva220.in", "r", stdin);
  #endif
  int kase;
  scanf("%d", &kase);
  while (kase--) {
    readConfig();
    while (scanf(" %c ", &cmd) && cmd != 'Q') {
      if (cmd == 'L') list();
      else move();
    }
    printBoard();
    if (kase) putchar('\n');
  }
  return 0;
}
