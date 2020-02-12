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
#define MAX_N 300
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
int N;

struct edge {
  int to, cap, rev;
};
vector<edge> G[MAX_N];

void add_edge(int from, int to, int cap) {
  G[from].push_back((edge){to, cap, (int)G[to].size()});
  G[to].push_back((edge){from, 0, (int)G[from].size() - 1});
}

bool used[MAX_N];

int dfs(int v, int t, int f) {
  if (v == t) return f;
  used[v] = true;
  for (int i = 0; i < G[v].size(); i++) {
    edge &e = G[v][i];
    if (!used[e.to] && e.cap > 0) {
      int d = dfs(e.to, t, min(f, e.cap));
      if (d > 0) {
        e.cap -= d;
        G[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}

int max_flow(int s, int t) {
  int flow = 0;
  for (;;) {
    memset(used, 0, sizeof(used));
    int f = dfs(s, t, inf);
    if (f == 0) return flow;
    flow += f;
  }
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N;
  vector<int> a(N), b(N), c(N), d(N);
  REP(i, N) cin >> a[i] >> b[i];
  REP(i, N) cin >> c[i] >> d[i];

  // 点が 2 x 2 (N=2) だとすると
  // 0: soruce
  // 1: 赤1
  // 2: 赤2
  // 3: 青1
  // 4: 青2
  // 5: sink

  // 点が 3 x 3 (N=3) だとすると
  // 0: soruce
  // 1: 赤1
  // 2: 赤2
  // 3: 赤3
  // 4: 青1
  // 5: 青2
  // 6: 青3
  // 7: sink

  REP(i, N) add_edge(0, i + 1, 1);
  REP(i, N) add_edge(N + i + 1, 2 * N + 1, 1);

  // 0 と 2N+1 をそれぞれ s と t とする
  REP(i, N) {
    REP(j, N) {
      // 赤 a[i] < c[j] かつ,b[i] < d[i]のとき、i + 1 と N + j + 1 に辺を張る
      if (a[i] < c[j] && b[i] < d[j]) {
        add_edge(i + 1, N + j + 1, 1);
      }
    }
  }
  printf("%d\n", max_flow(0, 2 * N + 1));
  return 0;
}
