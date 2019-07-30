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
typedef pair<ll, int> P;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

// Self settings
// clang-format off
#define MAX_N 100000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
// clang-format on

int N, K;
ll h[MAX_N + 1];
ll d[MAX_N + 1];

void solve()
{
  sort(h, h + N);
  ll ans = INT_MAX;
  for (int i = 0; i <= N - K; i++) {
    ans = min(ans, h[i + K - 1] - h[i]);
  }
  cout << ans << endl;
}

int main(void)
{
  cin >> N >> K;
  REP(i, N) cin >> h[i];
  solve();
  return 0;
}
