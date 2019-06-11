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

int n, W;
int w[MAX_N], v[MAX_N];
int dp[MAX_N][MAX_N];

// 方針
// 0 から順番に i 番目以降の品物を使って重さ j を実現する
// ときに最大となる w を算出する
void solve()
{
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j <= W; j++) {
      if (j < w[i]) {
        dp[i][j] = dp[i + 1][j];
      }
      else {
        dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
      }
    }
  }
  cout << dp[0][W] << endl;
}

int main(void)
{
  cin >> n >> W;
  for (int i = 0; i < n; i++) {
    cin >> w[i] >> v[i];
  }
  solve();
  return 0;
}
