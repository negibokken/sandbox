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
typedef pair<ll, int> PL;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

// Self settings
// clang-format off
#define MAX_N 100000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
const ll MOD = 1e9+7;
const ll INF = 1LL << 60;
const int inf = 1 << 31;
// clang-format on

int N;
ll C;

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
  REP(i, N + 1) cout << f[i] << SLN(i, N + 1);
  REP(i, N + 1) cout << g[i] << SLN(i, N + 1);
  // return 0;
  x[N] = C, v[N] = 0;
  for (int i = N; i >= 0; i--) {
    vsum += v[i];
    ll xb = vsum - (C - x[i]);
    if (i < N || i != 0) {
      // どっち周りの方が安くつくかを判定してマイナス
      // int idx = upper_bound(g, g + N + 1, g[i]) - g - 1;
      int idx = lower_bound(g, g + N + 1, g[i - 1]) - g - 1;
      if (idx == -1) idx = 0;
      // cout << g[i] << " : "
      //      << "idx: " << idx << ": " << x[idx] << ":" << (C - x[i]) << endl;
      xb -= min(x[idx], (C - x[i]));
    }
    cout << xb << endl;
    ll ga = g[i - 1];
    ans = max(ans, xb + ga);
  }
  cout << ans << endl;

  return 0;
}
