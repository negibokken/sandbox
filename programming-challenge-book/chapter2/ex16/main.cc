#include <iostream>
using namespace std;

// Self settings
// clang-format off
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
void myscanf(const char *fmt, int num, int *s, int *v) { REP(i,num) scanf(fmt, &s[i], &v[i]); }
void myscanf(const char *fmt, int num, int *s) { REP(i,num) scanf(fmt, &s[i]); }
// clang-format on

#define MAX_N 1000000

int n;
int K;
int a[MAX_N];
int m[MAX_N];

bool dp[MAX_N + 1][MAX_N + 1];

void solve()
{
  dp[0][0] = true;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= K; ++j) {
      for (int k = 0; k <= m[i] && k * a[i] <= j; ++k) {
        dp[i + 1][j] |= dp[i][j - k * a[i]];
      }
    }
  }
  if (dp[n][K])
    printf("Yes\n");
  else
    printf("No\n");
}

int main(void)
{
  scanf("%d %d\n", &n, &K);
  const char *fmt = "%d ";
  myscanf(fmt, 3, a);
  myscanf(fmt, 3, m);
  solve();
  return 0;
}
