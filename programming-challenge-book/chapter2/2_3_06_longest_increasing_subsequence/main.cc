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

int n;
int a[MAX_N];
int dp[MAX_N][MAX_N + 1];

void solve()
{
  int res = 0;
  for (int i = 0; i < n; i++) {
    dp[i][i] = 1;
    for (int j = i; j < n; j++) {
      if (a[i] < a[j]) {
        dp[i][j + 1] = dp[i][j] + 1;
      }
      else {
        dp[i][j + 1] = dp[i][j];
      }
    }
  }
  REP(i, n) res = max(res, dp[i][n]);
  printf("%d\n", res);
}

int main(void)
{
  cin >> n;
  REP(i, n) cin >> a[i];
  solve();
  return 0;
}
