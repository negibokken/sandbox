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

int main(void)
{
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  int dx = x2 - x1, dy = y2 - y1;

  int x3 = x2 - dy, y3 = y2 + dx;
  int x4 = x1 - dy, y4 = y1 + dx;
  cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
  return 0;
}
