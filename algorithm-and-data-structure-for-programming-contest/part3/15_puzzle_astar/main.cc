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

#define N 4
#define N2 16
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {1, 0, -1, 0};
static const char dir[4] = {'r', 'u', 'l', 'd'};
int MDT[N2][N2];

struct Puzzle {
  int f[N2], space, MD;
  int cost;

  bool operator<(const Puzzle& p) const {
    for (int i = 0; i < N2; i++) {
      if (f[i] == p.f[i]) continue;
      return f[i] < p.f[i];
    }
    return false;
  }
};

struct State {
  Puzzle puzzle;
  int estimated;
  bool operator<(const State& s) const { return estimated > s.estimated; }
};

int getAllMD(Puzzle pz) {
  int sum = 0;
  REP(i, N2) {
    if (pz.f[i] == N2) continue;
    sum += MDT[i][pz.f[i] - 1];
  }
  return sum;
}

int astar(Puzzle s) {
  priority_queue<State> PQ;
  s.MD = getAllMD(s);
  s.cost = 0;
  map<Puzzle, bool> V;
  Puzzle u, v;
  State initial;
  initial.puzzle = s;
  initial.estimated = getAllMD(s);
  PQ.push(initial);

  while (!PQ.empty()) {
    State st = PQ.top();
    PQ.pop();
    u = st.puzzle;
    if (u.MD == 0) return u.cost;
    V[u] = true;
    int sx = u.space / N;
    int sy = u.space % N;

    REP(r, 4) {
      int tx = sx + dx[r];
      int ty = sy + dy[r];
      if (tx < 0 || ty < 0 || tx >= N || ty >= N) continue;
      v = u;
      v.MD -= MDT[tx * N + ty][v.f[tx * N + ty] - 1];
      v.MD += MDT[sx * N + sy][v.f[tx * N + ty] - 1];

      swap(v.f[sx * N + sy], v.f[tx * N + ty]);
      v.space = tx * N + ty;
      if (!V[v]) {
        v.cost++;
        State news;
        news.puzzle = v;
        news.estimated = v.cost + v.MD;
        PQ.push(news);
      }
    }
  }
  return -1;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  REP(i, N2) REP(j, N2) { MDT[i][j] = abs(i / N - j / N) + abs(i % N - j % N); }

  Puzzle in;
  REP(i, N2) {
    cin >> in.f[i];
    if (in.f[i] == 0) {
      in.f[i] = N2;
      in.space = i;
    }
  }

  cout << astar(in) << endl;

  return 0;
}
