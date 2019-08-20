#include <math.h>
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

const int mod = 1000000007;
struct mint {
  ll x;
  mint(ll x = 0) : x(x % mod) {}
  mint& operator+=(const mint a)
  {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a)
  {
    if ((x += mod - a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a)
  {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const
  {
    mint res(*this);
    return res += a;
  }
  mint operator-(const mint a) const
  {
    mint res(*this);
    return res -= a;
  }
  mint operator*(const mint a) const
  {
    mint res(*this);
    return res *= a;
  }
  mint pow(ll t) const
  {
    if (!t) return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }
  mint inv() const { return pow(mod - 2); }
  mint operator/=(const mint a) { return (*this) *= a.inv(); }
  mint operator/(const mint a) const
  {
    mint res(*this);
    return res /= a;
  }
};

mint dp[61][2][2][2];

ll l, r;

int main(void)
{
  cin >> l >> r;
  dp[60][0][0][0] = 1;
  for (int i = 59; i >= 0; i--) {
    int lb = l >> i & 1;
    int rb = r >> i & 1;
    REP(j, 2) REP(k, 2) REP(s, 2)
    {
      mint pre = dp[i + 1][j][k][s];
      REP(x, 2) REP(y, 2)
      {
        if (x && !y) continue;  // x= 1, y = 0
        int nj = j, nk = k, ns = s;

        if (!s && x != y) continue;
        if (x && y) ns = 1;

        if (!j && !x && lb) continue;
        if (x && !lb) nj = 1;

        if (!k && y && !rb) continue;
        if (!y && rb) nk = 1;

        dp[i][nj][nk][ns] += pre;
      }
    }
  }
  mint ans;
  REP(j, 2) REP(k, 2) REP(s, 2) ans += dp[0][j][k][s];
  cout << ans.x << endl;
  return 0;
}
