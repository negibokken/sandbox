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
#include <stack>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

// Self settings
// clang-format off
#define MAX_N 200005
#define MAX_Q 200005
#define INF 10000000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
// clang-format on

int N, Q;
vector<int> G[MAX_N + 1];
int p[MAX_Q + 1], x[MAX_Q + 1];
int rnk[MAX_N];
ll cost[MAX_N + 1];

void dfs(int u, int c)
{
  cost[u] += c;
  for (int v : G[u]) {
    dfs(v, cost[u]);
  }
}

int main(void)
{
  scanf("%d%d", &N, &Q);

  REP(i, N) rnk[i] = INF;
  rnk[0] = 0;
  // 0-indexed なので 0 が根
  REP(i, N - 1)
  {
    int a, b;
    scanf("%d %d", &a, &b);
    // 0-indexed
    a--, b--;
    if (a < b) {
      G[a].push_back(b);
      rnk[b] = rnk[a] + 1;
    }
    else {
      G[b].push_back(a);
      rnk[a] = rnk[b] + 1;
    }
  }

  REP(i, Q)
  {
    int pp, xx;
    scanf("%d %d", &pp, &x[i]);
    pp--;
    p[i] = pp;
  }

  // 各コストを各頂点に設定する
  for (int i = 0; i < Q; i++) {
    cost[p[i]] += x[i];
  }

  // 各頂点の値を子ノードに伝播する
  dfs(0, 0);

  REP(i, N) printf("%lld%c", cost[i], (i == N - 1 ? '\n' : ' '));

  return 0;
}
