#include <iostream>
using namespace std;

// Self settings
// clang-format off
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
void myscanf(const char *fmt, int num, int *s, int *v) { REP(i,num) scanf(fmt, &s[i], &v[i]); }
void myscanf(const char *fmt, int num, int *s) { REP(i,num) scanf(fmt, &s[i]); }
// clang-format on

#define MAX_N 100000
#define MAX_K 100000

int n;
int a[MAX_N], m[MAX_N];
int K;

int dp[MAX_K + 1];

void solve()
{
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= K; ++j) {
      // Study here
      if (dp[j] >= 0) {
        dp[j] = m[i];
      }
      else if (j < a[i] || dp[j - a[i]] <= 0) {
        dp[j] = -1;
      }
      else {
        dp[j] = dp[j - a[i]] - 1;
      }
    }
  }
  if (dp[K] >= 0)
    printf("Yes\n");
  else
    printf("No\n");
}

int main(void)
{
  scanf("%d", &n);
  const char *fmt = "%d ";
  myscanf(fmt, n, a);
  myscanf(fmt, n, m);
  scanf("%d", &K);
  solve();
  return 0;
}
