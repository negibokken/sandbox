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
#define INF 2000000000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
// clang-format on

int N;
ll A[MAX_N + 1];
ll colors[MAX_N + 1];

void solve()
{
  deque<int> d;
  REP(i, N)
  {
    int p = lower_bound(d.begin(), d.end(), A[i]) - d.begin();
    if (p == 0) {
      d.push_front(A[i]);
    }
    else {
      d[p - 1] = A[i];
    }
  }
  int ans = d.size();
  cout << ans << endl;
}

int main(void)
{
  cin >> N;
  REP(i, N) cin >> A[i];
  solve();
  return 0;
}
