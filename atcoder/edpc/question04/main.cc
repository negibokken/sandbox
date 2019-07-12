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
#define MAX_N 100
#define MAX_W 100000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

int N, W;
ll v[MAX_N], w[MAX_N];
ll dp[MAX_N + 1][MAX_W + 1];

void solve()
{
  dp[0][0] = 0;
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = W; j >= 0; j--) {
      if (j < w[i])
        dp[i + 1][j] = dp[i][j];
      else
        dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
    }
  }
  cout << dp[N][W] << endl;
}

int main(void)
{
  cin >> N >> W;
  REP(i, N) cin >> w[i] >> v[i];
  solve();
  return 0;
}
