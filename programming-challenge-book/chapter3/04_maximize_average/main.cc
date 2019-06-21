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
#define INF 1000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

int k, n;
int w[MAX_N], v[MAX_N];

double y[MAX_N];

bool C(double x)
{
  for (int i = 0; i < n; i++) {
    y[i] = v[i] - x * w[i];
  }
  sort(y, y + n);
  double sum = 0;
  for (int i = 0; i < k; i++) {
    sum += y[n - i - 1];
  }
  return sum >= 0;
}

void solve()
{
  double lb = 0, ub = INF;
  for (int i = 0; i < 100; i++) {
    double mid = (lb + ub) / 2;
    if (C(mid))
      lb = mid;
    else
      ub = mid;
  }
  printf("%.2f\n", ub);
}

int main(void)
{
  cin >> n >> k;
  REP(i, n) cin >> w[i] >> v[i];
  solve();
  return 0;
}
