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
const int inf = 1000000;
// clang-format on

int N;
int A[MAX_N + 1];

map<int, int> prime_factors(int nn, map<int, int> &lcmm) {
  map<int, int> mp;
  for (ll i = 2; i * i <= nn; i++) {
    int cnt = 0;
    while (nn % i == 0) {
      cnt++;
      ++mp[i];
      nn /= i;
    }
    if (cnt != 0) lcmm[i] = max(lcmm[i], cnt);
  }
  if (nn != 1) {
    mp[nn]++;
    lcmm[nn] = max(lcmm[nn], mp[nn]);
  }
  return mp;
}

ll modpow(ll x, ll n) {
  const ll m = MOD;
  ll res = 1;
  while (n > 0) {
    if (n % 2 == 1) res = (res * x) % m;
    x = (x * x) % m;
    n >>= 1;
  }
  return res % m;
}

// clang-format off
const int mod = MOD;
inline void normal(ll &a) { a %= mod; (a < 0) && (a += mod); }
inline ll modMul(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a * b) % mod; }
inline ll modAdd(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); return (a + b) % mod; }
inline ll modSub(ll a, ll b) { a %= mod, b %= mod; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while (p) { if (p & 1LL) r = modMul(r, b); b = modMul(b, b); p >>= 1LL; } return r; }
inline ll modInverse(ll a) { return modPow(a, mod - 2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
// clang-format on

ll modmul(map<int, int> mp) {
  ll res = 0;
  for (auto m : mp) {
    res += modpow(m.first, m.second) % MOD;
  }
  return res;
}

map<int, int> aprimes[MAX_N];

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N;
  REP(i, N) cin >> A[i];

  map<int, int> lcmm;
  // vector<map<int, int>> aprimes(N);
  ll lc = 1;
  ll ans = 0;
  REP(i, N) {                                // N = 10^4
    aprimes[i] = prime_factors(A[i], lcmm);  // N * √A = 10^4 * 10^2 = 10^6
  }

  ll L = modmul(lcmm);

  REP(i, N) {  //
    // lcmm と arpimes[i] をそれぞれ計算していけばよい
    ans = modAdd(ans, modDiv(L, A[i]));  // 10^4 * divmp (10^5) = 10^9
  }
  cout << ans << endl;

  return 0;
}
