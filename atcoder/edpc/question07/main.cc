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
#define MAX_M 100000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on
int N, M;
int dp[MAX_N + 1];
vector<int> G[MAX_N + 1];
queue<int> que;
int S[MAX_N];

void solve()
{
  // 始点候補を追加する
  for (int i = 0; i < N; i++) {
    if (S[i] == 0) que.push(i);
  }

  int ans = 0;
  while (!que.empty()) {
    int c = que.front();
    que.pop();
    queue<P> q;
    for (int i = 0; i < G[c].size(); i++) {
      // 次の頂点が高々 1 しか進んでないならすでに探索済みの
      // 経路より大きくなることはない
      if (dp[G[c][i]] >= 0 + 1) continue;
      q.push(P(c, G[c][i]));
    }
    while (!q.empty()) {
      P p = q.front();
      q.pop();
      // 探索済みにもかかわらずこれから探索する経路がそれより
      // 同じか短いなら探索を途中でやめる
      if (dp[p.second] >= dp[p.first] + 1) continue;
      dp[p.second] = max(dp[p.second], dp[p.first] + 1);
      for (int i = 0; i < G[p.second].size(); i++) {
        // 次の頂点がすでに探索済みで今よりも長いか同じ経路で探索されてきてる
        // なら push しないでおく
        if (dp[G[p.second][i]] >= dp[p.second] + 1) continue;
        q.push(P(p.second, G[p.second][i]));
      }
    }
  }

  for (int i = 0; i < N + 1; i++) ans = max(ans, dp[i]);
  cout << ans << endl;
}

int main(void)
{
  scanf("%d%d", &N, &M);
  int x, y;
  REP(i, M)
  {
    scanf("%d%d", &x, &y);
    x--, y--;
    G[x].push_back(y);
    // 入次 0 のものがかならず最長パスに含まれている
    // (最長パスの途中からのパスは絶対に最長パスではない)
    // ループもないから入次が0の点がかならず存在する
    S[y]++;
  }
  solve();
  return 0;
}
