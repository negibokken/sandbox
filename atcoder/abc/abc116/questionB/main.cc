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

int s;
map<int, int> m;

int main(void)
{
  cin >> s;
  int i = 1;
  m[s]++;
  while (1) {
    i++;
    if (s % 2 == 0)
      s = s / 2;
    else
      s = 3 * s + 1;
    if (m.count(s) > 0) break;
    m[s]++;
  }
  cout << i << endl;
  return 0;
}
