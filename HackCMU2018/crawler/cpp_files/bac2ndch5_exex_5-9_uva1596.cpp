#include<cstdio>
#include<iostream>
#include<string>
#include<map>
#include<stdexcept>
using namespace std;

map<string, int> sizes;
map<string, map<int, int> > values;

int parseEx(string& exp);
pair<string, int> parseArray(string& arr, int arrPos);

pair<string, int> parseArray(string& arr, int arrPos) {
  string name = arr.substr(0, arrPos);
  string idxStr = arr.substr(arrPos + 1, arr.length() - arrPos - 2);
  int idx = parseEx(idxStr);
  if (idx < sizes[name]) return make_pair(name, idx);
  throw out_of_range("out of range: " + name + "[" + to_string(idx) + "]");
}

int parseEx(string& exp) {
  int found = exp.find_first_of('[');
  if (found == string::npos) return stoi(exp);
  pair<string, int> key = parseArray(exp, found);
  if (values.count(key.first) && values[key.first].count(key.second))
    return values[key.first][key.second];
  throw invalid_argument("no such element: " + key.first + "[" + to_string(key.second) + "]");
}

void parseDeclaration(string& dcl) {
  int found = dcl.find_first_of('['), len = dcl.length();
  string name = dcl.substr(0, found);
  int size = stoi(dcl.substr(found + 1, len - found - 2));
  // cout << name << " " << size << " ";
  sizes[name] = size;
}

bool parseAssignment(string& asn, int eqPos) {
  string left = asn.substr(0, eqPos);
  string right = asn.substr(eqPos + 1);
  try {
    pair<string, int> key = parseArray(left, left.find_first_of('['));
    int value = parseEx(right);
    values[key.first][key.second] = value;
    return true;
  } catch (const logic_error& e) {
    return false;
  }
}

int main() {
  #ifndef ONLINE_JUDGE
    freopen("input/uva1596.in", "r", stdin);
  #endif
  string line;
  while (getline(cin, line) && line != ".") {
    int errLine = 1;
    bool error = false;
    parseDeclaration(line);
    while (errLine++, getline(cin, line) && line != ".") {
      if (error) continue;
      int found = line.find_first_of('=');
      if (found == string::npos) parseDeclaration(line);
      else if (!parseAssignment(line, found)) {
        cout << errLine << endl;
        error = true;
      }
    }
    if (!error) cout << 0 << endl;
    values.clear();
  }
  return 0;
}
