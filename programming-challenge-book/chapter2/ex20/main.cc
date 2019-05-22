#include <stdio.h>
#include <iostream>
using namespace std;

// Self settings
// clang-format off
#define MAX_N 10000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
void myscanf(const char *fmt, int num, int *s, int *v) { REP(i,num) scanf(fmt, &s[i], &v[i]); }
void myscanf(const char *fmt, int num, int *s) { REP(i,num) scanf(fmt, &s[i]); }
// clang-format on

int n, m, M;
int a[MAX_N];

int dp[MAX_N][MAX_N];

void solve()
{
  for (int i = 0; i < n; ++i) {
    dp[i][0] = 1;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= m; ++j) {
      if (j - 1 - a[i] >= 0) {
        dp[i + 1][j] =
            (dp[i + 1][j - 1] + dp[i][j] - dp[i][j - 1 - a[i]] + M) % M;
      }
      else {
        dp[i + 1][j] = dp[i + 1][j - 1] + dp[i][j] % M;
      }
    }
  }
  printf("%d\n", dp[n][m]);
}

int main(void)
{
  scanf("%d %d %d\n", &n, &m, &M);
  const char *fmt = "%d ";
  myscanf(fmt, n, a);
  solve();
  return 0;
}
