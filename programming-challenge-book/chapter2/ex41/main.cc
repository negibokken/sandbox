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

int P, Q;
int A[MAX_N + 2];

int dp[MAX_N + 1][MAX_N + 2];

void solve()
{
  A[0] = 0;
  A[Q + 1] = P + 1;

  for (int q = 0; q <= Q; q++) {
    dp[q][q + 1] = 0;
  }

  for (int w = 2; w <= Q + 1; w++) {
    for (int i = 0; i + w <= Q + 1; i++) {
      int j = i + w, t = 10000;

      for (int k = i + 1; k < j; k++) {
        t = min(t, dp[i][k] + dp[k][j]);
      }
      dp[i][j] = t + A[j] - A[i] - 2;
    }
  }
  cout << dp[0][Q + 1] << endl;
}

int main(void)
{
  cin >> P >> Q;
  REP(i, Q) cin >> A[i + 1];
  solve();
  return 0;
}
