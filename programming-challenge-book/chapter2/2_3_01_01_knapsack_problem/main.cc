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
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

int n, W;
int w[MAX_N], v[MAX_N];

int dp[MAX_N][MAX_N];

int rec(int i, int j)
{
  if (dp[i][j] >= 0) {
    return dp[i][j];
  }
  int res;
  if (i == n) {
    res = 0;
  }
  else if (j < w[i]) {
    res = rec(i + 1, j);
  }
  else {
    res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
  }
  return dp[i][j] = res;
}

void solve()
{
  memset(dp, -1, sizeof(dp));
  printf("%d\n", rec(0, W));
}

int main(void)
{
  cin >> n >> W;
  REP(i, n) cin >> w[i] >> v[i];
  solve();
  return 0;
}
