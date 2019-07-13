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

// Self settings
// clang-format off
#define MAX_N 100
#define MAX_V 1000
// #define INF 1000000001
#define INF LLONG_MAX
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

ll N, W;
// ll dp[MAX_N + 1][MAX_V + 1];
ll dp[MAX_N + 1][MAX_N * MAX_V + 1];
ll w[MAX_N], v[MAX_N];

void solve()
{
  REP(i, N + 1) REP(j, MAX_N * MAX_V + 1) dp[i][j] = INF;
  dp[0][0] = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= MAX_N * MAX_V + 1; j++) {
      if (j < v[i] || dp[i][j - v[i]] == INF) {
        dp[i + 1][j] = dp[i][j];
      }
      else {
        dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
      }
    }
  }
  ll ans = 0;
  // REP(j, MAX_V + 1) cout << dp[N][j] << " ";
  REP(j, MAX_N * MAX_V + 1) if (dp[N][j] <= W) ans = j;
  cout << ans << endl;
}

int main(void)
{
  cin >> N >> W;
  REP(i, N) cin >> w[i] >> v[i];
  solve();
  return 0;
}
