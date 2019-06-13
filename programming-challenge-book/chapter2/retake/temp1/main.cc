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

int prime[MAX_N];
bool is_prime[MAX_N];

int sieve(int n)
{
  int p = 0;
  for (int i = 0; i <= n; ++i) is_prime[i] = true;

  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; ++i) {
    if (is_prime[i]) {
      prime[p++] = i;
      for (int j = 2 * i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
    break;
  }
  return p;
}

int n;
void solve(int n)
{
  sieve(MAX_N);
  cout << (is_prime[n] ? "Yes" : "No") << endl;
}

int main(void)
{
  cin >> n;
  solve(n);
  return 0;
}
