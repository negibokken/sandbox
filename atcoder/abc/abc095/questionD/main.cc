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

// Self settings
// clang-format off
#define MAX_N 100000
#define REP(i, N) for (ll i = 0; i < (ll)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
// clang-format on

ll N, C;

ll x[MAX_N + 1], v[MAX_N + 1];
ll f[MAX_N + 1];
ll g[MAX_N + 1];

void init()
{
  f[0] = 0;
  ll vsum = 0;
  for (int i = 0; i < N; i++) {
    vsum += v[i];
    f[i + 1] = vsum - x[i];
  }
  g[0] = 0;
  for (int i = 0; i < N; i++) {
    g[i + 1] = max(f[i + 1], g[i]);
  }
}

int main(void)
{
  cin >> N >> C;
  REP(i, N) cin >> x[i] >> v[i];

  init();

  ll ans = 0;
  ll vsum = 0;

  // REP(i, N + 1) cout << f[i] << SLN(i, N + 1);
  // REP(i, N + 1) cout << i << ":" << g[i] << SLN(i, N + 1);

  // return 0;
  x[N] = C, v[N] = 0;
  for (int i = N; i >= 0; i--) {
    vsum += v[i];
    ll xb = vsum - (C - x[i]);
    ll ga = g[i];

    // N のとき (A だけでいったとき) と
    // 0 のとき (B だけでいったとき) は
    // 被りがないのでマイナスする必要がない
    if (i != N && i != 0) {
      // どっち周りの方が安くつくかを判定してマイナス
      int idx = lower_bound(g, g + N + 1, ga) - g - 1;
      // printf("idx: %d, xb: %lld, ga: %lld \n", idx, xb, ga);
      // printf("x[idx]: %lld, (C-x[i]): %lld \n", x[idx], ((ll)C - x[i]));
      // -1 の場合 A の方に取りに行かないのが正解

      if (idx != -1) {
        ga = ga - min(x[idx], (C - x[i]));
      }
    }
    // cout << xb << ":" << ga << endl;
    ans = max(ans, (ll)(xb + ga));
  }
  cout << ans << endl;

  return 0;
}

