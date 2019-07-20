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
#define MAX_N 10
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on
int N;
double x[MAX_N];
char u[MAX_N][4];
const double btc = 380000.0;

void solve()
{
  double ans = 0.0;
  for (int i = 0; i < N; i++) {
    if (strcmp(u[i], "BTC") == 0) {
      ans += x[i] * btc;
    }
    else {
      ans += x[i];
    }
  }
  printf("%.6f\n", ans);
}

int main(void)
{
  cin >> N;
  REP(i, N) cin >> x[i] >> u[i];
  solve();
  return 0;
}
