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
#define LIMIT 100

const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {1, 0, -1, 0};
static const char dir[4] = {'d', 'l', 'u', 'r'};
int MDT[N2][N2];

struct Puzzle {
  int f[N2], space, MD;
};

Puzzle state;
int limit;
int path[LIMIT];

int getAllMD(Puzzle pz) {
  int sum = 0;
  for (int i = 0; i < N2; i++) {
    if (pz.f[i] == N2) continue;
    sum += MDT[i][pz.f[i] - 1];
  }
  return sum;
}

bool isSolved() {
  for (int i = 0; i < N2; i++) {
    if (state.f[i] != i + 1) return false;
  }
  return true;
}

bool dfs(int depth, int prev) {
  if (state.MD == 0) return true;
  if (depth + state.MD > limit) return false;

  int sx = state.space / N;
  int sy = state.space % N;
  Puzzle tmp;

  for (int r = 0; r < 4; r++) {
    int tx = sx + dx[r];
    int ty = sy + dy[r];
    if (tx < 0 || ty < 0 || tx >= N || ty >= N) continue;
    //
    if (max(prev, r) - min(prev, r) == 2) continue;
    tmp = state;
    state.MD -= MDT[tx * N + ty][state.f[tx * N + ty] - 1];
    state.MD += MDT[sx * N + sy][state.f[tx * N + ty] - 1];
    swap(state.f[tx * N + ty], state.f[sx * N + sy]);
    state.space = tx * N + ty;
    if (dfs(depth + 1, r)) {
      path[depth] = r;
      return true;
    }
    state = tmp;
  }
  return false;
}

string iterative_deepening(Puzzle in) {
  in.MD = getAllMD(in);
  for (limit = in.MD; limit <= LIMIT; limit++) {
    state = in;
    if (dfs(0, -100)) {
      string ans = "";
      REP(i, limit) ans += dir[path[i]];
      return ans;
    }
  }
  return "unsolvable";
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  REP(i, N2) {
    REP(j, N2) { MDT[i][j] = abs(i / N - j / N) + abs(i % N - j % N); }
  }

  Puzzle in;
  for (int i = 0; i < N2; i++) {
    cin >> in.f[i];
    if (in.f[i] == 0) {
      in.f[i] = N2;
      in.space = i;
    }
  }

  string ans = iterative_deepening(in);
  cout << ans.size() << endl;

  return 0;
}
