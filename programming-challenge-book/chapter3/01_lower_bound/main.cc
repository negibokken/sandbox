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

int n, k;
int a[MAX_N];

void solve()
{
  int lb = -1, ub = n;
  while (ub - lb > 1) {
    int mid = (ub + lb) / 2;
    if (a[mid] >= k) {
      ub = mid;
    }
    else {
      lb = mid;
    }
  }
  printf("%d\n", ub);
}

int main(void)
{
  cin >> n >> k;
  REP(i, n) cin >> a[i];
  solve();
  return 0;
}
