#include<cstdio>
#include<iostream>
#include<sstream>
#include<string>
#include<map>
#include<set>
#include<vector>
using namespace std;

vector<int> startLine;
vector<string> docs;
map<string, set<int> > index;

void updateIndex(string line, int lineNo) {
  for (string::iterator it = line.begin(); it != line.end(); it++) {
    if (isalpha(*it)) *it = tolower(*it);
    else *it = ' ';
  }
  stringstream ss(line);
  string word;
  while (ss >> word) index[word].insert(lineNo);
}

vector<string> resolveCmd(string& cmd) {
  vector<string> ans;
  stringstream ss(cmd);
  string token;
  while (ss >> token) ans.push_back(token);
  return ans;
}

int main() {
  #ifndef ONLINE_JUDGE
    freopen("input/uva1597.in", "r", stdin);
  #endif
  int N, M, lineNo = 0;
  string line, A, B;
  cin >> N;
  cin.ignore();
  for (int i = 0; i < N; i++) {
    startLine.push_back(lineNo);
    while (getline(cin, line) && line[0] != '*') {
      docs.push_back(line);
      updateIndex(line, lineNo++);
    }
  }
  startLine.push_back(lineNo);
  cin >> M;
  cin.ignore();
  while (M--) {
    getline(cin, line);
    vector<string> cmd = resolveCmd(line);
    bool found = false;
    if (cmd.size() == 1) {
      set<int>& bucket = index[cmd[0]];
      set<int>::iterator it = bucket.begin();
      for (int i = 0; i < N; i++) {
        while (it != bucket.end() && *it < startLine[i]) it++;
        if (it != bucket.end() && *it < startLine[i+1]) {
          if (found) cout << "----------" << endl;
          found = true;
          while (it != bucket.end() && *it < startLine[i+1])
            cout << docs[*(it++)] << endl;
        }
      }
    } else if (cmd.size() == 2) {
      set<int>& bucket = index[cmd[1]];
      set<int>::iterator it = bucket.begin();
      for (int i = 0; i < N; i++) {
        while (it != bucket.end() && *it < startLine[i]) it++;
        if (it == bucket.end() || *it >= startLine[i+1]) {
          if (found) cout << "----------" << endl;
          found = true;
          for (int j = startLine[i]; j < startLine[i+1]; j++)
            cout << docs[j] << endl;
        }
      }
    } else if (cmd.size() == 3) {
      set<int> &bucket1 = index[cmd[0]], &bucket2 = index[cmd[2]];
      set<int>::iterator it1 = bucket1.begin(), it2 = bucket2.begin();
      for (int i = 0; i < N; i++) {
        while (it1 != bucket1.end() && *it1 < startLine[i]) it1++;
        while (it2 != bucket2.end() && *it2 < startLine[i]) it2++;
        bool valid = false;
        if (cmd[1] == "AND") {
          valid = it1 != bucket1.end() && *it1 < startLine[i+1];
          valid &= it2 != bucket2.end() && *it2 < startLine[i+1];
        } else if (cmd[1] == "OR") {
          valid = it1 != bucket1.end() && *it1 < startLine[i+1]; 
          valid |= it2 != bucket2.end() && *it2 < startLine[i+1];
        }
        if (!valid) continue;
        if (found) cout << "----------" << endl;
        found = true;
        while (true) {
          int a = 10000, b = 10000;
          if (it1 != bucket1.end() && *it1 < startLine[i+1]) a = *it1;
          if (it2 != bucket2.end() && *it2 < startLine[i+1]) b = *it2;
          if (a == 10000 && b == 10000) break;
          if (a < b) it1++;
          else if (a > b) a = b, it2++;
          else it1++, it2++;
          cout << docs[a] << endl;
        }
      }
    }
    if (!found) cout << "Sorry, I found nothing." << endl;
    cout << "==========" << endl;
  }
  return 0;
}
