#include <stdio.h>
#include <iostream>
using namespace std;

// Self settings
// clang-format off
#define MAX_N 1000000007
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
void myscanf(const char *fmt, int num, int *s, int *v) { REP(i,num) scanf(fmt, &s[i], &v[i]); }
void myscanf(const char *fmt, int num, int *s) { REP(i,num) scanf(fmt, &s[i]); }
// clang-format on

int a[MAX_N];
int N, A, B, C;

int main(void)
{
  cin >> N >> A >> B >> C;
  cout << N << A << B << C;
  return 0;
}
