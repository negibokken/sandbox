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
#define INF 10000000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

int N, M;
ll x[MAX_N + 1];

bool C(int d)
{
  int last = 0;
  for (int i = 1; i < M; i++) {
    int crt = last + 1;
    while (crt < N && x[crt] - x[last] < d) {
      crt++;
    }
    if (crt == N) return false;
    last = crt;
  }
  return true;
}

void solve()
{
  sort(x, x + N);
  int lb = 0, ub = INF;
  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    if (C(mid))
      lb = mid;
    else
      ub = mid;
  }
  printf("%d\n", lb);
}

int main(void)
{
  cin >> N >> M;
  REP(i, N) cin >> x[i];
  solve();
  return 0;
}
