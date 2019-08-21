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
#include <tuple>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

// 左, 上, 右, 下
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

// Self settings
// clang-format off
#define MAX_N 100000
#define MAX_H 500
#define MAX_W 500
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
// clang-format on

int H, W;
int a[MAX_H][MAX_W];
int N = 0;
tuple<int, int, int, int> ops[MAX_H * MAX_W + 1];

void op(int h, int w, int d)
{
  int nw = w + dx[d], nh = h + dy[d];
  // 範囲外なら continue
  if (nw < 0 || nw >= W) return;
  if (nh < 0 || nh >= H) return;
  // 奇数なら移動させる
  // 交換する
  a[h][w]--, a[nh][nw]++;
  ops[N] = make_tuple(h + 1, w + 1, nh + 1, nw + 1);
  N++;
}

int main(void)
{
  cin >> H >> W;
  REP(i, H) REP(j, W) cin >> a[i][j];

  for (int i = 0; i < H; i++) {
    if (i % 2 == 0) {
      for (int j = 0; j < W; j++) {
        // 奇数を探して操作する
        if (a[i][j] % 2 == 0) continue;
        int d = 2;
        // 一番端っこなら下に送る
        if (j == W - 1) d = 3;
        op(i, j, d);
      }
    }
    else {
      for (int j = W - 1; j >= 0; j--) {
        // 奇数を探して操作する
        if (a[i][j] % 2 == 0) continue;
        int d = 0;
        if (j == 0) d = 3;
        op(i, j, d);
      }
    }
  }

  cout << N << endl;
  for (int i = 0; i < N; i++) {
    cout << get<0>(ops[i]) << " " << get<1>(ops[i]) << " " << get<2>(ops[i])
         << " " << get<3>(ops[i]) << endl;
  }
  return 0;
}
