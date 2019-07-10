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
typedef pair<int, int> P;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

// Self settings
// clang-format off
#define MAX_N 100000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on
int n, m, M;
// int dp[MAX_N][MAX_N];
int dp[MAX_N + 1][MAX_N + 1];

void solve()
{
  dp[0][0] = 1;
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (j - i >= 0) {
        dp[i][j] = (dp[i - 1][j] + dp[i][j - i]) % M;
      }
      else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  printf("%d\n", dp[m][n]);
}

int main(void)
{
  cin >> n >> m >> M;
  solve();
  return 0;
}
