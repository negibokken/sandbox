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
ll fact(ll n) { ll res = 1; for(ll i=2;i<=n;++i) res = res * i; return res;}
ll nCr(ll n, ll r) {return (fact(n)/fact(n-r)*fact(r)) ;}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
const ll MOD = 1e9+7;
const ll INF = 1LL << 60;
const int inf = 1000100011;
// clang-format on

int n, k;
ll T[MAX_N];

int check(ll p) {
  int i = 0;
  for (int j = 0; j < k; j++) {
    ll s = 0;
    while (s + T[i] <= p) {
      s += T[i];
      i++;
      if (i == n) return n;
    }
  }
  return i;
}

ll solve() {
  ll left = 0;
  ll right = 10000 * 10000;
  ll mid;
  while (right - left > 1) {
    mid = (left + right) / 2;
    int v = check(mid);
    if (v >= n)
      right = mid;
    else
      left = mid;
  }
  return right;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> k;
  REP(i, n) cin >> T[i];
  ll ans = solve();
  cout << ans << endl;

  return 0;
}
