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
#include <stack>
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

int N;
ll dp[100];

void solve()
{
  stack<int> q;
  int dig = 0;
  int n = N;
  while (n > 0) {
    q.push(n % 10);
    n /= 10;
    dig++;
  }

  int i = 0;
  while (!q.empty()) {
    int a = q.top();
    q.pop();
    int cnt = 0;
    if (a >= 7) cnt++;
    if (a >= 5) cnt++;
    if (a >= 3) cnt++;
    if (cnt == 0) {
      dp[i + 1] = dp[i];
    }
    else {
      dp[i + 1] = dp[i] * cnt;
    }
  }
  if (dig <= 2) {
    cout << 0 << endl;
  }
  else {
    cout << dp[dig] << endl;
  }
}

int main(void)
{
  cin >> N;
  solve();
  return 0;
}
