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
int n, q;
int A[MAX_N], rnk[MAX_N];

void init(int n) { REP(i, n) A[i] = i, rnk[i] = 0; }

int find(int x) {
  if (x == A[x]) {
    return x;
  }
  return A[x] = find(A[x]);
}

void unite(int x, int y) {
  int u = find(x);
  int v = find(y);
  if (u == v) return;
  if (rnk[u] < rnk[v]) {
    A[u] = v;
  } else {
    A[v] = u;
    if (rnk[u] == rnk[y]) rnk[u]++;
  }
}

int same(int x, int y) { return find(x) == find(y); }

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> q;
  init(n);
  int com, x, y;
  REP(i, q) {
    cin >> com >> x >> y;
    if (com == 0) {
      unite(x, y);
    } else if (com == 1) {
      cout << (same(x, y) ? "1" : "0") << endl;
    }
  }

  return 0;
}
