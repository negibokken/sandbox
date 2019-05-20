#include <stdio.h>
#include <iostream>
using namespace std;

// Self settings
// clang-format off
#define MAX_N 10000
#define INF 1000000000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
void myscanf(const char *fmt, int num, int *s, int *v) { REP(i,num) scanf(fmt, &s[i], &v[i]); }
void myscanf(const char *fmt, int num, int *s) { REP(i,num) scanf(fmt, &s[i]); }
// clang-format on

int n;
int a[MAX_N];
int dp[MAX_N];

void solve()
{
  int res = 0;
  for (int i = 0; i < n; i++) {
    dp[i] = 1;
    for (int j = 0; j < i; j++)
      if (a[j] < a[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    res = max(res, dp[i]);
  }
  printf("%d\n", res);
}

void solve2()
{
  fill(dp, dp + n, INF);
  for (int i = 0; i < n; i++) {
    *lower_bound(dp, dp + n, a[i]) = a[i];
  }
  printf("%ld\n", lower_bound(dp, dp + n, INF) - dp);
  // printf("%p %p %ld\n", lower_bound(dp, dp + n, INF), dp,
  //        lower_bound(dp, dp + n, INF) - dp);
}

int main(void)
{
  scanf("%d\n", &n);
  const char *fmt = "%d ";
  myscanf(fmt, n, a);
  solve2();
  // REP(i, n) printf("%d ", a[i]);
  return 0;
}

