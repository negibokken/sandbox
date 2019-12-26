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
const int inf = 1 << 30;
// clang-format on

int d(ll n) {
  int digit = 0;
  while (n > 0) {
    digit++;
    n /= 10;
  }
  return digit;
}

vector<ll> prime_numbers(ll n) {
  vector<ll> primes;
  for (ll i = 2; (ll)i * i <= n; i++) {
    while (n % i == 0) {
      primes.push_back(i);
      n /= i;
    }
  }
  if (n != 1) {
    primes.push_back(n);
  }
  return primes;
}

ll N;

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N;

  ll ans = inf;
  vector<ll> primes = prime_numbers(N);

  int n = primes.size();
  for (int i = 0; i < ((ll)1 << n); i++) {
    ll A = 1;
    // 223355
    // 000000
    ll ii = i, bit = 0;
    while (ii > 0) {
      if (ii & 1) {
        A *= primes[bit];
      }
      bit++;
      ii >>= 1;
    }
    ll B = N / A;
    ll a = max(d(B), d(A));
    ans = min(ans, a);
  }
  cout << ans << endl;

  return 0;
}
