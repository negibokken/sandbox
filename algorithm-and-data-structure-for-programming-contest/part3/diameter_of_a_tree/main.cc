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
#define MAX 100000
#define INFTY (1 << 30)

class Edge {
 public:
  int t, w;
  Edge() {}
  Edge(int t, int w) : t(t), w(w) {}
};

vector<Edge> G[MAX];
int n, d[MAX];

bool vis[MAX];
int cnt;

void bfs(int s) {
  REP(i, n) d[i] = INFTY;
  queue<int> Q;
  Q.push(s);
  d[s] = 0;
  int u;
  while (!Q.empty()) {
    u = Q.front();
    Q.pop();
    REP(i, G[u].size()) {
      Edge e = G[u][i];
      if (d[e.t] == INFTY) {
        d[e.t] = d[u] + e.w;
        Q.push(e.t);
      }
    }
  }
}

void solve() {
  bfs(0);

  int maxv = 0;

  int tgt = 0;
  REP(i, n) {
    if (d[i] == INFTY) continue;
    if (maxv < d[i]) {
      maxv = d[i];
      tgt = i;
    }
  }
  bfs(tgt);
  maxv = 0;
  REP(i, n) {
    if (d[i] == INFTY) continue;
    maxv = max(maxv, d[i]);
  }
  cout << maxv << endl;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int s, t, w;
  cin >> n;

  REP(i, n - 1) {
    cin >> s >> t >> w;

    G[s].push_back(Edge(t, w));
    G[t].push_back(Edge(s, w));
  }
  solve();

  return 0;
}
