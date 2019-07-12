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

int N, K;
int dp[MAX_N + 1], h[MAX_N];

void solve()
{
  dp[0] = 0;
  dp[1] = abs(h[0] - h[1]);
  for (int i = 2; i < N; i++) {
    int minc = INT_MAX;
    for (int j = i - 1; j >= max(i - K, 0); j--) {
      minc = min(minc, dp[j] + abs(h[i] - h[j]));
    }
    dp[i] = minc;
  }
  cout << dp[N - 1] << endl;
}

int main(void)
{
  cin >> N >> K;
  REP(i, N) cin >> h[i];
  solve();
  return 0;
}
