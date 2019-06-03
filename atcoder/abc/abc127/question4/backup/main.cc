#include <stdio.h>

// Self settings
// clang-format off
#define MAX_AC 1000000000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
void myscanf(const char *fmt, int num, int *s, int *v) { REP(i,num) scanf(fmt, &s[i], &v[i]); }
void myscanf(const char *fmt, int num, int *s) { REP(i,num) scanf(fmt, &s[i]); }
// clang-format on

int N, M;
int A[MAX_AC + 1], B[MAX_AC + 1], C[MAX_AC + 1];

int main(void)
{
  scanf("%d %d\n", &N, &M);
  const char *fmt = "%d ";
  myscanf(fmt, N, A);
  const char *fmt2 = "%d %d\n";
  myscanf(fmt2, M, B, C);

  printf("%d %d\n", N, M);
  REP(i, N) printf("%d ", A[i]);
  putchar('\n');
  REP(i, N) printf("%d %d\n", B[i], C[i]);
  return 0;
}
