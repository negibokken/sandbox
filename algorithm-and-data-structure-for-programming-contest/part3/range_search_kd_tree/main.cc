#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

// Self settings
// clang-format off
#define MAX_N 100000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
ll fact(ll n) { ll res = 1; for(ll i=2;i<=n;++i) res = res * i; return res;}
ll nCr(ll n, ll r) {return (fact(n)/fact(n-r)*fact(r)) ;}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
const ll MOD = 1e9+7;
const ll INF = 1LL << 60;
const int inf = 1000100011;
// clang-format on

class Node {
 public:
  int location;
  int p, l, r;
  Node() {}
};

class Point {
 public:
  int id, x, y;
  Point(){};
  Point(int id, int x, int y) : id(id), x(x), y(y){};
  bool operator<(const Point &p) const { return id < p.id; }
  void print() { printf("%d\n", id); }
};

static const int MAX = 1000000;
static const int NIL = -1;

int N;
Point P[MAX_N];
Node T[MAX_N];
int np;

bool lessX(const Point &p1, const Point &p2) { return p1.x < p2.x; }
bool lessY(const Point &p1, const Point &p2) { return p2.x < p1.x; }

int makeKDTree(int l, int r, int depth) {
  if (!(l < r)) return NIL;
  int mid = (l + r) / 2;
  int t = np++;
  if (depth % 2 == 0) {
    sort(P + l, P + r, lessX);
  } else {
    sort(P + l, P + r, lessY);
  }
  T[t].location = mid;
  T[t].l = makeKDTree(l, mid, depth + 1);
  T[t].r = makeKDTree(mid + 1, r, depth + 1);
  return t;
}

void find(int v, int sx, int tx, int sy, int ty, int depth,
          vector<Point> &ans) {
  int x = P[T[v].location].x;
  int y = P[T[v].location].y;

  if (sx <= x && x <= tx && sy <= y && y <= ty) {
    ans.push_back(P[T[v].location]);
  }

  if (depth % 2 == 0) {
    if (T[v].l != NIL) {
      if (sx <= x) find(T[v].l, sx, tx, sy, ty, depth + 1, ans);
    }
    if (T[v].r != NIL) {
      if (x <= tx) find(T[v].r, sx, tx, sy, ty, depth + 1, ans);
    }
  } else {
    if (T[v].l != NIL) {
      if (sy <= y) find(T[v].l, sx, tx, sy, ty, depth + 1, ans);
    }
    if (T[v].r != NIL) {
      if (y <= ty) find(T[v].r, sx, tx, sy, ty, depth + 1, ans);
    }
  }
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int x, y;
  scanf("%d", &N);
  REP(i, N) {
    scanf("%d %d", &x, &y);
    P[i] = Point(i, x, y);
    T[i].l = T[i].r = T[i].p = NIL;
  }

  np = 0;

  int root = makeKDTree(0, N, 0);

  int q;
  scanf("%d", &q);
  int sx, sy, tx, ty;
  vector<Point> ans;
  REP(i, q) {
    scanf("%d %d %d %d", &sx, &tx, &sy, &ty);
    ans.clear();
    find(root, sx, tx, sy, ty, 0, ans);
    sort(ans.begin(), ans.end());
    for (int j = 0; j < ans.size(); j++) {
      ans[j].print();
    }
    printf("\n");
  }

  return 0;
}
