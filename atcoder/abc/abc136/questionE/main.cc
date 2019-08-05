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
#define MAX_N 500
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
// clang-format on

int N, K;
int A[MAX_N];

void solve()
{
  ll sum = 0;
  REP(i, N) sum += A[i];
  ll n = sum;
  set<ll> ret;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ret.insert(i);
      ret.insert(n / i);
    }
  }
  ll ans = 1;
  for (ll x : ret) {
    ll need = 0;
    {
      vector<ll> r(N);
      REP(i, N) r[i] = A[i] % x;
      sort(r.begin(), r.end());
      ll b = 0;
      REP(i, N) b += x - r[i];
      ll a = 0;
      need = 1e18;
      REP(i, N)
      {
        a += r[i];
        b -= x - r[i];
        need = min(need, max(a, b));
      }
    }
    if (need <= K) ans = max(ans, x);
  }
  cout << ans << endl;

  int r[MAX_N];
  // for (auto)
}

int main(void)
{
  cin >> N >> K;
  REP(i, N) cin >> A[i];
  solve();
  return 0;
}
