#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

// Self settings
// clang-format off
#define MAX_N 10000
#define MAX_V 10000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
void myscanf(const char *fmt, int num, int *s, int *v) { REP(i,num) scanf(fmt, &s[i], &v[i]); }
void myscanf(const char *fmt, int num, int *s) { REP(i,num) scanf(fmt, &s[i]); }
// clang-format on

vector<int> G[MAX_V];
int V, E;

int color[MAX_V];

bool dfs(int v, int c)
{
  color[v] = c;
  cout << "G[v].size(): " << G[v].size() << endl;
  for (int i = 0; i < G[v].size(); ++i) {
    cout << "G[v][i]: " << G[v][i] << endl;
    if (color[G[v][i]] == c) return false;
    if (color[G[v][i]] == 0 && !dfs(G[v][i], -c)) return false;
  }
  return true;
}

void solve()
{
  for (int i = 0; i < V; i++) {
    if (color[i] == 0) {
      if (!dfs(i, 1)) {
        printf("No\n");
        return;
      }
    }
  }
  printf("Yes\n");
  for (int i = 0; i < V; ++i) {
    cout << color[i] << endl;
  }
}

int main(void)
{
  scanf("%d %d", &V, &E);
  int v1, v2;
  for (int i = 0; i < E; ++i) {
    scanf("%d %d", &v1, &v2);
    G[v1][v2] = 0;
  }
  solve();
  return 0;
}
