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

int N, T, A;
int H[MAX_N];

void solve()
{
  int minindex = 0;
  double mi = INT_MAX;
  for (int i = 1; i <= N; i++) {
    double diff = abs((double)A - ((double)T - (double)H[i] * 0.006));
    if (diff < mi) {
      mi = diff, minindex = i;
    }
  }
  cout << minindex << endl;
}

int main(void)
{
  cin >> N >> T >> A;
  for (int i = 1; i <= N; i++) cin >> H[i];
  solve();
  return 0;
}
