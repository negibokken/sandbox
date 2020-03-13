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

#define MAX 10000
int N;
vector<int> G[MAX];
bool visited[MAX];
int prenum[MAX], parent[MAX], lowest[MAX], timer;

void dfs(int current, int prev) {
  prenum[current] = lowest[current] = timer;
  timer++;

  visited[current] = true;
  int next;

  for (int i = 0; i < G[current].size(); i++) {
    next = G[current][i];
    if (!visited[next]) {
      parent[next] = current;
      dfs(next, current);
      lowest[current] = min(lowest[current], lowest[next]);
    } else if (next != prev) {
      lowest[current] = min(lowest[current], prenum[next]);
    }
  }
}

void art_points() {
  REP(i, N) visited[i] = false;
  timer = 1;
  dfs(0, -1);

  set<int> ap;
  int np = 0;
  REP(i, N) {
    int p = parent[i];
    if (p == 0)
      np++;
    else if (prenum[p] <= lowest[i])
      ap.insert(p);
  }

  if (np > 1) ap.insert(0);
  for (set<int>::iterator it = ap.begin(); it != ap.end(); it++) {
    cout << *it << endl;
  }
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int m;
  cin >> N >> m;
  int s, t;
  REP(i, m) {
    cin >> s >> t;
    G[s].push_back(t);
    G[t].push_back(s);
  }

  art_points();

  return 0;
}
