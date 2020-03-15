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
#define MAX_N 100000
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
#define MAX 8
#define N 8
#define FREE -1
#define NOT_FREE 1

int k, row[MAX + 1], col[MAX + 1];
int dpos[2 * MAX - 1], dneg[2 * MAX - 1];
bool X[N][N];

void initialize() {
  REP(i, N) { row[i] = FREE, col[i] = FREE; }
  REP(i, 2 * N - 1) { dpos[i] = FREE, dneg[i] = FREE; }
}

void printBoard() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (X[i][j]) {
        if (row[i] != j) return;
      }
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << ((row[i] == j) ? "Q" : ".");
    }
    cout << endl;
  }
}

void recursive(int i) {
  if (i == N) {
    printBoard();
    return;
  }

  for (int j = 0; j < N; j++) {
    if (NOT_FREE == col[j] || NOT_FREE == dpos[i + j] ||
        NOT_FREE == dneg[i - j + N - 1]) {
      continue;
    }
    row[i] = j;
    col[j] = dpos[i + j] = dneg[i - j + N - 1] = NOT_FREE;
    recursive(i + 1);
    row[i] = col[j] = dpos[i + j] = dneg[i - j + N - 1] = FREE;
  }
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  initialize();

  REP(i, N) REP(j, N) X[i][j] = false;

  int k;
  cin >> k;
  REP(i, k) {
    int r, c;
    cin >> r >> c;
    X[r][c] = true;
  }

  recursive(0);

  return 0;
}
