#include <stdio.h>
#include <iostream>
using namespace std;

// Self settings
// clang-format off
#define MAX_N 10000
#define INF 100000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
void myscanf(const char *fmt, int num, int *s, int *v) { REP(i,num) scanf(fmt, &s[i], &v[i]); }
void myscanf(const char *fmt, int num, int *s) { REP(i,num) scanf(fmt, &s[i]); }
// clang-format on

int N, ML, MD;
int AL[MAX_N], BL[MAX_N], DL[MAX_N];
int AD[MAX_N], BD[MAX_N], DD[MAX_N];

int d[MAX_N];

void solve()
{
  fill(d, d + N, INF);
  d[0] = 0;
  for (int k = 0; k < N; ++k) {
    for (int i = 0; i + 1 < N; ++i) {
      if (d[i + 1] < INF) d[i] = min(d[i], d[i + 1]);
    }

    for (int i = 0; i < ML; ++i) {
      if (d[AL[i] - 1] < INF) {
        d[BL[i] - 1] = min(d[BL[i] - 1], d[AL[i] - 1] + DL[i]);
      }
    }
    for (int i = 0; i < MD; ++i) {
      if (d[BD[i] - 1] < INF) {
        d[AD[i] - 1] = min(d[AD[i] - 1], d[BD[i] - 1] - DD[i]);
      }
    }
  }

  int res = d[N - 1];
  if (d[0] < 0) {
    res = -1;
  }
  else if (res == INF) {
    res = -2;
  }
  printf("%d\n", res);
}

int main(void)
{
  cin >> N >> ML >> MD;
  for (int i = 0; i < ML; ++i) {
    cin >> AL[i] >> BL[i] >> DL[i];
  }
  for (int i = 0; i < MD; ++i) {
    cin >> AD[i] >> BD[i] >> DD[i];
  }

  solve();
  return 0;
}
