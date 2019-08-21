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

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

// Self settings
// clang-format off
#define MAX_N 100000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
// clang-format on

int N, K;

ll f(int n)
{
  if (n == 0) return 1;
  return n * f(n - 1);
}

ll nPr(int n, int r) { return f(n) / f(r); }

int main(void)
{
  cin >> N >> K;

  ll ans = 0;
  if (K % 2 == 1) {
    ll cnt = 0;
    for (int i = 1; i <= N; i++)
      if (i % K == 0) cnt++;
    ans = cnt * cnt * cnt;
  }
  else {
    ll cnt = 0, half = 0, dup = 0;
    for (int i = 1; i <= N; i++) {
      ll r = i % K;
      if (i % K == 0) cnt++;
      if (i % K == K / 2) half++;
      if (i % K == 0 && i % K == K / 2) dup++;
    }
    ans += cnt * cnt * cnt;
    ll h = half - dup;
    ans += h * h * h;
  }
  cout << ans << endl;
  return 0;
}
