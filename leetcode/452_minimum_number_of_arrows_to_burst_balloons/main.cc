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
#include <sstream>
#include <stack>
#include <string>
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
struct Node { int data; Node *left, *right; Node(int data) : data(data), left(NULL), right(NULL) {} };
// clang-format on

class Segment {
  int x1, x2;

 public:
  Segment(int p1, int p2) : x1(p1), x2(p2){};
  Segment* Joint(Segment* s) {
    if (x2 < s->x1) return nullptr;
    int start = x1 < s->x1 ? x1 : s->x1;
    int end = x2 < s->x2 ? s->x2 : x2;
    return new Segment(start, end);
  }
  bool IsEqualTo(Segment s) const { return x1 == s.x1 && x2 == s.x2; }
  bool IsLessThan(Segment s) const { return x1 < s.x1; }
  string str() const {
    stringstream ss;
    ss << "(" << x1 << ", " << x2 << ")";
    return ss.str();
  }
  void print() const { cout << "(" << x1 << ", " << x2 << ")" << endl; }
};

bool operator==(const Segment& lhs, const Segment& rhs) {
  return lhs.IsEqualTo(rhs);
}

bool operator!=(const Segment& lhs, const Segment& rhs) {
  return !(lhs == rhs);
}

bool operator<(const Segment& lhs, const Segment& rhs) {
  return lhs.IsLessThan(rhs);
}
bool operator>(const Segment& lhs, const Segment& rhs) { return !(lhs < rhs); }
bool operator<=(const Segment& lhs, const Segment& rhs) { return !(lhs > rhs); }
bool operator>=(const Segment& lhs, const Segment& rhs) { return rhs <= lhs; }

// 比較
// イコール

static bool mysort(vector<int>& a, vector<int>& b) {
  return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
}
int findMinArrowShots(vector<vector<int>>& points) {
  int cnt = 0, arrow = INT_MIN;
  if (points.size() == 0) {
    return 0;
  }
  sort(points.begin(), points.end(), mysort);
  for (int i = 0; i < points.size(); i++) {
    if (arrow != INT_MIN && points[i][0] <= arrow) {
      continue;
    }
    arrow = points[i][1];
    cnt++;
  }
  return cnt;
}

void testSegment() {
  vector<tuple<P, P, P>> arr = {
      {{1, 1}, {1, 1}, {1, 1}},
      {{1, 2}, {2, 3}, {1, 3}},
      {{1, 4}, {2, 3}, {1, 4}},
      {{2, 3}, {1, 2}, {1, 3}},
  };

  for (auto a : arr) {
    P p1 = get<0>(a);
    P p2 = get<1>(a);
    P p3 = get<2>(a);
    Segment* s1 = new Segment(p1.first, p1.second);
    Segment* s2 = new Segment(p2.first, p2.second);
    Segment* expected = new Segment(p3.first, p3.second);
    Segment* got = s1->Joint(s2);
    if (*got != *expected) {
      printf("expected %s but got %s", expected->str().c_str(),
             got->str().c_str());
    }
  }

  Segment* s1 = new Segment(0, 1);
  Segment* s2 = new Segment(2, 3);
  Segment* got = s1->Joint(s2);
  if (got != nullptr) {
    printf("expected nullptr but got %s", got->str().c_str());
  }
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  testSegment();

  int n;
  cin >> n;
  vector<vector<int>> arr;
  REP(i, n) {
    vector<int> a(2);
    cin >> a[0] >> a[1];
    arr.push_back(a);
  }

  cout << findMinArrowShots(arr) << endl;

  return 0;
}
