#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

// Self settings
// clang-format off
#define MAX_N 100000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
// clang-format on

const int MOD = 1000000007;
int N;
char S[MAX_N + 1];
ll dp[MAX_N + 1][13];

void solve()
{
  dp[0][0] = 1;
  for (int i = 0; i < N; i++) {
    int c;
    if (S[i] == '?')
      c = -1;
    else
      c = S[i] - '0';

    for (int j = 0; j < 10; j++) {
      if (c != -1 && c != j) continue;
      for (int k = 0; k < 13; k++) {
        dp[i + 1][(k * 10 + j) % 13] += dp[i][k];
      }
    }
    for (int j = 0; j < 13; j++) dp[i + 1][j] %= MOD;
  }
  ull res = dp[N][5];
  printf("%llu\n", res);
}

int main(void)
{
  cin >> S;
  N = strlen(S);
  solve();
  return 0;
}
