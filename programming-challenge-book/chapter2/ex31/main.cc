#include <stdio.h>
#include <iostream>
using namespace std;

// Self settings
// clang-format off
#define MAX_V 10000
#define INF 1000000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
void myscanf(const char *fmt, int num, int *s, int *v) { REP(i,num) scanf(fmt, &s[i], &v[i]); }
void myscanf(const char *fmt, int num, int *s) { REP(i,num) scanf(fmt, &s[i]); }
// clang-format on

int cost[MAX_V][MAX_V];
int mincost[MAX_V];
bool used[MAX_V];
int V, E;

int prim()
{
  for (int i = 0; i < V; ++i) {
    mincost[i] = INF;
    used[i] = false;
  }
  mincost[0] = 0;
  int res = 0;

  while (true) {
    int v = -1;

    for (int u = 0; u < V; ++u) {
      if (!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
    }

    if (v == -1) break;
    used[v] = true;
    res += mincost[v];
    for (int u = 0; u < V; ++u) {
      mincost[u] = min(mincost[u], cost[v][u]);
    }
  }
  return res;
}

int main(void)
{
  cin >> V >> E;
  REP(i, V) REP(j, V) cost[i][j] = INF;

  for (int i = 0; i < E; ++i) {
    int v1, v2, c;
    cin >> v1 >> v2 >> c;
    cost[v1][v2] = c;
  }
  int result = prim();

  cout << result << endl;
  return 0;
}
