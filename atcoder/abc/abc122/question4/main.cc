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
#define MAX_N 100
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

bool ok(string l4)
{
  for (int i = 0; i < 4; i++) {
    string last4 = l4;
    if (i >= 1) {
      swap(last4[i - 1], last4[i]);
    }
    if (last4.find("AGC") != std::string::npos) {
      return false;
    }
  }
  return true;
}

int n;
map<string, mint> m[MAX_N];

mint dfs(int cur, string last3)
{
  if (m[cur].count(last3) > 0) return m[cur][last3];
  if (cur == n) return 1;
  mint ret = 0;
  string ACGT = "ACGT";
  for (int i = 0; i < 4; i++) {
    char c = ACGT[i];
    string last4 = last3 + c;
    if (ok(last4)) {
      ret = (ret + dfs(cur + 1, last3.substr(1, 2) + c));
    }
  }
  m[cur][last3] = ret;
  return ret;
}
int main(void)
{
  cin >> n;
  cout << dfs(0, "TTT").x << endl;
}
