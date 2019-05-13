#include <iostream>
using namespace std;

#define MAX_N 10000
#define MAX_M 10000

int n, m;
char s[MAX_N], t[MAX_M];
int dp[MAX_N][MAX_M];

void solve()
{
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i] == t[j]) {
        dp[i + 1][j + 1] = dp[i][j] + 1;
      }
      else {
        dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
      }
    }
  }
  printf("%d\n", dp[n][m]);
}

int main(void)
{
  scanf("%d %d", &n, &m);
  scanf("%s %s", s, t);
  solve();
  return 0;
}
