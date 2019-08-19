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
#define sz(x) int(x.size())
// clang-format on

char s[MAX_N + 1], t[MAX_N + 1];

int main(void)
{
  string s, t;
  cin >> s >> t;

  int n = sz(s), m = sz(t);
  vector<vector<int>> is(26);
  REP(i, n) is[s[i] - 'a'].push_back(i);
  REP(i, n) is[s[i] - 'a'].push_back(i + n);

  ll ans = 0;
  int p = 0;
  REP(i, m)
  {
    int c = t[i] - 'a';
    if (sz(is[c]) == 0) {
      puts("-1");
      return 0;
    }
    p = *lower_bound(is[c].begin(), is[c].end(), p) + 1;
    if (p >= n) {
      p -= n;
      ans += n;
    }
  }
  ans += p;
  cout << ans << endl;
  return 0;
}
