#include <stdio.h>
#include <iostream>
using namespace std;

// Self settings
// clang-format off
#define MAX_N 10000
#define MAX_M 10000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
void myscanf(const char *fmt, int num, int *s, int *v) { REP(i,num) scanf(fmt, &s[i], &v[i]); }
void myscanf(const char *fmt, int num, int *s) { REP(i,num) scanf(fmt, &s[i]); }
// clang-format on

int n, m, M;
int dp[MAX_M + 1][MAX_N + 1];

void solve()
{
  dp[0][0] = 1;
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (j - i >= 0) {
        dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % M;
      }
      else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  printf("%d\n", dp[m][n]);
}

int main(void)
{
  scanf("%d %d %d", &n, &m, &M);
  solve();
  return 0;
}
