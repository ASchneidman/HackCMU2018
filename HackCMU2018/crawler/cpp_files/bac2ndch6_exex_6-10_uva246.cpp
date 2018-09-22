#include<cstdio>
#include<iostream>
#include<set>
#include<vector>
#include<deque>
using namespace std;

vector<deque<int> > piles;
set<vector<deque<int> > > state;

bool read() {
  int x;
  deque<int> u;
  piles.clear(); state.clear();
  for (int i = 0; i <= 7; i++) piles.push_back(u);
  for (int i = 0; i < 52; i++) {
    cin >> x;
    if (x == 0) return false;
    int j = i < 14 ? i % 7 : 7;
    piles[j].push_back(x);
  }
  state.insert(piles);
  return true;
}

int next(int cur) {
  int i = cur;
  do i = (i + 1) % 7;
  while (piles[i].size() == 0 && i != cur);
  return i;
}

void check(deque<int>& pile) {
  while (pile.size() >= 3) {
    int n = pile.size();
    deque<int>& deck = piles[7];
    int t1 = pile.front(), t2 = pile[1];
    int b1 = pile.back(), b2 = pile[n-2], b3 = pile[n-3];
    if ((t1 + t2 + b1) % 10 == 0) {
      deck.push_back(t1); deck.push_back(t2); deck.push_back(b1);
      pile.pop_front(); pile.pop_front(); pile.pop_back();
    } else if ((t1 + b2 + b1) % 10 == 0) {
      deck.push_back(t1); deck.push_back(b2); deck.push_back(b1);
      pile.pop_front(); pile.pop_back(); pile.pop_back();
    } else if ((b3 + b2 + b1) % 10 == 0) {
      deck.push_back(b3); deck.push_back(b2); deck.push_back(b1);
      pile.pop_back(); pile.pop_back(); pile.pop_back();
    } else {
      break;
    }
  }
}

bool put(deque<int>& pile, int rnd) {
  deque<int>& deck = piles[7];
  int x = deck.front(); deck.pop_front();
  pile.push_back(x);
  check(pile);
  if (deck.empty()) { cout << "Loss: " << rnd << endl; return false; }
  if (deck.size() == 52) { cout << "Win : " << rnd << endl; return false; }
  if (!state.insert(piles).second) { cout << "Draw: " << rnd << endl; return false;}
  return true;
}

void solve() {
  int rnd = 14, cur = 6;
  do {
    cur = next(cur);
  } while (put(piles[cur], ++rnd));
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input/uva246.in", "r", stdin);
  #endif
  while (read()) {
    solve();
  }
	return 0;
}
