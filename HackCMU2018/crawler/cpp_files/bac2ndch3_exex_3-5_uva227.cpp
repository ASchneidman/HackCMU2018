#include<cstdio>

void display(char puzzle[][7]) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (j) putchar(' ');
      putchar(puzzle[i][j]);
    }
    putchar('\n');
  }
}

int main() {
  #ifndef ONLINE_JUDGE
    freopen("input/uva227.in", "r", stdin);
  #endif
  char puzzle[5][7];
  int kase = 0;
  while(fgets(puzzle[0], 7, stdin)) {
    if (puzzle[0][0] == 'Z') break;
    if (kase) putchar('\n');
    printf("Puzzle #%d:\n", ++kase);
    fgets(puzzle[1], 7, stdin);
    fgets(puzzle[2], 7, stdin);
    fgets(puzzle[3], 7, stdin);
    fgets(puzzle[4], 7, stdin);
    int x, y;
    for (int i = 0; i < 5; i++)
      for (int j = 0; j < 5; j++)
        if (puzzle[i][j] == ' ' || puzzle[i][j] == '\n' || puzzle[i][j] == '\0')
          { x = i; y = j; break; }
    int dir, err = 0;
    while (1) {
      dir = getchar();
      if (dir == 'A') {
        if (x == 0) { err = 1; break; }
        puzzle[x][y] = puzzle[x-1][y];
        --x;
      } else if(dir == 'B') {
        if (x == 4) { err = 1; break; }
        puzzle[x][y] = puzzle[x+1][y];
        x++;
      } else if(dir == 'L') {
        if (y == 0) { err = 1; break; }
        puzzle[x][y] = puzzle[x][y-1];
        y--;
      } else if(dir == 'R') {
        if (y == 4) { err = 1; break; }
        puzzle[x][y] = puzzle[x][y+1];
        y++;
      } else if(dir == '0') break;
    }
    if (dir != '0') while((dir = getchar()) != '0');
    while((dir = getchar()) != '\n');
    if (err) puts("This puzzle has no final configuration.");
    else {
      puzzle[x][y] = ' ';
      display(puzzle);
    }
  }
  return 0;
}
