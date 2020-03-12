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

int V, E;
int d[MAX_N][MAX_N];

void warshallFloyd() {
  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      if (d[i][k] == inf) continue;
      for (int j = 0; j < V; j++) {
        if (d[k][j] == inf) continue;
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> V >> E;
  int s, t, dd;
  REP(i, V) REP(j, V) {
    if (i == j) {
      d[i][j] = 0;
    } else {
      d[i][j] = inf;
    }
  }
  REP(i, E) {
    cin >> s >> t >> dd;
    d[s][t] = dd;
  }

  warshallFloyd();

  REP(i, V) {
    if (d[i][i] < 0) {
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
    }
  }

  REP(i, V) {
    REP(j, V) {
      if (j) {
        cout << " ";
      }

      if (d[i][j] == inf) {
        cout << "INF";
      } else {
        cout << d[i][j];
      }
    }
    cout << endl;
  }

  return 0;
}
