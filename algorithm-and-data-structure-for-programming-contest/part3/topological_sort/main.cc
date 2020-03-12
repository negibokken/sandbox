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

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int V, E;
  cin >> V >> E;
  vector<int> G[V], indeg(V), visited(V);
  int s, t;
  REP(i, E) {
    cin >> s >> t;
    G[s].push_back(t);
    indeg[t]++;
  }

  vector<int> out;
  queue<int> que;
  for (int u = 0; u < V; u++) {
    if (indeg[u] == 0 && !visited[u]) {
      que.push(u);
      while (!que.empty()) {
        int v = que.front();
        que.pop();
        visited[v] = true;
        out.push_back(v);
        for (auto vv : G[v]) {
          indeg[vv]--;
          if (indeg[vv] == 0 && !visited[vv]) {
            que.push(vv);
          }
        }
      }
    }
  }

  REP(i, out.size()) {
    if (i) cout << " ";
    cout << out[i];
  }
  cout << endl;

  return 0;
}
