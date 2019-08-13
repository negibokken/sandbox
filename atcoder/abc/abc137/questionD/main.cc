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
#define MAX_W 10000
#define INF 10000000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
// clang-format on

int N, M;
int A[MAX_N], B[MAX_N];

int main(void)
{
  cin >> N >> M;
  vector<vector<int>> jobs(M);
  REP(i, N)
  {
    int a, b;
    cin >> a >> b;
    if (a > M) continue;
    jobs[M - a].push_back(b);
  }

  priority_queue<int> q;
  ll ans = 0;
  for (int i = M - 1; i >= 0; i--) {
    for (int b : jobs[i]) {
      q.push(b);
    }
    if (!q.empty()) {
      ans += q.top();
      q.pop();
    }
  }
  cout << ans << endl;

  return 0;
}
