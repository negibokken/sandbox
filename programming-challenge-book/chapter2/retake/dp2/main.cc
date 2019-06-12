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

int n, m;
char s1[MAX_N], s2[MAX_N];
int dp[MAX_N + 1][MAX_N + 1];

void show() { REP(i, n) REP(j, m) cout << dp[i][j] << endl; }

// s1, i: abcd
// s2, j: becd
// i\j 0 1 2 3 4
// 0   0 0 0 0 0
// 1   0 0 0 0 0
// 2   0 1 1 1 1
// 3   0 1 1 2 2
// 4   0 1 1 2 3
// i 番目までで
void solve()
{
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s1[i] == s2[j]) {
        dp[i + 1][j + 1] = dp[i][j] + 1;
      }
      else {
        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i + 1][j]);
      }
    }
  }
  cout << dp[n][m] << endl;
}

int main(void)
{
  cin >> n >> m;
  cin >> s1 >> s2;
  solve();
  return 0;
}
