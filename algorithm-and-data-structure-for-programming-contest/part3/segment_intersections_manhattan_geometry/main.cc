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
#include <stack>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

// Self settings
// clang-format off
#define BOTTOM 0
#define LEFT 1
#define RIGHT 2
#define TOP 3
#define MAX_N 100000
#define MAX 100000
#define INFTY (1<<30)
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
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
// clang-format on

class EndPoint {
 public:
  Point p;
  int seg, st;
  EndPoint() {}
  EndPoint(Point p, int seg, int st) : p(p), seg(seg), st(st) {}

  bool operator<(const EndPoint& ep) const {
    if (p.y == ep.p.y) {
      return st < ep.st;
    } else {
      return p.y < ep.p.y;
    }
  }
};

EndPoint EP[2 * 10000];

int manhattanIntersection(vector<Segment> S) {
  int n = S.size();

  for (int i = 0, k = 0; i < n; i++) {
    if (S[i].p1.y == S[i].p2.y) {
      if (S[i].p1.x > S[i].p2.x) {
        swap(S[i].p1, S[i].p2);
      } else if (S[i].p1.y > S[i].p2.y) {
        swap(S[i].p1, S[i].p2);
      }
    }

    if (S[i].p1.y == S[i].p2.y) {
      EP[k++] = EndPoint(S[i].p1, i, LEFT);
      EP[k++] = EndPoint(S[i].p2, i, RIGHT);
    } else {
      EP[k++] = EndPoint(S[i].p1, i, BOTTOM);
      EP[k++] = EndPoint(S[i].p2, i, TOP);
    }
  }

  sort(EP, EP + (2 * n));

  set<int> BT;
  BT.insert(10000001);
  int cnt = 0;

  for (int i = 0; i < 2 * n; i++) {
    if (EP[i].st == TOP) {
      BT.erase(EP[i].p.x);
    } else if (EP[i].st == BOTTOM) {
      BT.insert(EP[i].p.x);
    } else if (EP[i].st == LEFT) {
      set<int>::iterator b = BT.lower_bound(S[EP[i].seg].p1.x);
      set<int>::iterator e = BT.upper_bound(S[EP[i].seg].p2.x);
      cnt += distance(b, e);
    }
  }
  return cnt;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  vector<Segment> s;
  int n;
  cin >> n;
  REP(i, n) {
    Segment sg;
    cin >> sg.p1.x >> sg.p1.y >> sg.p2.x >> sg.p2.y;
    s.push_back(sg);
  }

  int ans = manhattanIntersection(s);
  cout << ans << endl;

  return 0;
}
