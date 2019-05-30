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
int d[MAX_V][MAX_V];

void warshall_floyd()
{
  for (int k = 0; k < V; ++k) {
    for (int i = 0; i < V; ++i) {
      for (int j = 0; j < V; ++j) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

int main(void)
{
  scanf("%d %d", &V, &E);
  REP(i, V) REP(j, V) d[i][j] = INF;
  for (int i = 0; i < E; ++i) {
    int v1, v2, c;
    scanf("%d %d %d", &v1, &v2, &c);
    d[v1][v2] = c;
  }
  warshall_floyd();
  cout << d[0][6] << endl;
  return 0;
}
