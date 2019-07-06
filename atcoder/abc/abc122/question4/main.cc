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
#define MAX_N 10
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

const ll mod = 1000000007;

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

mint pt[MAX_N + 1][MAX_N + 1];

mint f(mint n) { return n * f(n - 1).x; }

mint p(mint n, mint r) { return f(n).x / f(n - r).x; }

mint powM(mint b, mint p)
{
  mint n = 1;
  for (int i = 0; i < p.x; i++) {
    n *= b;
  }
  return n;
}

void init()
{
  memset(pt, 0, sizeof(pt));
  pt[0][0] = 1;
  for (int i = 0; i <= MAX_N; i++) {
    for (int j = 0; j <= MAX_N; j++) {
      pt[i + 1][j] += pt[i][j];
      pt[i + 1][j + 1] += pt[i][j];
    }
  }
}

int n;
int main(void)
{
  init();
  cin >> n;
  // All
  mint b = powM(4, n);
  cout << (b.x - (n - 2) * 3) << endl;
  return 0;
}
