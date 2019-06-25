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

const int dx[5] = {-1, 0, 0, 0, 1};
const int dy[5] = {0, -1, 0, 1, 0};

// Self settings
// clang-format off
#define MAX_N 10000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

int n;
int A[MAX_N], B[MAX_N], C[MAX_N], D[MAX_N];

int CD[MAX_N * MAX_N];

void solve()
{
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      CD[i * n + j] = C[i] + D[j];
    }
  }
  sort(CD, CD + n * n);

  ll res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int cd = -(A[i] + B[j]);
      res += upper_bound(CD, CD + n * n, cd) - lower_bound(CD, CD + n * n, cd);
    }
  }
  printf("%lld\n", res);
}

int main(void)
{
  cin >> n;
  REP(i, n) cin >> A[i];
  REP(i, n) cin >> B[i];
  REP(i, n) cin >> C[i];
  REP(i, n) cin >> D[i];
  solve();
  return 0;
}
