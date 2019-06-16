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

// Self settings
// clang-format off
#define MAX_N 10000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

int N, X;
int L[MAX_N];
int D[MAX_N + 1];

void solve()
{
  REP(i, N) D[i + 1] = D[i] + L[i];
  int cnt = 0;
  for (int i = 0; i <= N; ++i) {
    if (D[i] > X) {
      break;
    }
    cnt++;
  }
  cout << cnt << endl;
}

int main(void)
{
  cin >> N >> X;
  REP(i, N) cin >> L[i];
  solve();
  return 0;
}
