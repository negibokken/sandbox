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
#include <stack>
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

int t = 1;
int N;
vector<int> G[MAX_N + 1];
int visited[MAX_N + 1], d[MAX_N + 1], f[MAX_N + 1], idx[MAX_N + 1];

int next(int v) {
  for (int i = 0; i < G[v].size(); i++) {
    if (visited[G[v][i]]) continue;
    return G[v][i];
  }
  return -1;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N;

  int id, e, v;
  REP(i, N) {
    cin >> id;
    cin >> e;
    REP(j, e) {
      cin >> v;
      G[id].push_back(v);
    }
  }

  int t = 1;
  stack<int> st;
  st.push(1);
  while (!st.empty()) {
    int v = st.top();
    if (!visited[v]) d[v] = t++;
    visited[v] = true;
    int u = v;
    while ((u = next(u)) != -1) {
      if (visited[u]) continue;
      st.push(u);
      visited[u] = true;
      d[u] = t++;
    }
    int finished = st.top();
    st.pop();
    f[finished] = t++;
  }

  for (int i = 1; i <= N; i++) {
    printf("%d %d %d\n", i, d[i], f[i]);
  }

  return 0;
}
