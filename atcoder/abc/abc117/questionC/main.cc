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

int N, M;
int diff[MAX_N + 1];
int X[MAX_N + 1];

int main(void)
{
  cin >> N >> M;
  REP(i, M) cin >> X[i];

  sort(X, X + M);

  priority_queue<int> q;
  diff[0] = 0;
  REP(i, M - 1)
  {
    if (M - 1 == 0) break;
    diff[i + 1] = X[i + 1] - X[i];
    q.push(diff[i + 1]);
  }
  int sum = X[M - 1] - X[0];

  int n = N - 1;
  while (n > 0 && !q.empty()) {
    int s = q.top();
    q.pop();
    sum -= s;
    n--;
  }
  cout << sum << endl;
  return 0;
}
