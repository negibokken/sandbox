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
#define MAX_N 8
#define INF 1000000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

int N, A, B, C;
int l[MAX_N];

int dfs(int cur, int a, int b, int c)
{
  if (cur == N) {
    if (min({a, b, c}) > 0) {
      return abs(a - A) + abs(b - B) + abs(c - C) - 30;
    }
    else {
      return INF;
    }
  }
  int ret0 = dfs(cur + 1, a, b, c);
  int ret1 = dfs(cur + 1, a + l[cur], b, c) + 10;
  int ret2 = dfs(cur + 1, a, b + l[cur], c) + 10;
  int ret3 = dfs(cur + 1, a, b, c + l[cur]) + 10;
  return min({ret0, ret1, ret2, ret3});
}

void solve() { cout << dfs(0, 0, 0, 0) << endl; }

int main(void)
{
  cin >> N >> A >> B >> C;
  REP(i, N) cin >> l[i];
  sort(l, l + N);
  solve();
  return 0;
}
