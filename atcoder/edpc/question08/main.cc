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

//                 L  U
const int dx[2] = {-1, 0};
const int dy[2] = {0, -1};

// Self settings
// clang-format off
#define MAX_HW 1000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on
int H, W;
bool board[MAX_HW][MAX_HW];
ll dp[MAX_HW + 1][MAX_HW + 1];
const int mod = 1000000007;

int neighbor(int x, int y)
{
  ll n = 0;
  for (int i = 0; i < 2; i++) {
    int xx = x + dx[i], yy = y + dy[i];
    // 盤外か岩なら組み合わせからはずす
    if (xx < 0 || yy < 0 || !board[xx][yy]) continue;
    n = (n + dp[xx][yy]) % mod;
  }
  return n;
}

void solve()
{
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      // 岩もしくは最初はスキップ
      if (!board[i][j] || (i == 0 && j == 0)) continue;
      dp[i][j] = neighbor(i, j);
    }
  }
  cout << dp[H - 1][W - 1] << endl;
}

int main(void)
{
  cin >> H >> W;
  REP(i, H) REP(j, W)
  {
    char x;
    cin >> x;
    if (x == '.')
      board[i][j] = true;
    else
      board[i][j] = false;
  }
  solve();
  return 0;
}
