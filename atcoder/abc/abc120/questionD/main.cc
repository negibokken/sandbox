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
// clang-format on

int N, M;
int A[MAX_N], B[MAX_N];
int sz[MAX_N];
int par[MAX_N];
int rnk[MAX_N];

void init(int n) { REP(i, n) par[i] = i, rnk[i] = 0, sz[i] = 1; }

int find(int x) { return (par[x] == x) ? x : par[x] = find(par[x]); }

int size(int x)
{
  int p = find(x);
  return sz[p];
}

void unite(int x, int y)
{
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (rnk[x] > rnk[y]) {
    sz[y] += size(x);
    par[x] = y;
  }
  else {
    sz[x] += size(y);
    par[y] = x;
    if (rnk[x] == rnk[y]) rnk[x]++;
  }
}

bool same(int x, int y) { return find(x) == find(y); }

void solve()
{
  init(N);
  ll ans[MAX_N + 1];
  ans[M] = (N * (N - 1)) / 2;
  for (int i = M - 1; i >= 0; i--) {
    int u = A[i], v = B[i];
    if (same(u, v)) {
      ans[i] = ans[i + 1];
    }
    else {
      ans[i] = ans[i + 1] - size(u) * size(v);
    }
    unite(u, v);
  }
  REP(i, M) cout << ans[i + 1] << (i == M - 1 ? "\n" : " ");
  // REP(i, M) cout << ans[i + 1] << endl;
}

int main(void)
{
  cin >> N >> M;
  REP(i, M)
  {
    int u, v;
    cin >> u >> v;
    // 0-indexed
    u--, v--;
    A[i] = u, B[i] = v;
  }
  solve();
  return 0;
}
