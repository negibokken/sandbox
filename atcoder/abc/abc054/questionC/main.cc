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

int n, m;
int ans = 0;

bool isAll(vector<bool> visited) {
  for (auto v : visited)
    if (!v) return false;
  return true;
}

void dfs(int cur, vector<vector<int>> G, vector<bool> visited, int visnum) {
  visited[cur] = true;
  for (auto child : G[cur]) {
    if (visited[child]) continue;
    visnum++;
    dfs(child, G, visited, visnum);
  }
  if (isAll(visited)) ans++;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  vector<vector<int>> G(n);
  int a, b;
  // 0-indexed
  REP(i, m) {
    cin >> a >> b;
    G[a - 1].push_back(b - 1);
    G[b - 1].push_back(a - 1);
  }

  vector<bool> visited(n);
  dfs(0, G, visited, 1);
  cout << ans << endl;

  return 0;
}
