#include<cstdio>
#include<iostream>
#include<string>
#include<sstream>
#include<map>
#include<set>
using namespace std;

set<string> add, del, chg;

string repr(string s) {
  string ans = s;
  for (string::iterator it = ans.begin(); it != ans.end(); it++)
    if (!isalnum(*it))
      *it = ' ';
  return ans;
}

void readDict(map<string, string>& dict) {
  string line;
  getline(cin, line);
  stringstream ss(repr(line));
  string key, value;
  while (ss >> key >> value) dict[key] = value;
}

void diff(map<string, string>& oldDict, map<string, string>& newDict) {
  for (map<string, string>::iterator it = newDict.begin(); it != newDict.end(); it++) {
    string key = it->first, value = it->second;
    if (!oldDict.count(key)) add.insert(key);
    else {
      if (oldDict[key] != value) chg.insert(key);
      oldDict.erase(key);
    }
  }
  for (map<string, string>::iterator it = oldDict.begin(); it != oldDict.end(); it++)
    del.insert(it->first);
}

void printSet(set<string>& s) {
  for (set<string>::iterator it = s.begin(); it != s.end(); it++) {
    if (it != s.begin()) cout << ",";
    cout << *it;
  }
  cout << endl;
}

void display() {
  if (add.size()) {
    cout << "+";
    printSet(add);
  }
  if (del.size()) {
    cout << "-";
    printSet(del);
  }
  if (chg.size()) {
    cout << "*";
    printSet(chg);
  }
  if (add.size() + del.size() + chg.size() == 0)
    cout << "No changes" << endl;
  cout << endl;
  add.clear();
  del.clear();
  chg.clear();
}

int main() {
  #ifndef ONLINE_JUDGE
    freopen("input/uva12504.in", "r", stdin);
  #endif
  int T;
  string line;
  cin >> T;
  cin.ignore();
  while (T--) {
    map<string, string> oldDict, newDict;
    readDict(oldDict); readDict(newDict);
    diff(oldDict, newDict);
    display();
  }
  return 0;
}
