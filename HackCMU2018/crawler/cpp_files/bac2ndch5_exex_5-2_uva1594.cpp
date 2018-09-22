#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<set>
using namespace std;

const int loop = 1000;

set< vector<int> > ducci;

int main() {
  #ifndef ONLINE_JUDGE
    freopen("input/uva1594.in", "r", stdin);
  #endif
  int T, n, el;
  vector<int> v1, v2;
  cin >> T;
  while (T--) {
    ducci.clear(); v1.clear();
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> el;
      v1.push_back(el);
    }
    for (int i = 0; i < loop; i++) {
      int cnt = 0, el;
      pair<std::set< vector<int> >::iterator, bool> ret = ducci.insert(v1);
      if (!ret.second) { cout << "LOOP" << endl; break; }
      v2.clear();
      for (int j = 0; j < n; j++) {
        el = abs(v1[j] - v1[(j+1)%n]), cnt |= el;
        v2.push_back(el);
      }
      if (cnt == 0)  { cout << "ZERO" << endl; break; }
      v1.swap(v2);
    }
  }
  return 0;
}

/** Without using STL
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

const int loop = 1000;

bool next(int* A, int n) {
  int cnt = 0;
  A[n] = A[0];
  for (int j = 0; j < n; j++) {
    A[j] = abs(A[j] - A[j+1]);
    if (A[j]) cnt++;
  }
  return cnt == 0;
}

int main() {
  #ifndef ONLINE_JUDGE
    freopen("input/uva1594.in", "r", stdin);
  #endif
  int T, n, A[16];
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < loop; i++) {
      if (next(A, n)) {
        cout << "ZERO" << endl;
        n = -1;
        break;
      }
    }
    if (n != -1) cout << "LOOP" << endl;
  }
  return 0;
}
*/
