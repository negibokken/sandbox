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
#define INF 10000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

int N, M;
int S, T;

int dist[MAX_N][3];
int sv, tv;

int main(void)
{
  scanf("%d%d", &N, &M);
  int u, v;
  vector<vector<int>> G(N);
  REP(i, M)
  {
    scanf("%d%d", &u, &v);
    // 0-indexed
    G[u - 1].push_back(v - 1);
  }
  scanf("%d%d", &sv, &tv);
  // 0-indexed
  sv = sv - 1, tv = tv - 1;

  REP(i, N) REP(j, 3) dist[i][j] = INF;

  queue<P> que;
  que.push(P(sv, 0));
  dist[sv][0] = 0;
  while (!que.empty()) {
    int v = que.front().first;
    int l = que.front().second;
    que.pop();
    for (int u : G[v]) {
      int nl = (l + 1) % 3;
      if (dist[u][nl] != INF) continue;
      dist[u][nl] = dist[v][l] + 1;
      que.push(P(u, nl));
    }
  }
  int res = dist[tv][0];
  if (res == INF)
    res = -1;
  else
    res /= 3;
  printf("%d\n", res);
  return 0;
}
