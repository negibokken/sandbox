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
#define MAX_N 30
#define MAX_M 30
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
// clang-format on
int N, M;
int K[MAX_M];
int A[MAX_M][MAX_N];
bool Q[MAX_M];

void solve()
{
  fill(Q, Q + MAX_M, true);
  int cnt = 0;
  REP(q, 30)
  {
    bool n = true;
    REP(i, N)
    {
      sort(A[i], A[i] + K[i]);
      bool s = binary_search(A[i], A[i] + K[i], q + 1);
      n &= binary_search(A[i], A[i] + K[i], q + 1);
    }
    if (n) cnt++;
  }
  cout << cnt << endl;
}

int main(void)
{
  cin >> N >> M;
  REP(i, N)
  {
    cin >> K[i];
    REP(j, K[i]) { cin >> A[i][j]; }
  }
  solve();
  return 0;
}
