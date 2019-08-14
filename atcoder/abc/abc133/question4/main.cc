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
#define SLN(i,N) (i == N-1 ? "\n" : " ")
// clang-format on

int N;
ll A[MAX_N];
ll x[MAX_N];

void solve()
{
  ll sum = 0;
  // calculate x1
  for (int i = 0; i < N; i++) {
    if (i % 2 == 0) {
      sum += A[i];
    }
    else {
      sum -= A[i];
    }
  }
  x[0] = sum;
  for (int i = N - 1; i >= 1; i--) {
    int idx = i + 1;
    if (idx == N) idx = 0;
    x[i] = 2 * A[i] - x[idx];
  }
  REP(i, N) cout << x[i] << SLN(i, N);
}

int main(void)
{
  cin >> N;
  REP(i, N) cin >> A[i];
  solve();
  return 0;
}
