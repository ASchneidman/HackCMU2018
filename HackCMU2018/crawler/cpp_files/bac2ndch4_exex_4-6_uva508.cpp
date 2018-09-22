#include<cstdio>
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

map<char, string> morse;
map<string, string> ctx;

string encode(string word) {
  int i = 0;
  string code;
  while (word[i])
   code += morse[word[i++]];
  return code;
}

int dist(string s1, string s2) {
  int cnt = 0, len1 = s1.length(), len2 = s2.length();
  while (s1[cnt] == s2[cnt] && s1[cnt] && s2[cnt]) cnt++;
  if (cnt < len1 && cnt < len2) return -1;
  return max(len1, len2) - cnt;  
}

void find(string input) {
  int minDiff = 0x7fffffff;
  string result;
  map<string, string>::iterator it;
  for (it = ctx.begin(); it != ctx.end(); it++) {
    int diff = dist(it->second, input);
    if (diff == -1) continue;
    if (diff < minDiff) {
      minDiff = diff;
      result = it->first;
    } else if (diff == 0 && minDiff == 0) {
      result += '!';
      break;
    }
  }
  if (minDiff) result += '?';
  cout << result << endl;
}

int main() {
  #ifndef ONLINE_JUDGE
    freopen("input/uva508.in", "r", stdin);
  #endif
  ios::sync_with_stdio(false);
  string s1, s2;
  while (cin >> s1 && s1[0] != '*') {
    cin >> s2;
    morse[s1[0]] = s2;
  }
  while (cin >> s1 && s1[0] != '*')
    ctx[s1] = encode(s1);
  while (cin >> s1 && s1[0] != '*') 
    find(s1);
  return 0;
}

/* Wrong Answer
#include<cstdio>
#include<cstring>

char morse[127][7];
char word[100][11], code[100][61] = { 0 };
int n = 0, minWord = 0;

int dist(char* x, char* y) {
  int diff = 0;
  while (*x && *y && *x == *y || !(*x && *y) && *x + *y) {
    if (*x != *y) diff++;
    if (*x) x++; if (*y) y++;
  }
  if (*x && *y) return -1;
  return diff;
}

void find(char* input) {
  int minDiff = 0x7fffffff, minI = -1, cnt = 0;
  for (int i = 0; i < n; i++) {
    int diff = dist(input, code[i]);
    // printf("%d (%s) (%s): (%d %d %d)\n", i, input, code[i], minI, minDiff, diff);
    if (diff == -1) continue;
    if (diff == 0) cnt++;
    if (diff < minDiff) { minDiff = diff; minI = i; }
    else if (diff == minDiff && strcmp(word[i], word[minI]) < 0) minI = i;
  }
  if (minI == -1) printf("%s?\n", word[minWord]);
  else if (minDiff > 0) printf("%s?\n", word[minI]);
  else if (cnt == 1) printf("%s\n", word[minI]);
  else if (cnt > 1) printf("%s!\n", word[minI]);
}

int main() {
  #ifndef ONLINE_JUDGE
    freopen("input/uva508.in", "r", stdin);
  #endif
  char c, *cur, input[81];
  memset(code, 0, sizeof(code));
  memset(input, 0, sizeof(input));
  while (scanf(" %c", &c) && c != '*') scanf("%s", morse[c]);
  while (scanf("%s", word[n]) && word[n][0] != '*') {
    cur = word[n];
    if (n && strcmp(word[n], word[minWord]) < 0) minWord = n;
    while (*cur) strcat(code[n], morse[*(cur++)]);
    n++;
  }
  
  while (scanf("%s", input) && input[0] != '*') {
    find(input);
    memset(input, 0, sizeof(input));
  }
  return 0;
}
*/
