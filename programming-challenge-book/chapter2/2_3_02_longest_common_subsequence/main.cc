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

int n, m;
char s[MAX_N], t[MAX_N];
int dp[MAX_N][MAX_N];

void solve()
{
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i] == t[j]) {
        dp[i][j] = dp[i - 1][j] + 1;
      }
      else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  printf("%d\n", dp[n][m]);
}

int main(void)
{
  cin >> n >> m;
  cin >> s;
  cin >> t;
  solve();
  return 0;
}
