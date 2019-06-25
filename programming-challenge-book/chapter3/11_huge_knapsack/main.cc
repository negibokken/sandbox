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
#define MAX_N 40
#define INF 10000
#define MAX_NN 1 << (MAX_N / 2)
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

int n;
ll W;
ll w[MAX_N], v[MAX_N];

pair<ll, ll> ps[MAX_NN];

void solve()
{
  int n2 = n / 2;
  for (int i = 0; i < 1 << n2; i++) {
    ll sw = 0, sv = 0;
    for (int j = 0; j < n2; j++) {
      if (i >> j & 1) {
        sw += w[j];
        sv += v[j];
      }
    }
    ps[i] = make_pair(sw, sv);
  }

  sort(ps, ps + (1 << n2));
  int m = 1;
  for (int i = 1; i < 1 << n2; i++) {
    if (ps[m - 1].second < ps[i].second) {
      ps[m++] = ps[i];
    }
  }

  ll res = 0;
  for (int i = 0; i < 1 << (n - n2); i++) {
    ll sw = 0, sv = 0;
    for (int j = 0; j < n - n2; j++) {
      if (i >> j & 1) {
        sw += w[n2 + j];
        sv += v[n2 + j];
      }
    }
    if (sw <= W) {
      ll tv = (lower_bound(ps, ps + m, make_pair(W - sw, (ll)INF)) - 1)->second;
      res = max(res, sv + tv);
    }
  }
  printf("%lld\n", res);
}

int main(void)
{
  cin >> n >> W;
  REP(i, n) cin >> w[i];
  REP(i, n) cin >> v[i];
  solve();
  return 0;
}
