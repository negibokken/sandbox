#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Self settings
// clang-format off
#define MAX_N 100000
#define mod 1000000007
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
// clang-format on

typedef long long ll;
int N, M;
bool A[MAX_N];
int dp[MAX_N + 1];

int main(void)
{
  cin >> N >> M;
  REP(i, N) A[i] = true;
  REP(i, M)
  {
    int a;
    cin >> a;
    A[a] = false;
  }
  dp[N] = 1;
  for (int i = N - 1; i >= 0; i--) {
    // 壊れているならその階にはたどり着けないので0通りにする
    if (!A[i]) {
      dp[i] = 0;
      continue;
    }

    // 一個前か二個前からたどり着くための
    // 方法は何通りあるか確認する
    ll sum = 0;
    for (int j = 1; j <= 2; j++) {
      int idx = i + j;
      if (idx > N) continue;
      sum = (sum + dp[idx]) % mod;
    }
    dp[i] = sum;
  }

  // REP(i, N + 1) cout << dp[i] << SLN(i, N + 1);
  cout << dp[0] << endl;
  return 0;
}
