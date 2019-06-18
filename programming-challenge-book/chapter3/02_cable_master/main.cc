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
#define INF 1000000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

int N, K;
double L[MAX_N];

bool C(double x)
{
  int num = 0;
  for (int i = 0; i < N; i++) {
    num += (int)(L[i] / x);
  }
  return num >= K;
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
  printf("%.2f\n", floor(ub * 100) / 100);
}

int main(void)
{
  cin >> N >> K;
  REP(i, N) cin >> L[i];
  solve();
  return 0;
}
