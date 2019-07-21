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
#define MAX_N 300000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

int N;
int A[MAX_N + 1];
int B[MAX_N + 1];

void solve()
{
  int M = 0;
  // 1-indexed
  for (int i = N; i >= 1; i--) {
    int bb = 0;
    // i 以上で i の倍数のボールの個数がどうなっていたか
    for (int j = i + i; j <= N; j += i) {
      bb += B[j];
    }
    // 制約チェック
    // ボールがすでに A[i] の制約を満たしているなら
    if (bb % 2 == A[i]) {
      // ボールを加えない
      B[i] = 0;
    }
    else {
      // ボールを加える
      B[i] = 1;
      M++;
    }
  }
  int idx = 0;
  // search last 1
  for (int i = 1; i <= N; i++) {
    if (B[i] == 1) idx = i;
  }
  cout << M << endl;
  for (int i = 1; i <= idx; i++) {
    if (B[i] == 1) cout << i << (i == idx ? "\n" : " ");
  }
}

int main(void)
{
  cin >> N;
  // 1-indexed
  REP(i, N) cin >> A[i + 1];
  solve();
  return 0;
}
