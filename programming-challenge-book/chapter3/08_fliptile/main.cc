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

const int dx[5] = {-1, 0, 0, 0, 1};
const int dy[5] = {0, -1, 0, 1, 0};

// Self settings
// clang-format off
#define MAX_N 10000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

int M, N;
int tile[MAX_N][MAX_N];
int opt[MAX_N][MAX_N];
int flip[MAX_N][MAX_N];

int get(int x, int y)
{
  int c = tile[x][y];
  for (int d = 0; d < 5; d++) {
    int x2 = x + dx[d], y2 = y + dy[d];
    if (0 <= x2 && x2 < M && 0 <= y2 && y2 < N) {
      c += flip[x2][y2];
    }
  }
  return c % 2;
}

int calc()
{
  for (int i = 1; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (get(i - 1, j) != 0) {
        flip[i][j] = 1;
      }
    }
  }

  for (int j = 0; j < N; j++) {
    if (get(M - 1, j) != 0) {
      return -1;
    }
  }

  int res = 0;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      res += flip[i][j];
    }
  }
  return res;
}

void solve()
{
  int res = -1;

  for (int i = 0; i < 1 << N; i++) {
    memset(flip, 0, sizeof(flip));
    for (int j = 0; j < N; j++) {
      flip[0][N - j - 1] = i >> j & 1;
    }
    int num = calc();
    if (num >= 0 && (res < 0 || res > num)) {
      res = num;
      memcpy(opt, flip, sizeof(flip));
    }
  }
  if (res < 0) {
    printf("IMPOSSIBLE\n");
  }
  else {
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        printf("%d%c", opt[i][j],
               (((i == M - 1) && (j == N - 1)) ? '\n' : ' '));
      }
    }
  }
}

int main(void)
{
  cin >> M >> N;
  REP(i, M) REP(j, N) cin >> tile[i][j];
  solve();
  return 0;
}
