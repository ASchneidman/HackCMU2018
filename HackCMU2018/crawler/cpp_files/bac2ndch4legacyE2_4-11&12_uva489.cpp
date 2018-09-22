#include<stdio.h>
#include<string.h>

const int maxn = 1000;

int main() {
  #ifndef ONLINE_JUDGE
    freopen("input/uva489.in", "r", stdin);
  #endif
  int n;
  while(scanf("%d", &n) == 1 && n != -1) {
    printf("Round %d\n", n);
    char input[maxn];
    scanf("%s", input);
    int word[26] = {0}, guess[26] = {0};
    int num = 0, len_word = strlen(input), i;
    for(i = 0; i < len_word; i++) {
      int word_num = input[i] - 'a';
      if(!word[word_num]) {
        word[word_num]++;
        num++;
      }
    }
    scanf("%s", input);
    int len_guess = strlen(input);
    int false_time = 0;
    for(i = 0; i < len_guess; i++) {
      int word_num = input[i] - 'a';
      if(!guess[word_num]) {
        guess[word_num]++;
        if(!word[word_num]) {
          false_time++;
          if(false_time >= 7) {
            printf("You lose.\n");
            break;
          }
        } else {
          num--;
          if(!num) {
            printf("You win.\n");
            break;
          }
        }
      }
    }
    if(i >= len_guess)
      printf("You chickened out.\n");
  }
  return 0;
}
