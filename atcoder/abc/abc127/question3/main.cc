#include <stdio.h>

// clang-format off
#define MAX_N 100000
#define MAX_M 100000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
void myscanf(const char *fmt, int num, int *s, int *v) { REP(i,num) scanf(fmt, &s[i], &v[i]); }
// clang-format on

int N, M;
int L[MAX_N + 1];
int R[MAX_N + 1];

int main(void)
{
  scanf("%d %d\n", &N, &M);
  const char *fmt = "%d %d\n";
  myscanf(fmt, M, L, R);
  int minL = 0, minR = 100000;
  for (int i = 0; i < M; ++i) {
    if (minL < L[i]) minL = L[i];
    if (minR > R[i]) minR = R[i];
  }
  if ((minR - minL + 1) <= 0) {
    printf("0\n");
  }
  else {
    printf("%d\n", (minR - minL) + 1);
  }
  return 0;
}
