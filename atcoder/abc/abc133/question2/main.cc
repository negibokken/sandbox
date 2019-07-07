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
#define MAX_N 100
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

int N, D;
int X[MAX_N][MAX_N];

bool C(double x) { return ceil(x) == floor(x); }

double innerDist(int x, int y) { return abs(x - y) * abs(x - y); }

int main(void)
{
  cin >> N >> D;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < D; j++) {
      cin >> X[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      double d = 0;
      for (int k = 0; k < D; k++) {
        d += innerDist(X[i][k], X[j][k]);
      }
      double dd = sqrt(d);
      if (C(dd)) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
