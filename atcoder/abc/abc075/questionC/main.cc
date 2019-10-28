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
const int inf = 1 << 30;
// clang-format on

int N, M;
int A[MAX_N], B[MAX_N];

bool isDeletedEdge(int u, int v, int edgeId)
{
  return (A[edgeId] == u && B[edgeId] == v) ||
         (A[edgeId] == v && B[edgeId] == u);
}

bool isConnected(int deletedEdge, vector<vector<int>> G)
{
  vector<bool> visited(G.size(), false);
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    visited[u] = true;
    for (auto v : G[u]) {
      if (isDeletedEdge(u, v, deletedEdge)) continue;
      if (visited[v]) continue;
      q.push(v);
    }
  }
  REP(i, G.size()) if (!visited[i]) return false;
  return true;
}

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N >> M;
  vector<vector<int>> G(N);
  REP(i, M)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    A[i] = a, B[i] = b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  int cnt = 0;
  for (int i = 0; i < M; i++) {
    if (!isConnected(i, G)) cnt++;
  }
  cout << cnt << endl;

  return 0;
}
