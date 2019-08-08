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
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < 3; i++) {
    int d = n % 10;
    if (d == 1) {
      d = 9;
    }
    else if (d == 9) {
      d = 1;
    }
    ans += d * (int)pow(10, i);
    n /= 10;
  }
  cout << ans << endl;
  return 0;
}
