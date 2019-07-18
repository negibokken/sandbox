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
int A, B, K;

void solve()
{
  int ans = 0;
  int cnt = 0;
  for (int i = min(A, B); i >= 1; i--) {
    if (A % i == 0 && B % i == 0) cnt++;
    if (cnt == K) {
      ans = i;
      break;
    }
  }
  cout << ans << endl;
}

int main(void)
{
  cin >> A >> B >> K;
  solve();
  return 0;
}
