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
#define MAX_N 1000000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
// clang-format on

int N;
char s[MAX_N][15];

ll factorial(ll n)
{
  if (n <= 0) return 1;
  ll f = 1;
  for (ll i = 1; i <= n; i++) {
    f *= i;
  }
  return f;
}

ll comb(ll n, ll r)
{
  ll a = (n * (n - 1)) / 2;
  return (a == 0 ? 1 : a);
}

int main(void)
{
  cin >> N;
  REP(i, N) cin >> s[i];
  REP(i, N) sort(s[i], s[i] + 10);
  map<string, ll> m;
  REP(i, N) m[s[i]]++;
  ll ans = 0;
  for (auto mm : m) {
    if (mm.second >= 2) {
      ans += comb(mm.second, 2);
    }
  }
  cout << ans << endl;
  return 0;
}
