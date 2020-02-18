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
struct Point {
  double x, y;
};

void koch(int n, Point a, Point b) {
  if (n == 0) return;
  Point s, t, u;
  double th = M_PI * 60.0 / 180.0;

  s.x = (2.0 * a.x + 1.0 * b.x) / 3.0;
  s.y = (2.0 * a.y + 1.0 * b.y) / 3.0;
  t.x = (1.0 * a.x + 2.0 * b.x) / 3.0;
  t.y = (1.0 * a.y + 2.0 * b.y) / 3.0;
  u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
  u.y = (t.x - s.x) * sin(th) - (t.y - s.y) * cos(th) + s.y;

  koch(n - 1, a, s);
  printf("%.8f %.8f\n", s.x, s.y);
  koch(n - 1, s, u);
  printf("%.8f %.8f\n", u.x, u.y);
  koch(n - 1, u, t);
  printf("%.8f %.8f\n", t.x, t.y);
  koch(n - 1, t, b);
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  Point a, b;
  int n;
  scanf("%d", &n);
  a.x = 0;
  a.y = 0;
  b.x = 100;
  b.y = 0;

  printf("%.8f %.8f\n", a.x, a.y);
  koch(n, a, b);
  printf("%.8f %.8f\n", b.x, b.y);

  return 0;
}
