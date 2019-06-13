#include <stdio.h>
#include <iostream>
using namespace std;

// Self settings
// clang-format off
#define MAX_N 10000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
void myscanf(const char *fmt, int num, int *s, int *v) { REP(i,num) scanf(fmt, &s[i], &v[i]); }
void myscanf(const char *fmt, int num, int *s) { REP(i,num) scanf(fmt, &s[i]); }
// clang-format on

int n;

typedef long long ll;
ll mod_pow(ll x, ll n, ll mod)
{
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * x % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}

int prime[MAX_N];
bool is_prime[MAX_N + 1];

int sieve()
{
  int p = 0;
  for (int i = 0; i <= n; ++i) is_prime[i] = true;
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; ++i) {
    if (is_prime[i]) {
      prime[p++] = i;
    }
    for (int j = 2 * i; j <= n; j += i) is_prime[j] = false;
  }
  return p;
}

void solve()
{
  bool flag = true;
  sieve();
  if (is_prime[n]) {
    cout << "No" << endl;
    return;
  }

  for (int i = 2; i < n; ++i) {
    int ans = mod_pow(i, n, n);
    if (ans != i) {
      flag = false;
      break;
    }
  }
  cout << (flag ? "Yes" : "No") << endl;
}

int main(void)
{
  cin >> n;
  solve();
  return 0;
}
