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
#define MAX_M 30
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

int n, m, a, b;
int t[MAX_N];
int d[MAX_M][MAX_M];

double dp[1 << MAX_M][MAX_M];

string printb(int n, int x) {
  string s = "";
  while (n > 0) {
    int b = n % 2;
    s += to_string(b);
    n /= 2;
  }
  while (s.size() < x) {
    s += "0";
  }
  reverse(s.begin(), s.end());
  return s;
}

void solve() {
  for (int i = 0; i <= 1 << n; i++) {
    fill(dp[i], dp[i] + m, inf);
  }
  dp[(1 << n) - 1][a - 1] = 0;
  double res = inf;
  for (int S = (1 << n) - 1; S >= 0; S--) {
    res = min(res, dp[S][b - 1]);
    for (int v = 0; v < m; v++) {
      for (int i = 0; i < n; i++) {
        if (S >> i & 1) {
          for (int u = 0; u < m; u++) {
            if (d[v][u] >= 0) {
              dp[S & ~(1 << i)][u] =
                  min(dp[S & ~(1 << i)][u], dp[S][v] + (double)d[v][u] / t[i]);
            }
          }
        }
      }
    }
  }
  if (res == inf) {
    printf("Impossible\n");
  } else {
    printf("%.3f\n", res);
  }
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  cin >> n >> m >> a >> b;
  REP(i, n) cin >> t[i];
  int u, v, c;
  REP(i, m) REP(j, m) d[i][j] = inf;
  REP(i, m) {
    cin >> u >> v >> c;
    d[u][v] = c;
    d[v][u] = c;
  }
  solve();

  return 0;
}
