#include <iostream>
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
using namespace std;

// clang-format off
void myscanf(const char *fmt, int num, int *s, int *v) { REP(i,num) scanf(fmt, &s[i], &v[i]); }
// clang-format on

#define MAX_N 10000
#define MAX_V 100
#define INF 1000000

int n, W;
int w[MAX_N], v[MAX_N];
int dp[MAX_N + 1][MAX_N * MAX_V + 1];

void solve()
{
  fill(dp[0], dp[0] + MAX_N * MAX_V + 1, INF);
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= MAX_N * MAX_V; ++j) {
      if (j < v[i]) {
        dp[i + 1][j] = dp[i][j];
      }
      else {
        dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
      }
    }
  }
  int res = 0;
  for (int i = 0; i <= MAX_N * MAX_V; ++i) {
    if (dp[n][i] <= W) res = i;
  }
  printf("%d\n", res);
}

int main(void)
{
  scanf("%d %d\n", &n, &W);
  const char *fmt = "(%d, %d) ";
  myscanf(fmt, n, w, v);
  // REP(i, n) printf("(%d, %d)\n", w[i], v[i]);
  solve();
  return 0;
}
