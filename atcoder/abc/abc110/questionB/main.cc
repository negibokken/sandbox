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
#define MAX_M 100
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
// clang-format on

int N, M, X, Y;

int main(void)
{
  cin >> N >> M >> X >> Y;
  vector<int> x(N), y(M);
  REP(i, N) cin >> x[i];
  REP(i, M) cin >> y[i];

  int xmax = *max_element(x.begin(), x.end());
  int ymin = *min_element(y.begin(), y.end());

  int d = (ymin - xmax);
  int Z = xmax + d;
  if (d >= 1 && (X < Z && Z <= Y) && xmax < Z && Z <= ymin) {
    cout << "No War" << endl;
  }
  else {
    cout << "War" << endl;
  }
  return 0;
}
