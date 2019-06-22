#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

// Self settings
// clang-format off
#define MAX_N 100000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on
int N;
int dir[MAX_N];

int f[MAX_N];

int calc(int K)
{
  memset(f, 0, sizeof(f));
  int res = 0;
  int sum = 0;
  for (int i = 0; i + K <= N; i++) {
    if ((dir[i] + sum) % 2 == 0) {
      res++;
      f[i] = 1;
    }
    sum += f[i];
    if (i - K + 1 >= 0) {
      sum -= f[i - K + 1];
    }
  }
  // ここまでで
  // 0 ~ N - i + K

  for (int i = N - K + 1; i < N; i++) {
    if ((dir[i] + sum) % 2 == 0) {
      return -1;
    }
    if (i - K + 1 >= 0) {
      sum -= f[i - K + 1];
    }
  }
  return res;
}

void solve()
{
  int K = 1, M = N;
  for (int k = 1; k <= N; k++) {
    int m = calc(k);
    if (m >= 0 && M > m) {
      M = m;
      K = k;
    }
  }
  cout << K << " " << M << endl;
}

int main(void)
{
  cin >> N;
  REP(i, N)
  {
    char x;
    cin >> x;
    dir[i] = (x == 'F' ? 1 : 0);
  }
  solve();
  return 0;
}
