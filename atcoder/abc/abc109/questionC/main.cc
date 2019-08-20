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

ll gcd(ll a, ll b)
{
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main(void)
{
  int N, X;
  cin >> N >> X;
  vector<int> x(N + 1);
  REP(i, N) cin >> x[i];
  x[N] = X;

  // N log N
  sort(x.begin(), x.end());

  ll w[N + 1];
  REP(i, N) { w[i] = x[i + 1] - x[i]; }

  ll dp[N + 1];
  dp[0] = w[0];
  REP(i, N) { dp[i + 1] = gcd(dp[i], w[i]); }

  cout << dp[N] << endl;
  return 0;
}
