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
#define MAX_N 100
#define MAX_V 100
#define INF 10000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on
int n, W;
int w[MAX_N], v[MAX_N];
int dp[MAX_N + 1][MAX_N * MAX_V + 1];

void solve()
{
  fill(dp[0], dp[0] + MAX_N * MAX_V + 1, INF);
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= MAX_N * MAX_V; j++) {
      if (j < v[i]) {
        dp[i + 1][j] = dp[i][j];
      }
      else {
        dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
      }
    }
  }
  int res = 0;
  for (int i = 0; i <= MAX_N * MAX_V; i++)
    if (dp[n][i] <= W) res = i;
  cout << res << endl;
}

int main(void)
{
  cin >> n >> W;
  REP(i, n) cin >> w[i] >> v[i];
  solve();
  return 0;
}
