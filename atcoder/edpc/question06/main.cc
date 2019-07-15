#include <string.h>
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
typedef pair<char, int> Pc;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

// Self settings
// clang-format off
#define MAX_N 3000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on
char s[MAX_N + 1], t[MAX_N + 1];
int dp[MAX_N + 1][MAX_N + 1];

void solve()
{
  int sl = strlen(s), tl = strlen(t);
  REP(i, sl + 1) REP(j, tl + 1) dp[i][j] = 0;
  for (int i = 0; i < sl; i++) {
    for (int j = 0; j < tl; j++) {
      if (s[i] == t[j]) {
        dp[i + 1][j + 1] = dp[i][j] + 1;
      }
      else {
        dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
      }
    }
  }
  if (dp[sl][tl] == 0) {
    cout << " " << endl;
  }
  else {
    string ans = "";
    int cur = dp[sl][tl];
    int i = sl, j = tl;
    while (i > 0 && j > 0) {
      if (s[i - 1] == t[j - 1]) {
        ans += s[i - 1];
        cur--;
        i--, j--;
      }
      else if (i - 1 >= 0 && dp[i - 1][j] == cur) {
        i--;
      }
      else if (j - 1 >= 0 && dp[i][j - 1] == cur) {
        j--;
      }
      else {
        i--;
      }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
  }
}

int main(void)
{
  cin >> s >> t;
  solve();
  return 0;
}
