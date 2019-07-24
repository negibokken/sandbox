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
#define MAX_N 10000
#define INF -1000000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
// clang-format on

int cost[] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int N, M;
int A[9];
char ans[MAX_N];
int dp[MAX_N + 1];

void solve()
{
  fill(dp, dp + N, INF);
  dp[0] = 0;
  REP(i, N + 1)
  {
    REP(j, M)
    {
      if (i - cost[A[j]] >= 0 && dp[i - cost[A[j]]] != INF) {
        dp[i] = max(dp[i], dp[i - cost[A[j]]] + 1);
      }
    }
  }

  int i = N;
  while (i > 0) {
    int ma = 0;
    for (int j = 0; j < M; j++) {
      if (i - cost[A[j]] < 0) continue;
      if (dp[i - cost[A[j]]] == dp[i] - 1) {
        ma = max(ma, A[j]);
      }
    }
    cout << ma;
    i -= cost[ma];
  }
  cout << endl;
}

int main(void)
{
  cin >> N >> M;
  REP(i, M) { cin >> A[i]; }
  solve();
  return 0;
}
