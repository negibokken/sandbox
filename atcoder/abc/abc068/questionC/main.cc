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

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N >> M;
  // 0-indexed
  int goal = N - 1;
  vector<vector<int>> G(N);
  REP(i, M)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b), G[b].push_back(a);
  }

  int start = 0;
  queue<int> q;
  q.push(start);

  vector<bool> used(N, false);
  vector<int> cost(N, -inf);
  cost[0] = 2;

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    used[u] = true;
    for (auto v : G[u]) {
      if (!used[v]) q.push(v);
      cost[v] = max(cost[v], cost[u] - 1);
    }
  }

  if (cost[goal] >= 0) {
    cout << "POSSIBLE" << endl;
  }
  else {
    cout << "IMPOSSIBLE" << endl;
  }

  return 0;
}
