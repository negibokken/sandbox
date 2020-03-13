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
typedef pair<int, int> P;

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
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)

class Point {
 public:
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  Point operator+(Point p) { return Point(x + p.x, y + p.y); }
  Point operator-(Point p) { return Point(x - p.x, y - p.y); }
  Point operator*(double a) { return Point(a * x, a * y); }
  Point operator/(double a) { return Point(x / a, y / a); }
  double abs() { return sqrt(norm()); }
  double norm() { return x * x + y * y; }
  bool operator<(const Point& p) const { return x != p.x ? x < p.x : y < p.y; }
  bool operator==(const Point& p) const {
    return fabs(x - p.y) < EPS && fabs(y - p.y) < EPS;
  }
};
typedef Point Vector;
double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }
struct Segment {
  Point p1, p2;
};
typedef Segment Line;
class Circle {
 public:
  Point c;
  double r;
  Circle(Point c = Point(), double r = 0.0) : c(c), r(r) {}
};

bool isOrthogonoal(Vector a, Vector b) { return equals(dot(a, b), 0.0); }
bool isOrthogonoal(Point a1, Point a2, Point b1, Point b2) {
  return isOrthogonoal(a1 - a2, b1 - b2);
}
bool isOrthogonoal(Segment s1, Segment s2) {
  return equals(dot(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}

bool isParallel(Vector a, Vector b) { return equals(cross(a, b), 0.0); }
bool isParallel(Point a1, Point a2, Point b1, Point b2) {
  return isParallel(a1 - a2, b1 - b2);
}
bool isParallel(Segment s1, Segment s2) {
  return equals(cross(s1.p2 - s1.p1, s2.p2 - s2.p1), 0.0);
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  Point p[4];
  REP(i, n) {
    REP(j, 4) { cin >> p[j].x >> p[j].y; }
    if (isParallel(p[0], p[1], p[2], p[3])) {
      cout << "2" << endl;
    } else if (isOrthogonoal(p[0], p[1], p[2], p[3])) {
      cout << "1" << endl;
    } else {
      cout << "0" << endl;
    }
  }

  return 0;
}
