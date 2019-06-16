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

// Self settings
// clang-format off
#define MAX_N 10000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

int n, S;
int a[MAX_N];

int sum[MAX_N + 1];

void solve()
{
  for (int i = 0; i < n; i++) {
    sum[i + 1] = sum[i] + a[i];
  }

  if (sum[n] < S) {
    cout << "0" << endl;
    return;
  }

  REP(i, n + 1) cout << sum[i] << " ";
  cout << endl;
  // 累積和のうちでどこの区間で S を達成しているか
  int res = n;
  for (int s = 0; sum[s] + S <= sum[n]; s++) {
    int t = lower_bound(sum + s, sum + n, sum[s] + S) - sum;
    cout << s << ":" << t << endl;
    res = min(res, t - s);
  }
  cout << res << endl;
}

int main(void)
{
  cin >> n >> S;
  REP(i, n) cin >> a[i];
  solve();
  return 0;
}
