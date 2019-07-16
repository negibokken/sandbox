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
#define MAX_N 2999
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

int N;
double p[MAX_N];
double dp[MAX_N + 1][MAX_N + 1];

void solve()
{
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1.0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= N; j++) {
      if (j == 0) {
        dp[i + 1][j] = dp[i][j] * (1.0 - p[i]);
      }
      else {
        dp[i + 1][j] = (dp[i][j - 1] * p[i]) + (dp[i][j] * (1.0 - p[i]));
      }
    }
  }
  int div = ((N + 1) / 2);
  double ans = 0.0;
  for (int i = div; i <= N; i++) ans += dp[N][i];
  printf("%.10f\n", ans);
}

int main(void)
{
  cin >> N;
  REP(i, N) cin >> p[i];
  solve();
  return 0;
}
