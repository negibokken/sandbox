#include <stdio.h>
#include <bitset>
#include <iostream>
#include <vector>
using namespace std;

// Self settings
// clang-format off
#define MAX_N 10
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
void myscanf(const char *fmt, int num, int *s, int *v) { REP(i,num) scanf(fmt, &s[i], &v[i]); }
void myscanf(const char *fmt, int num, int *s) { REP(i,num) scanf(fmt, &s[i]); }
// clang-format on

int N, M;

int k[MAX_N + 1];
int p[MAX_N + 1];
int dp[MAX_N + 1][MAX_N + 1];

int main(void)
{
  cin >> N >> M;

  // それぞれの電球がどのビット列でつくか保持
  vector<int> a(N);

  for (int i = 0; i < M; ++i) {
    int k;
    cin >> k;
    for (int j = 0; j < k; ++j) {
      int s;
      cin >> s;
      s--;
      // sw3, sw2, sw1 の並びのビット列で表現される
      // e.g 101, 001
      a[i] |= (1 << s);
    }
  }

  for (int i = 0; i < M; ++i) {
    cout << std::bitset<8>(a[i]) << endl;
  }

  vector<int> p(M);
  for (int i = 0; i < M; ++i) {
    int x;
    cin >> x;
    p[i] = x;
  }

  int ans = 0;
  for (int s = 0; s < (1 << N); ++s) {
    for (int i = 0; i < M; ++i) {
      int t = 0;
      for (int j = 0; j < N; ++j) {
        if (s >> j & 1) {
          t++;
        }
      }
      if (t % 2 == p[i]) {
        ans++;
      }
    }
  }
  cout << ans << endl;

  return 0;
}
