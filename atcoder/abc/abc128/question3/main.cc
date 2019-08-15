#include <math.h>
#include <stdio.h>
#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

// Self settings
// clang-format off
#define MAX_N 10
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

int N, M;

int k[MAX_N + 1];
int p[MAX_N + 1];
int s[MAX_N + 1];

int main(void)
{
  cin >> N >> M;
  REP(i, M)
  {
    int k;
    cin >> k;
    REP(j, k)
    {
      int ss;
      cin >> ss;
      s[i] += (int)pow(2, ss - 1);
    }
  }
  REP(i, M) cin >> p[i];

  int ans = 0;
  for (int i = 0; i < (1 << N); i++) {
    int onLight = 0;
    for (int j = 0; j < M; j++) {
      int no1 = s[j] & i;
      int cnt = 0;
      // count # 1
      while (no1 > 0) {
        if (no1 & 1) cnt++;
        no1 >>= 1;
      }
      if (cnt % 2 == p[j]) onLight++;
    }
    if (onLight == M) ans++;
  }

  cout << ans << endl;

  return 0;
}
