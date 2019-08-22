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

int L;

int main(void)
{
  cin >> L;
  int l = L;
  int r = 0;
  while (l > 0) {
    r++, l >>= 1;
  }
  r = min(19, r);
  cout << r << endl;

  int N = r + 1;
  vector<vector<P>> G(N);

  for (int i = 0; i < N - 1; i++) {
    G[i].push_back(P(i + 1, (int)pow(2, i)));
  }

  int X = L;
  for (int t = N - 1; t >= 0; t--) {
    if (L - (int)pow(2, t - 1) >= (int)pow(2, r)) {
      G[t].push_back(P(N, X - (int)pow(2, t - 1)));
      X -= (int)pow(2, t - 1);
    }
  }
  return 0;
}
