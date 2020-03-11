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

typedef struct Edge {
  int to, cost;
} Edge;

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<Edge> G[n];
  vector<int> d(n), visited(n);
  int id, k, v, c;
  REP(i, n) {
    cin >> id >> k;
    REP(j, k) {
      cin >> v >> c;
      G[id].push_back(Edge{v, c});
    }
  }

  priority_queue<P> que;
  que.push(P(0, 0));
  REP(i, n) d[i] = inf;
  d[0] = 0;
  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int u = p.second, dist = p.first;
    visited[u] = true;
    for (Edge e : G[u]) {
      if (!visited[e.to] || p.first + e.cost < d[e.to]) {
        que.push(P(p.first + e.cost, e.to));
        d[e.to] = min(d[e.to], p.first + e.cost);
      }
    }
  }

  REP(i, n) { printf("%d %d\n", i, d[i]); }

  return 0;
}
