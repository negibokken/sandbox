#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

// Self settings
// clang-format off
#define MAX_N 100000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

ll N, K;
ll a[MAX_N + 1];
ll d[MAX_N + 1];

void solve()
{
  ll cnt = 0;
  ll sum = 0;
  int s = 0, t = 0;
  for (int i = 0; i < N; i++) {
    while (t < N && sum < K) {
      sum += a[t++];
    }
    if (sum >= K) {
      cnt += N - t + 1;
    }
    if (sum < K) break;
    sum -= a[i];
  }
  printf("%lld\n", cnt);
}

int main(void)
{
  scanf("%lld%lld", &N, &K);
  REP(i, N) scanf("%lld", &a[i]);
  solve();
  return 0;
}
