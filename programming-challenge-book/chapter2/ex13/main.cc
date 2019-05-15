#include <iostream>
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
using namespace std;

#define MAX_N 10000
#define MAX_W 10000

int n, W;
int w[MAX_W], v[MAX_N];
int dp[MAX_N][MAX_W];

void solve2()
{
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= W; ++j) {
      if (j < w[i]) {
        dp[i + 1][j] = dp[i][j];
      }
      else {
        dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - w[i]] + v[i]);
      }
    }
  }
  printf("%d\n", dp[n][W]);
}

void solve()
{
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= W; j++) {
      for (int k = 0; k * w[i] <= j; k++) {
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - k * w[i]] + k * v[i]);
      }
    }
  }
  printf("%d\n", dp[n][W]);
}

int main(void)
{
  scanf("%d %d\n", &n, &W);
  REP(i, n) scanf("(%d, %d) ", &w[i], &v[i]);
  solve();
  return 0;
}
