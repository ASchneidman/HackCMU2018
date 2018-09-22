#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

const double eps = 1e-6;

struct Map {
  string name;
  double x1, y1, x2, y2;
  double minx, area, ratio;
  double centerx, centery;
  double cornerx, cornery;
  Map(string name, double x1, double y1, double x2, double y2)
      : name(name), x1(x1), y1(y1), x2(x2), y2(y2) {
    centerx = (x1 + x2) / 2;
    centery = (y1 + y2) / 2;
    cornerx = max(x1, x2);
    cornery = min(y1, y2);
    minx = min(x1, x2);
    area = abs((x1 - x2) * (y1 - y2));
    ratio = abs((x1 - x2) / (y1 - y2));
  }
  bool contain(double x, double y) const {
    return (x1 < x && x < x2 || x2 < x && x < x1)
        && (y1 < y && y < y2 || y2 < y && y < y1);
  }
  bool operator < (const Map& rhs) const {
    return area > rhs.area;
  }
};

struct Detail {
  string name;
  int level;
  double distCenter, ratio, distCorner, minx;
  Detail(string name): name(name) {}
  bool operator < (const Detail& rhs) const {
    if (level > rhs.level) return true;
    if (distCenter < rhs.distCenter) return true;
    if (abs(0.75 - ratio) < abs(0.75 -rhs.ratio)) return true;
    if (distCorner > rhs.distCorner) return true;
    if (minx < rhs.minx) return true;
    return false;
  }
};

set<Map> maps;
map<string, set<Detail> > locs;

void buildLoc(string name, double x, double y) {
  int level = 1;
  set<Map>::iterator it = maps.begin();
  double last = it->area;
  locs[name] = set<Detail>();
  for (; it != maps.end(); it++) {
    if (!it->contain(x, y)) continue;
    Detail d(it->name);
    if (abs(it->area - last) < eps) d.level = level;
    else d.level = ++level;
    d.distCenter = pow(x - it->centerx, 2) + pow(y - it->centery, 2);
    d.ratio = it->ratio;
    d.distCorner = pow(x - it->cornerx, 2) + pow(y - it->cornery, 2);
    d.minx = it->minx;
    locs[name].insert(d);
    last = it->area;
  }
}

void processReq(string name, int level) {
  cout << name << " at detail level " << level << " ";
  if (locs.count(name) == 0) { cout << "unknown location" << endl; return; }
  set<Detail> d = locs[name];
  set<Detail>::iterator it = d.begin();
  if (d.size() == 0) { cout << "no map contains that location" << endl; return; }
  while (it->level > level && it != d.end()) it++;
  if (level > it->level) {
    cout << "no map at that detail level; using " << it->name << endl;
  } else {
    cout << "using " << it->name << endl;
  }
}

int main() {
  #ifndef ONLINE_JUDGE
    freopen("input/uva511.in", "r", stdin);
  #endif
  string s;
  double x1, y1, x2, y2;
  int level;
  getline(cin, s);  
  while (cin >> s && s != "LOCATIONS") {
    cin >> x1 >> y1 >> x2 >> y2;
    maps.insert(Map(s, x1, y1, x2, y2));
  }
  while (cin >> s && s != "REQUESTS") {
    cin >> x1 >> y1;
    buildLoc(s, x1, y1);
  }
  while (cin >> s && s != "END") {
    cin >> level;
    processReq(s, level);
  }
  return 0;
}
