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

ll L, R;
const ll mod = 2019;

int main(void)
{
  cin >> L >> R;

  R = min(R, L + 4096);
  map<ll, int> n, m;
  ll ans = INT_MAX;
  for (int i = L; i < R; i++) {
    for (int j = i + 1; j <= R; j++) {
      ll a = i * j % mod;
      ans = min(ans, a);
      if (ans == 0) {
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
