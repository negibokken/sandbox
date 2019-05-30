#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

// Self settings
// clang-format off
#define MAX_N 10000
#define MAX_V 10000
#define INF 1000000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
void myscanf(const char *fmt, int num, int *s, int *v) { REP(i,num) scanf(fmt, &s[i], &v[i]); }
void myscanf(const char *fmt, int num, int *s) { REP(i,num) scanf(fmt, &s[i]); }
// clang-format on

int cost[MAX_V][MAX_V];
int d[MAX_V];
bool used[MAX_V];
int V, E;
int pre[MAX_V];

void dijkstra(int s)
{
  fill(d, d + V, INF);
  fill(used, used + V, false);
  fill(pre, pre + V, -1);

  d[s] = 0;

  while (true) {
    int v = -1;
    for (int u = 0; u < V; u++) {
      if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
    }
    if (v == -1) break;
    used[v] = true;
    for (int u = 0; u < V; u++) {
      if (d[u] > d[v] + cost[v][u]) {
        d[u] = d[v] + cost[v][u];
        pre[u] = v;
      }
    }
  }
}

vector<int> get_path(int t)
{
  vector<int> path;
  for (; t != -1; t = pre[t]) path.push_back(t);
  reverse(path.begin(), path.end());
  return path;
}

int main(void)
{
  scanf("%d %d", &V, &E);
  for (int i = 0; i < V; ++i)
    for (int j = 0; j < V; ++j) cost[i][j] = INF;
  for (int i = 0; i < E; ++i) {
    int v1, v2, c;
    scanf("%d %d %d", &v1, &v2, &c);
    cost[v1][v2] = c;
  }
  dijkstra(0);
  cout << d[6] << endl;
  vector<int> path = get_path(6);
  for (auto v : path) cout << v << endl;

  return 0;
}
