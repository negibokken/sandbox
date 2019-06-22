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
// typedef pair<int, int> P;

// Self settings
// clang-format off
#define MAX_N 100000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

int P;
int a[MAX_N];

void solve()
{
  set<int> all;
  for (int i = 0; i < P; i++) {
    all.insert(a[i]);
  }
  int n = all.size();

  int s = 0, t = 0, num = 0;
  map<int, int> count;
  int res = P;
  for (;;) {
    while (t < P && num < n) {
      if (count[a[t++]]++ == 0) {
        num++;
      }
    }
    if (num < n) break;
    res = min(res, t - s);
    while (s < t && num == n) {
      --count[a[s]];
      if (count[a[s++]] == 0) {
        num--;
      }
      else {
        res = min(res, t - s);
      }
    }
  }
  cout << res << endl;
}

int main(void)
{
  cin >> P;
  REP(i, P) cin >> a[i];
  solve();
  return 0;
}
