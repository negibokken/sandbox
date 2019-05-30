#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Self settings
// clang-format off
#define MAX_V 10000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define INF 100000
void myscanf(const char *fmt, int num, int *s, int *v) { REP(i,num) scanf(fmt, &s[i], &v[i]); }
void myscanf(const char *fmt, int num, int *s) { REP(i,num) scanf(fmt, &s[i]); }
// clang-format on

struct edge {
  int to, cost;
};
typedef pair<int, int> P;
int V, E;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s)
{
  priority_queue<P, vector<P>, greater<P>> que;
  fill(d, d + V, INF);
  d[s] = 0;
  que.push(P(0, s));

  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (d[v] < p.first) continue;
    for (int i = 0; i < G[v].size(); ++i) {
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}

int main(void)
{
  scanf("%d %d", &V, &E);
  for (int i = 0; i < E; ++i) {
    int v1, v2, c;
    scanf("%d %d %d", &v1, &v2, &c);
    edge e = {v2, c};
    G[v1].push_back(e);
  }
  dijkstra(0);
  cout << d[6] << endl;
  return 0;
}
