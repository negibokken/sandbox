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

//                 0 1   2   3
//                 L  D   U  R
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

// Self settings
// clang-format off
#define MAX_N 100000
#define MAX_W 4000
#define MAX_H 4000
#define INF 1000000000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
// clang-format on

int H, W;
bool S[MAX_H][MAX_W];
int memo[MAX_H][MAX_W][4];

// L: 0
// D: 1
// U: 2
// R: 3
int dfs(int i, int j, int d)
{
  // 範囲外なら 0 を返す
  if (j < 0 || j >= W || i < 0 || i >= H) return 0;

  // 壁の場合 0 を返す
  if (!S[i][j]) return 0;

  // すでに訪問済みならそれを返す
  if (memo[i][j][d] != INF) {
    return memo[i][j][d];
  }

  // 自分自身を数える
  int sum = 1;
  // ある方向dのすべてのマスを順番に数えていく
  sum += dfs(i + dy[d], j + dx[d], d);
  return memo[i][j][d] = sum;
}

void solve()
{
  // Init
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      for (int k = 0; k < 4; k++) memo[i][j][k] = INF;
    }
  }

  int ans = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (!S[i][j]) continue;
      int sum = 0;
      for (int k = 0; k < 4; k++) {
        // 各方向の成分を足す
        sum += dfs(i, j, k);
      }
      // 自分自身を４回数えてるので3減らす
      sum -= 3;
      ans = max(ans, sum);
    }
  }

  cout << ans << endl;
}

int main(void)
{
  cin >> H >> W;
  REP(i, H) REP(j, W)
  {
    char c;
    cin >> c;
    S[i][j] = (c == '.');
  }
  solve();
  return 0;
}
