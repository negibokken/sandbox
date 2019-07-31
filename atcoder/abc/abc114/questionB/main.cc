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
#define MAX_N 11
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
// clang-format on

char S[MAX_N];

void solve()
{
  int ans = INT_MAX;
  int n = strlen(S);
  for (int i = 0; i <= n - 3; i++) {
    int a = 0;
    int k = 0;
    while (k < 3) {
      a += (S[i + k] - '0') * (int)pow(10, 2 - k);
      k++;
    }
    ans = min(ans, abs(753 - a));
  }
  cout << ans << endl;
}

int main(void)
{
  cin >> S;
  solve();
  return 0;
}
