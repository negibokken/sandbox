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

const int INFTY = (1 << 21);
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

int n, a[MAX_N][MAX_N];

int prim() {
  int u, minv;
  int d[MAX_N], p[MAX_N], color[MAX_N];
  REP(i, n) { d[i] = INFTY, p[i] = -1, color[i] = WHITE; }
  d[0] = 0;

  while (1) {
    minv = INFTY;
    u = -1;
    REP(i, n) {
      if (minv > d[i] && color[i] != BLACK) {
        u = i;
        minv = d[i];
      }
    }
    if (u == -1) break;
    color[u] = BLACK;
    REP(v, n) {
      if (color[v] != BLACK && a[u][v] != INFTY) {
        if (d[v] > a[u][v]) {
          d[v] = a[u][v];
          p[v] = u;
          color[v] = GRAY;
        }
      }
    }
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (p[i] != -1) sum += a[i][p[i]];
  }
  return sum;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;
  REP(i, n) {
    REP(j, n) {
      cin >> a[i][j];
      if (a[i][j] == -1) a[i][j] = INFTY;
    }
  }

  cout << prim() << endl;

  return 0;
}
