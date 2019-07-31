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
ll X;
ll a[MAX_N];
ll p[MAX_N];

void init()
{
  a[0] = 1, p[0] = 1;
  for (int i = 0; i < N; i++) {
    a[i + 1] = a[i] * 2 + 3;
    p[i + 1] = p[i] * 2 + 1;
  }
}

ll f(ll N, ll X)
{
  if (N == 0) {
    return X <= 0 ? 0 : 1;
  }
  else if (X <= 1 + a[N - 1]) {
    return f(N - 1, X - 1);
  }
  else {
    return p[N - 1] + 1 + f(N - 1, X - 2 - a[N - 1]);
  }
}

void solve()
{
  init();
  cout << f(N, X) << endl;
}

int main(void)
{
  cin >> N >> X;
  solve();
  return 0;
}
