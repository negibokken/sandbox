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
#define INF 1000000000000
#define MINF -1000000000000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
// clang-format on

int A, B, Q;
ll s[MAX_N + 2], t[MAX_N + 2], x[MAX_N + 2];
ll ANS[MAX_N];

void solve()
{
  REP(i, Q)
  {
    ll q = x[i + 1];
    int si = upper_bound(s, s + A, q) - s;
    int ti = upper_bound(t, t + B, q) - t;
    ll ans = INF;
    for (int i = -1; i <= 0; i++) {
      for (int j = -1; j <= 0; j++) {
        if (abs(s[si + i]) == INF || abs(t[ti + j]) == INF) continue;
        ans = min(ans, abs(q - s[si + i]) + abs(s[si + i] - t[ti + j]));
        ans = min(ans, abs(q - t[ti + j]) + abs(t[ti + j] - s[si + i]));
      }
    }
    ANS[i] = ans;
  }
  // REP(i, Q) { cout << ANS[i] << endl; }
  REP(i, Q) { cout << ANS[i] << SLN(i, Q); }
}

int main(void)
{
  cin >> A >> B >> Q;
  REP(i, A) cin >> s[i + 1];
  s[0] = MINF, s[A + 1] = INF;
  REP(i, B) cin >> t[i + 1];
  t[0] = MINF, t[B + 1] = INF;
  REP(i, Q) cin >> x[i + 1];
  x[0] = MINF, x[Q + 1] = INF;
  solve();
  return 0;
}
