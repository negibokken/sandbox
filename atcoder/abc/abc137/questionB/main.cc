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
  int K, X;
  cin >> K >> X;

  int l = max(X - (K - 1), -1000000);
  int r = min(X + (K - 1), 1000000);
  for (int i = l; i <= r; i++) {
    cout << i << (i == r ? "\n" : " ");
  }

  return 0;
}
