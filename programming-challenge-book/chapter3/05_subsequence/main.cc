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
#define MAX_N 100000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

int n;
ll S;
int a[MAX_N];

ll sum[MAX_N];

void solve()
{
  int res = n + 1;
  int s = 0, t = 0, sum = 0;
  for (;;) {
    while (t < n && sum < S) {
      sum += a[t++];
    }
    if (sum < S) break;
    res = min(res, t - s);
    sum -= a[s++];
    while (s < t && sum > S) {
      res = min(res, t - s);
      sum -= a[s++];
    }
  }
  if (res > n) {
    res = 0;
  }
  printf("%d\n", res);
}

int main(void)
{
  cin >> n >> S;
  REP(i, n) cin >> a[i];
  solve();
  return 0;
}
