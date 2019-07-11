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
int dp[MAX_N + 1], h[MAX_N + 1];

void solve()
{
  dp[0] = 0;
  dp[1] = abs(h[1] - h[0]);
  for (int i = 2; i < n; i++) {
    dp[i] =
        min(dp[i - 2] + abs(h[i - 2] - h[i]), dp[i - 1] + abs(h[i - 1] - h[i]));
  }
  cout << dp[n - 1] << endl;
}

int main(void)
{
  cin >> n;
  REP(i, n) cin >> h[i];
  solve();
  return 0;
}
