#include <stdio.h>
#include <iostream>
using namespace std;

// Self settings
// clang-format off
#define MAX_N 10000
#define MAX_V 10000
#define MAX_E 10000
#define INF 1000000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
void myscanf(const char *fmt, int num, int *s, int *v) { REP(i,num) scanf(fmt, &s[i], &v[i]); }
void myscanf(const char *fmt, int num, int *s) { REP(i,num) scanf(fmt, &s[i]); }
// clang-format on

struct edge {
  int from, to, cost;
};

edge es[MAX_E];
int d[MAX_V];
int V, E;

void shortest_path(int s)
{
  for (int i = 0; i < V; i++) d[i] = INF;
  d[s] = 0;
  while (true) {
    bool update = false;
    for (int i = 0; i < E; i++) {
      edge e = es[i];
      if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost) {
        d[e.to] = d[e.from] + e.cost;
        update = true;
      }
    }
    if (!update) break;
  }
}

int main(void)
{
  scanf("%d %d", &V, &E);
  for (int i = 0; i < E; ++i) {
    scanf("%d %d %d", &es[i].from, &es[i].to, &es[i].cost);
  }
  shortest_path(0);
  printf("%d\n", d[6]);
  return 0;
}

