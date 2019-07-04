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
#define MAX_N 100000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

int N, L;
int s[MAX_N];

void solve()
{
  for (int i = 0; i < N; i++) {
    s[i] = L + (i + 1) - 1;
  }
  int idx;
  int m = 1000;
  for (int i = 0; i < N; i++) {
    if (abs(s[i]) < m) {
      m = abs(s[i]);
      idx = i;
    }
  }
  int sum = 0;
  for (int i = 0; i < N; i++) {
    sum += s[i];
  }
  sum -= s[idx];
  printf("%d\n", sum);
}

int main(void)
{
  cin >> N >> L;
  solve();
  return 0;
}
