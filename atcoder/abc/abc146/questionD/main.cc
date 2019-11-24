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

// Self settings
// clang-format off
#define MAX_N 100000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
ll fact(ll n) { ll res = 1; for(ll i=2;i<=n;++i) res = res * i; return res;}
ll nCr(ll n, ll r) {return (fact(n)/fact(n-r)*fact(r)) ;}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
const int inf = 1 << (30);
// clang-format on

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  int a[MAX_N], b[MAX_N];

  vector<int> G[N];
  int aa, bb;
  REP(i, N - 1) {
    cin >> aa >> bb;
    aa--, bb--;
    a[i] = aa, b[i] = bb;
    G[a[i]].push_back(b[i]);
  }

  vector<bool> visited(N);
  map<int, map<int, bool>> mp;
  map<int, map<int, int>> ans;

  map<int, int> usedColors;
  int colors = 0;
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    // if (visited[u]) continue;
    visited[u] = true;
    for (auto v : G[u]) {
      if (visited[v]) continue;
      q.push(v);
      // u - v
      int cidx = inf;
      // find edge color
      for (int i = usedColors[u]; i < N; i++) {
        if (!mp[u][i]) {
          cidx = i;
          colors = max(colors, cidx);
          usedColors[u]++;
          mp[u][i] = true, mp[v][i] = true;
          break;
        }
      }
      ans[u][v] = cidx;
    }
  }

  cout << colors + 1 << endl;
  REP(i, N - 1) { cout << ans[a[i]][b[i]] + 1 << endl; }

  return 0;
}
