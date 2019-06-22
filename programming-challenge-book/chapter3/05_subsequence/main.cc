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
  for (int i = 0; i < n; i++) {
    sum[i + 1] = sum[i] + a[i];
  }

  if (sum[n] < S) {
    printf("0\n");
    return;
  }

  int res = n;
  for (int s = 0; sum[s] + S <= sum[n]; s++) {
    int t = lower_bound(sum + s, sum + n, sum[s] + S) - sum;
    res = min(res, t - s);
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
