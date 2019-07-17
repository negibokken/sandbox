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
#define MAX_N 20
#define MAX_M 20
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

int N, M;
int A[MAX_N][MAX_M];
int B[MAX_M];
int C;

void solve()
{
  int cnt = 0;
  REP(i, N)
  {
    int sum = 0;
    REP(j, M) { sum += A[i][j] * B[j]; }
    sum += C;
    if (sum > 0) cnt++;
  }
  cout << cnt << endl;
}

int main(void)
{
  cin >> N >> M >> C;
  REP(i, M) cin >> B[i];
  REP(i, N) REP(j, M) cin >> A[i][j];
  solve();
  return 0;
}
