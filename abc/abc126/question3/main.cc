#include <stdio.h>
#include <cmath>

#define MAX_N 100000
#define MAX_K 100000

#define REP(i, N) for (int i = 0; i < (int)(N); ++i)

int N, K;
int dp[MAX_N];

void solve()
{
  dp[0] = 0;
  for (int i = 1; i <= N; ++i) {
    int sum = i;
    int cnt = 0;
    while (sum < K) {
      sum = sum * 2;
      cnt++;
    }
    dp[i] = cnt;
  }
  double result = 0.0;
  for (int i = 1; i <= N; ++i) {
    result += pow(0.5, dp[i]);
  }
  printf("%.11f\n", result * 1.0 / (double)N);
}

int main(void)
{
  scanf("%d %d", &N, &K);
  solve();
  return 0;
}
