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
int n, m, q;

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> m;

  vector<int> G[n];
  vector<int> color(n), visited(n);
  int s, t;
  REP(i, m) {
    cin >> s >> t;
    G[s].push_back(t);
    G[t].push_back(s);
  }
  cin >> q;
  vector<int> qs(m), qt(m);
  REP(i, q) { cin >> qs[i] >> qt[i]; }

  int c = 0;
  for (int i = 0; i < n; i++) {
    if (visited[i]) continue;
    color[i] = c;
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      visited[v] = true;
      color[v] = c;
      for (auto u : G[v]) {
        if (visited[u]) continue;
        q.push(u);
      }
    }
    c++;
  }

  REP(i, q) { cout << (color[qs[i]] == color[qt[i]] ? "yes" : "no") << endl; }

  return 0;
}
