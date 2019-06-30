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

mint c[4005][4005];

void init()
{
  c[0][0] = 1;
  for (int i = 0; i <= 4000; i++) {
    for (int j = 0; j <= i; j++) {
      c[i + 1][j] += c[i][j];
      c[i + 1][j + 1] += c[i][j];
    }
  }
}

mint comb(int n, int k) { return c[n][k]; }
mint f2(int n, int k) { return comb(n + k - 1, k - 1); }
mint f(int n, int k)
{
  if (n < k) return 0;
  if (n == 0 && k == 0) return 1;
  if (k < 1) return 0;
  return f2(n - k, k);
}

int main(void)
{
  init();
  int n, k;
  cin >> n >> k;
  ll cnt = 1;
  for (int i = 1; i <= k; i++) {
    mint blue = f(k, i);
    mint red = 0;
    {
      red += f(n - k, i - 1);
      red += f(n - k, i);
      red += f(n - k, i);
      red += f(n - k, i + 1);
    }
    mint ans = blue * red;
    printf("%lld\n", ans.x);
  }
  return 0;
}
