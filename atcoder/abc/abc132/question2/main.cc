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
// clang-format on

int n;
int p[MAX_N];

int main(void)
{
  cin >> n;
  REP(i, n) scanf("%d", &p[i]);
  int cnt = 0;
  for (int i = 1; i < n - 1; i++) {
    if (p[i - 1] < p[i] && p[i] < p[i + 1]) cnt++;
    if (p[i + 1] < p[i] && p[i] < p[i - 1]) cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}
