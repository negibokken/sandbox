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

typedef pair<int, int> P;
// Self settings
// clang-format off
#define MAX_N 100000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
// clang-format on

int N;
int color[MAX_N];
bool visited[MAX_N];

int main(void)
{
  cin >> N;
  vector<vector<P>> G(N + 1);
  REP(i, N - 1)
  {
    long long u, v, w;
    cin >> u >> v >> w;
    // 0-indexed
    u--, v--;
    G[u].push_back(P(v, w));
    G[v].push_back(P(u, w));
  }

  REP(i, N) visited[i] = false;

  queue<int> q;
  q.push(0);
  color[0] = 0;
  visited[0] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    visited[u] = true;
    for (auto p : G[u]) {
      int v = p.first, w = p.second;
      if (visited[v]) continue;
      // 偶数なら同じ色分けに
      if (w % 2 == 0) {
        color[v] = color[u];
      }
      else {
        color[v] = 1 - color[u];
      }
      q.push(v);
    }
  }

  REP(i, N) cout << color[i] << endl;

  return 0;
}
