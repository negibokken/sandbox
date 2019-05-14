#include <iostream>
using namespace std;

#define MAX_W 10000
#define MAX_N 10000

int n, W;
int w[MAX_W], v[MAX_N];
int dp[MAX_N + 1][MAX_W + 1];

void solve()
{
  for (int i = 0; i < n; i++) {
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
  for (int i = 0; i < n; ++i) {
    scanf("(%d, %d) ", &w[i], &v[i]);
  }

  solve();
  return 0;
}
