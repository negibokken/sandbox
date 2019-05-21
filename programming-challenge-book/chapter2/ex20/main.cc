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

int n, m, M;
int a[MAX_N];

int main(void)
{
  scanf("%d %d %d\n", &n, &m, &M);
  const char *fmt = "%d ";
  myscanf(fmt, n, a);
  printf("%d %d %d\n", n, m, M);
  REP(i, n) printf("%d\n", a[i]);
  return 0;
}
