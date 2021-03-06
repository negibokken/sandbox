#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "bokken.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, char> Pc;
typedef pair<int, string> Ps;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
const int dx8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const string dir8[8] = {"U", "RU", "R", "RD", "D", "LD", "L", "LU"};

// Self settings
// clang-format off
#define MAX_N 100000
#define MAX 100000
#define INFTY (1<<30)
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
#define arrin(arr,N) REP(i,(N)) { cin >> arr[i]; }
ll fact(ll n) { ll res = 1; for(ll i=2;i<=n;++i) res = res * i; return res;}
ll nCr(ll n, ll r) {return (fact(n)/fact(n-r)*fact(r)) ;}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
const ll MOD = 1e9+7;
const ll INF = 1LL << 60;
const int inf = 1000100011;
class Point { public: double x, y; Point(double x = 0, double y = 0) : x(x), y(y) {} Point operator+(Point p) { return Point(x + p.x, y + p.y); } Point operator-(Point p) { return Point(x - p.x, y - p.y); } Point operator*(double a) { return Point(a * x, a * y); } Point operator/(double a) { return Point(x / a, y / a); } double abs() { return sqrt(norm()); } double norm() { return x * x + y * y; } bool operator<(const Point& p) const { return x != p.x ? x < p.x : y < p.y; } bool operator==(const Point& p) const { return fabs(x - p.y) < EPS && fabs(y - p.y) < EPS; } };
typedef Point Vector;
double norm(Vector a) { return a.x * a.x + a.y * a.y; }
double abs(Vector a) { return sqrt(norm(a));}
double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }
struct Segment { Point p1, p2; };
typedef Segment Line;
struct Node { int data; Node *left, *right; Node(int data) : data(data), left(NULL), right(NULL) {} };
// clang-format on

// typedef array<int, 3> T;
// struct comp {
//   bool operator()(const T& lhs, const T& rhs) const {
//     return get<0>(lhs) > get<0>(rhs);
//   }
// };
//
// class UnionFind {
//   vector<int> d;
//   vector<int> rnk;
//
//  public:
//   UnionFind(int n) {
//     d.resize(n), rnk.resize(n, 0);
//     for (int i = 0; i < n; i++) d[i] = i;
//   }
//   bool same(int i, int j) { return find(i) == find(j); }
//   int find(int i) {
//     if (d[i] == i) {
//       return i;
//     } else {
//       return d[i] = find(d[i]);
//     }
//   }
//   void unite(int i, int j) {
//     int x = find(i);
//     int y = find(j);
//     if (x == y) return;
//     if (rnk[x] < rnk[y]) {
//       d[x] = y;
//     } else {
//       d[y] = x;
//       if (rnk[x] == rnk[y]) rnk[x]++;
//     }
//   }
// };
//
// int minCostConnectPoints(vector<vector<int>>& points) {
//   UnionFind uf(points.size());
//   priority_queue<T, vector<T>, comp> pq;
//   for (int i = 0; i < points.size(); i++) {
//     for (int j = i + 1; j < points.size(); j++) {
//       int cost =
//           abs(points[i][0] - points[j][0]) + abs(points[i][1] -
//           points[j][1]);
//       pq.push({cost, i, j});
//     }
//   }
//   long long ans = 0;
//   while (!pq.empty()) {
//     array<int, 3> a = pq.top();
//     a[0];
//     if (!uf.same(u, v)) {
//       ans += cost;
//       uf.unite(u, v);
//     }
//     pq.pop();
//   }
//   return ans;
// }
int find(vector<int>& ds, int i) {
  return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
}
int minCostConnectPoints(vector<vector<int>>& ps) {
  int n = ps.size(), res = 0;
  vector<int> ds(n, -1);
  vector<array<int, 3>> arr;
  for (auto i = 0; i < n; ++i)
    for (auto j = i + 1; j < n; ++j) {
      arr.push_back(std::array<int, 3>{
          {abs(ps[i][0] - ps[j][0]) + abs(ps[i][1] - ps[j][1]), i, j}});
    }
  make_heap(begin(arr), end(arr), greater<array<int, 3>>());
  while (!arr.empty()) {
    pop_heap(begin(arr), end(arr), greater<array<int, 3>>());
    array<int, 3> a = arr.back();
    arr.pop_back();
    i = find(ds, i), j = find(ds, j);
    if (i != j) {
      res += dist;
      ds[i] += ds[j];
      ds[j] = i;
      if (ds[i] == -n) break;
    }
  }
  return res;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n;
  cin >> n;
  vector<vector<int>> arr(n);

  REP(i, n) {
    vector<int> point(2);
    REP(j, 2) { cin >> point[j]; }
    arr[i] = point;
  }

  cout << minCostConnectPoints(arr) << endl;

  return 0;
}
