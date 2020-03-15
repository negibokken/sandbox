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

// Self settings
// clang-format off
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
#define N 3
#define N2 9

struct Puzzle {
  int f[N2];
  int space;
  string path;

  bool operator<(const Puzzle& p) const {
    for (int i = 0; i < N2; i++) {
      if (f[i] == p.f[i]) continue;
      return f[i] > p.f[i];
    }
    return false;
  }
};
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
static const char dir[4] = {'u', 'l', 'd', 'r'};

bool isTarget(Puzzle p) {
  for (int i = 0; i < N2; i++) {
    if (p.f[i] != (i + 1)) return false;
  }
  return true;
}

string bfs(Puzzle s) {
  queue<Puzzle> Q;
  map<Puzzle, bool> V;
  Puzzle u, v;
  s.path = "";
  Q.push(s);
  V[s] = true;

  while (!Q.empty()) {
    u = Q.front();
    Q.pop();
    if (isTarget(u)) return u.path;
    int sx = u.space / N;
    int sy = u.space % N;
    for (int r = 0; r < 4; r++) {
      int tx = sx + dx[r];
      int ty = sy + dy[r];
      if (tx < 0 || ty < 0 || tx >= N || ty >= N) continue;
      v = u;
      swap(v.f[u.space], v.f[tx * N + ty]);
      v.space = tx * N + ty;
      if (!V[v]) {
        V[v] = true;
        v.path += dir[r];
        Q.push(v);
      }
    }
  }
  return "unsolvable";
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  Puzzle in;

  REP(i, N2) {
    cin >> in.f[i];
    if (in.f[i] == 0) {
      in.f[i] = N2;
      in.space = i;
    }
  }
  string ans = bfs(in);
  cout << ans.size() << endl;

  return 0;
}
