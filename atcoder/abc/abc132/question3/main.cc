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
#define MAX_N 100001
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

int N;
int d[MAX_N];

int main(void)
{
  scanf("%d", &N);
  REP(i, N) scanf("%d", &d[i]);
  sort(d, d + N);
  int cnt = 0;
  for (int i = 0; i < MAX_N; i++) {
    int k = lower_bound(d, d + N, i) - d;
    if (k == (N - k)) cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}
