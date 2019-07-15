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

// Self settings
// clang-format off
#define MAX_N 100000
#define MAX_M 100000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on
int N, M;
int dp[MAX_N + 1];
vector<int> G[MAX_N + 1];

int f(int x)
{
  if (dp[x] > 0) return dp[x];
  int fans = 0;
  for (int i = 0; i < G[x].size(); i++) fans = max(fans, f(G[x][i]) + 1);
  return dp[x] = fans;
}

void solve()
{
  int ans = 0;
  for (int i = 0; i < N; i++) ans = max(ans, f(i));
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
  }
  solve();
  return 0;
}
