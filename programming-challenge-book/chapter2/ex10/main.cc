#include <iostream>
using namespace std;

#define MAX_N 10000
#define MAX_W 10000

int n, W;
int w[MAX_N], v[MAX_N];
int dp[MAX_N + 1][MAX_W + 1];

// int rec(int i, int j)
// {
//   if (dp[i][j] >= 0) {
//     return dp[i][j];
//   }
//
//   int res;
//   if (i == n) {
//     res = 0;
//   }
//   else if (j < w[i]) {
//     res = rec(i + 1, j);
//   }
//   else {
//     res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
//   }
//   return dp[i][j] = res;
// }
//
// void solve()
// {
//   memset(dp, -1, sizeof(dp));
//   printf("%d\n", rec(0, W));
// }

// 動的計画法で解くパターン
void solve()
{
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j <= W; ++j) {
      if (j < w[i]) {
        dp[i][j] = dp[i + 1][j];
      }
      else {
        dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
      }
    }
  }
  printf("%d\n", dp[0][W]);
}

int main(void)
{
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++) {
    scanf("(%d, %d) ", &w[i], &v[i]);
  }
  scanf("%d", &W);
  solve();
  return 0;
}
