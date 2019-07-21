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
};

ll N, K;
mint dp[55][55][2605];

int main(void)
{
  cin >> N >> K;
  dp[0][0][0] = 1;
  REP(i, N)
  {
    REP(j, i + 1)
    {
      REP(k, K + 1)
      {
        {
          int nj = j;
          dp[i + 1][nj][k + nj * 2] += dp[i][j][k];
        }
        {
          int nj = j + 1;
          dp[i + 1][nj][k + nj * 2] += dp[i][j][k];
        }
        {
          int nj = j;
          mint x = j * 2;
          dp[i + 1][nj][k + nj * 2] += dp[i][j][k] * x;
        }
        if (j >= 1) {
          int nj = j - 1;
          mint x = j * j;
          dp[i + 1][nj][k + nj * 2] += dp[i][j][k] * x;
        }
      }
    }
  }
  mint ans = dp[N][0][K];
  cout << ans.x << endl;
  return 0;
}
