#include <stdio.h>
#include <iostream>
using namespace std;

// Self settings
// clang-format off
#define MAX_N 1000000
#define MAX_SQRT_B 1000000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
void myscanf(const char *fmt, int num, int *s, int *v) { REP(i,num) scanf(fmt, &s[i], &v[i]); }
void myscanf(const char *fmt, int num, int *s) { REP(i,num) scanf(fmt, &s[i]); }
// clang-format on

int a, b;
typedef long long ll;

bool is_prime[MAX_N];
bool is_prime_small[MAX_SQRT_B];

void segment_sieve(ll a, ll b)
{
  int cnt = 0;
  for (int i = 0; (ll)i * i < b; ++i) is_prime_small[i] = true;
  for (int i = 0; i < b - 1; ++i) is_prime[i] = true;

  for (int i = 2; (ll)i * i < b; ++i) {
    if (is_prime_small[i]) {
      cnt++;
      for (int j = 2 * i; (ll)j * j < b; j += i) is_prime_small[j] = false;
      for (ll j = max(2LL, (a + i - 1) / i) * i; j < b; j += i)
        is_prime[j - 1] = false;
    }
  }
  cout << cnt << endl;
}

void solve() { segment_sieve(a, b); }

int main(void)
{
  cin >> a >> b;
  solve();
  return 0;
}
