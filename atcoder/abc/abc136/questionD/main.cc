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
#define MAX_N 1000000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
// clang-format on

char S[MAX_N + 1];
int ans[MAX_N];

void solve()
{
  int n = strlen(S);

  int even = 0, odd = 0;
  int t = 0;
  while (t < n) {
    int cnt = 0;
    // Find R near by L
    while (S[t] == 'R' && t < n) {
      t++, cnt++;
    }
    cnt++;
    int r = t - 1, l = t;
    int d = (cnt + 1) / 2;
    ans[l] += d;
    ans[r] += cnt - d;

    cnt = 0;
    // L の間すすめる
    while (S[t] == 'L' && t < n) t++, cnt++;
    t--, cnt--;
    d = (cnt + 1) / 2;
    ans[r] += d;
    ans[l] += cnt - d;
    t++;
  }
  REP(i, n) cout << ans[i] << SLN(i, n);
}

int main(void)
{
  cin >> S;
  solve();
  return 0;
}
