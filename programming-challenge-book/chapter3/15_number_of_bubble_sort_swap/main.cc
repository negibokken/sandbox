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
int a[MAX_N];

int bit[MAX_N + 1];

int sum(int i)
{
  int s = 0;
  while (i > 0) {
    s += bit[i];
    i -= i & -i;
  }
  return s;
}

void add(int i, int x)
{
  while (i <= n) {
    bit[i] += x;
    i += i & -i;
  }
}

void solve()
{
  ll ans = 0;
  for (int j = 0; j < n; j++) {
    ans += j - sum(a[j]);
    add(a[j], 1);
  }
  printf("%lld\n", ans);
}

int main(void)
{
  cin >> n;
  REP(i, n) cin >> a[i];
  solve();
  return 0;
}
