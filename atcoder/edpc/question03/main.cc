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
int a[MAX_N], b[MAX_N], c[MAX_N];
int dp[MAX_N][3];

void solve()
{
  for (int i = 0; i < 3; i++) dp[0][i] = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      int m = 0;
      if (j == 0)
        dp[i + 1][j] = max(dp[i][1] + b[i], dp[i][2] + c[i]);
      else if (j == 1)
        dp[i + 1][j] = max(dp[i][0] + a[i], dp[i][2] + c[i]);
      else if (j == 2)
        dp[i + 1][j] = max(dp[i][0] + a[i], dp[i][1] + b[i]);
    }
  }
  int res = 0;
  for (int i = 0; i < 3; i++) res = max(res, dp[n][i]);
  cout << res << endl;
}

int main(void)
{
  cin >> n;
  REP(i, n) cin >> a[i] >> b[i] >> c[i];
  solve();
  return 0;
}
