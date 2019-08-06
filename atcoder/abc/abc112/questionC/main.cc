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

int N;
int x[MAX_N], y[MAX_N], h[MAX_N];

void solve()
{
  for (int j = 0; j <= 100; j++) {
    for (int k = 0; k <= 100; k++) {
      int nh = -1;
      for (int i = 0; i < N; i++) {
        if (h[i] > 0) {
          int tmp = abs(x[i] - j) + abs(y[i] - k) + h[i];
          if (nh == -1) {
            nh = tmp;
          }
          else {
            if (nh != tmp) {
              nh = -2;
              break;
            }
          }
        }
      }
      if (nh == -2) continue;

      for (int i = 0; i < N; i++) {
        if (h[i] == 0) {
          int dist = abs(j - x[i]) + abs(y[i] - k);
          if (nh > dist) {
            nh = -2;
            break;
          }
        }
      }
      if (nh == -2) continue;
      cout << j << " " << k << " " << nh << endl;
      return;
    }
  }
}

int main(void)
{
  cin >> N;
  REP(i, N) cin >> x[i] >> y[i] >> h[i];
  solve();
  return 0;
}
