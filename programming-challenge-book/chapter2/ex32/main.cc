#include <stdio.h>
#include <iostream>
using namespace std;

// Self settings
// clang-format off
#define MAX_N 10000
#define MAX_V 10000
#define MAX_E 10000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
void myscanf(const char *fmt, int num, int *s, int *v) { REP(i,num) scanf(fmt, &s[i], &v[i]); }
void myscanf(const char *fmt, int num, int *s) { REP(i,num) scanf(fmt, &s[i]); }
// clang-format on

struct edge {
  int u, v, cost;
};

int par[MAX_V];
int rnk[MAX_V];

void init_union_find(int n)
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

bool comp(const edge &e1, const edge &e2) { return e1.cost < e2.cost; }

edge es[MAX_E];
int V, E;

int kuskal()
{
  sort(es, es + E, comp);
  init_union_find(V);
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

int main(void)
{
  cin >> V >> E;
  for (int i = 0; i < E; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    es[i] = {u, v, c};
  }
  int res = kuskal();
  cout << res << endl;
  return 0;
}
