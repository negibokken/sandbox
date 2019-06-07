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

int px[2], py[2];

int gcd(int a, int b)
{
  if (b == 0) return a;
  return gcd(b, a % b);
}

void solve()
{
  int ans = gcd(abs(px[0] - px[1]), abs(py[0] - py[1])) - 1;
  printf("%d\n", ans);
}

int main(void)
{
  for (int i = 0; i < 2; ++i) {
    cin >> px[i] >> py[i];
  }
  solve();
  return 0;
}
