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

int n;
int v[MAX_N];

void solve()
{
  map<int, int> m[2];
  for (int i = 0; i < n; i++) {
    m[i % 2][v[i]]++;
  }
  priority_queue<P> q[2];
  for (int i = 0; i < 2; i++) {
    for (auto v : m[i]) {
      q[i].push(P(v.second, v.first));
    }
  }

  int d0, d1;
  // もしも同じ数字が一番数が多い場合条件2に反するので
  // 数が多い方をそのまま、数が少ない方を二番目に多い方に変える
  // ただし、二個同じcntのがある場合はそちらの pop を優先する
  P p0 = P(0, 0), p1 = P(0, 0);
  while (p0.second == p1.second) {
    p0 = q[0].top();
    q[0].pop();
    p1 = q[1].top();
    q[1].pop();

    // もし同じ数字なら違う数字に変える
    if (p0.second == p1.second) {
      // どっちに交換したほうがいいか調べてみる
      P p0sub, p1sub;
      if (!q[1].empty())
        p1sub = q[1].top();
      else
        p1sub = P(0, -1);
      if (!q[0].empty())
        p0sub = q[0].top();
      else
        p0sub = P(0, -1);

      if (p0.first - p0sub.first < p1.first - p1sub.first) {
        p0 = p0sub;
      }
      else {
        p1 = p1sub;
      }
    }
  }
  d0 = p0.first, d1 = p1.first;
  int ans = n / 2 - d0 + n / 2 - d1;
  cout << ans << endl;
}

int main(void)
{
  cin >> n;
  REP(i, n) cin >> v[i];
  solve();
  return 0;
}
