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

int N, M, K;
vector<int> G[MAX_N + 5];
vector<int> B[MAX_N + 5];
int ans[MAX_N + 5];
map<P, bool> blocked;

int parN[MAX_N + 5];
int par[MAX_N + 5];
int rnk[MAX_N + 5];

void init(int n) { REP(i, n) par[i] = i, rnk[i] = 0, parN[i] = 1; }

int find(int x) {
  if (par[x] == x)
    return x;
  else
    return par[x] = find(par[x]);
}

void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (rnk[x] < rnk[y]) {
    par[x] = y;
    int temp = parN[x];
    parN[x] += parN[y];
    parN[y] += temp;
  } else {
    par[y] = x;
    int temp = parN[y];
    parN[y] += parN[x];
    parN[x] += temp;
    if (rnk[x] == rnk[y]) rnk[x]++;
  }
}

bool same(int x, int y) { return find(x) == find(y); }

bool contains(int v, int x) {
  // 直近の友達ではない
  return std::find(G[v].begin(), G[v].end(), x) != G[v].end();
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N >> M >> K;
  init(N);

  int a, b;
  REP(i, M) {
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
    unite(a, b);
  }

  int c, d;
  REP(i, K) {
    cin >> c >> d;
    c--, d--;
    B[c].push_back(d);
    B[d].push_back(c);
    blocked[P(c, d)] = true;
    blocked[P(d, c)] = true;
  }

  REP(i, N) {
    if (i) cout << " ";
    int ans = max((parN[find(i)] - 1) - (int)G[i].size(), 0);
    // ブロックされた人たちを削除する
    REP(j, B[i].size()) {
      if (same(i, B[i][j])) ans = max(ans - 1, 0);
    }
    cout << ans;
  }
  cout << endl;

  return 0;
}
