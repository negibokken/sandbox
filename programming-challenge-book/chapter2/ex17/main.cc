#include <stdio.h>
#include <iostream>
using namespace std;

// Self settings
// clang-format off
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define MAX_N 10000
#define MAX_K 10000
void myscanf(const char *fmt, int num, int *s, int *v) { REP(i,num) scanf(fmt, &s[i], &v[i]); }
void myscanf(const char *fmt, int num, int *s) { REP(i,num) scanf(fmt, &s[i]); }
// clang-format on

int n;
int a[MAX_N], m[MAX_N];
int K;
int dp[MAX_N + 1][MAX_K + 1];

// void solve()
// {
//   dp[0][0] = true;
//   for (int i = 0; i < n; ++i) {
//     for (int j = 0; j <= K; ++j) {
//       for (int k = 0; k <= m[i] && k * a[i] <= j; ++k) {
//         dp[i + 1][j] |= dp[i][j - k * a[i]];
//       }
//     }
//   }
//   if (dp[n][K])
//     printf("Yes\n");
//   else
//     printf("No\n");
// }
void solve()
{
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= K; ++j) {
      if (dp[i][j] >= 0) {
        dp[i + 1][j] = m[i];
      }
      else if (j < a[i] || dp[i + 1][j] <= 0) {
        dp[i + 1][j] = -1;
      }
      else {
        dp[i + 1][j] = dp[i + 1][j - a[i]] - 1;
      }
    }
  }
  if (dp[n][K] >= 0)
    printf("Yes\n");
  else
    printf("No\n");
}

int main(void)
{
  scanf("%d %d\n", &n, &K);
  const char *fmt = "%d ";
  myscanf(fmt, n, a);
  myscanf(fmt, n, m);
  solve();
  return 0;
}

