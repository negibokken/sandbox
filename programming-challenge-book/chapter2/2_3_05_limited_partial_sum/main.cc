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

int n, K;
int a[MAX_N], m[MAX_N];
int dp[MAX_N + 1];

void solve()
{
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= K; j++) {
      if (dp[j] >= 0) {
        dp[j] = m[i];
      }
      else if (j < a[i] || dp[j - a[i]] <= 0) {
        dp[j] = -1;
      }
      else {
        dp[j] = dp[j - a[i]] - 1;
      }
    }
  }
  cout << (dp[K] ? "Yes" : "No") << endl;
}

int main(void)
{
  cin >> n >> K;
  REP(i, n) cin >> a[i];
  REP(i, n) cin >> m[i];
  solve();
  return 0;
}
