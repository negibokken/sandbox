#include <stdio.h>
#include <iostream>
using namespace std;

// Self settings
// clang-format off
#define MAX_N 100000
#define MAX_W 1000000000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
void myscanf(const char *fmt, int num, int *u, int *v, int *w) { REP(i,num) scanf(fmt, &u[i], &v[i], &w[i]); }
// clang-format on

int N;
int u[MAX_N];
int v[MAX_N];
int w[MAX_N];
int col[MAX_N] = {0};

int main(void)
{
  scanf("%d\n", &N);
  const char *fmt = "%d %d %d\n";
  myscanf(fmt, N - 1, u, v, w);
  for (int i = 0; i < N; ++i) {
    if (w[i] % 2 == 0) {
      col[u[i]] = 0;
      col[v[i]] = 0;
    }
    else {
      col[u[i]] = 1;
      col[v[i]] = 1;
    }
  }
  for (int i = 0; i < N; ++i) printf("%d\n", col[i]);

  return 0;
}
