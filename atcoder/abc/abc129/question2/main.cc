#include <stdio.h>
#include <algorithm>
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
int w[101];

int main(void)
{
  cin >> n;
  REP(i, n) cin >> w[i];
  int diff = 10000;
  for (int t = 0; t < n; ++t) {
    int j = 0;
    int diffL = 0;
    while (j <= t) {
      diffL += w[j];
      j++;
    }

    j = t + 1;
    int diffR = 0;
    while (j < n) {
      diffR += w[j];
      j++;
    }
    diff = min(diff, abs(diffL - diffR));
  }
  cout << diff << endl;
  return 0;
}
