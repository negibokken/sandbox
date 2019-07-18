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
typedef unsigned long long ull;
typedef pair<int, int> P;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

// Self settings
// clang-format off
#define MAX_N 100000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on
ll A, B;

void solve()
{
  ll ans = 0;
  ll a = A, b = B;
  if (a % 2 == 0 && b % 2 == 0) {
    ans = b ^ (((b - a) / 2) % 2 == 1 ? 1 : 0);
  }
  else if (a % 2 == 0 && b % 2 == 1) {
    ans = (((b - a + 1) / 2) % 2 == 1 ? 1 : 0);
  }
  else if (a % 2 == 1 && b % 2 == 0) {
    ans = a ^ (((b - a - 1) / 2) % 2 == 1 ? 1 : 0) ^ b;
  }
  else {
    ans = a ^ (((b - a) / 2) % 2 == 1 ? 1 : 0);
  }
  cout << ans << endl;
}

int main(void)
{
  cin >> A >> B;
  solve();
  return 0;
}
