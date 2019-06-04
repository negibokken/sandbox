#include <stdio.h>
#include <iostream>
using namespace std;

// Self settings
// clang-format off
#define MAX_N 10000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
void myscanf(const char *fmt, int num, int *s, int *v) { REP(i,num) scanf(fmt, &s[i], &v[i]); }
void myscanf(const char *fmt, int num, int *s) { REP(i,num) scanf(fmt, &s[i]); }
// clang-format on

int par[MAX_N];
int rnk[MAX_N];

// Union Find Tree
void init(int n)
{
  for (int i = 0; i < n; ++i) {
    par[i] = i;
    rnk[i] = 0;
  }
}

int find(int x)
{
  if (par[x] == x) {
    return x;
  }
  else {
    // ついでに経路最適化
    return par[x] = find(par[x]);
  }
}

void unite(int x, int y)
{
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (rnk[x] < rnk[y]) {
    par[x] = y;
  }
  else {
    par[y] = x;
    if (rnk[x] == rnk[y]) rnk[x]++;
  }
}

bool same(int x, int y) { return find(x) == find(y); }

// Kruskal
int V, E;
struct edge {
  int u, v, cost;
};
edge es[MAX_N];

bool comp(const edge &e1, const edge &e2) { return e1.cost < e2.cost; }

int kruskal()
{
  sort(es, es + E, comp);
  init(V);
  int res = 0;
  for (int i = 0; i < E; ++i) {
    edge e = es[i];
    if (!same(e.u, e.v)) {
      unite(e.u, e.v);
      res += e.cost;
    }
  }
  return res;
}

// Main
int N, M, R;
int x[MAX_N], y[MAX_N], d[MAX_N];

void solve()
{
  V = N + M;
  E = R;
  for (int i = 0; i < R; ++i) {
    es[i] = (edge){x[i], N + y[i], -d[i]};
  }
  printf("%d\n", 10000 * (N + M) + kruskal());
}

int main(void)
{
  cin >> N >> M >> R;
  for (int i = 0; i < R; i++) {
    cin >> x[i] >> y[i] >> d[i];
  }
  solve();
  return 0;
}
