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
#include <stack>
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
int N;
int C753[] = {7, 5, 3};

bool is753(ll s)
{
  ll ss = s;
  int cnt = 0;
  for (int i = 0; i < 3; i++) {
    ss = s;
    while (ss > 0) {
      if (ss % 10 == C753[i]) {
        cnt++;
        ss /= 10;
        break;
      }
      ss /= 10;
    }
  }
  return cnt == 3;
}

int dfs(ll s)
{
  // cout << s << endl;
  if (s > N) {
    return 0;
  }
  ll ret = is753(s) ? 1 : 0;
  for (int i = 0; i < 3; i++) {
    ret += dfs(s * 10 + C753[i]);
  }
  return ret;
}

void solve() { cout << dfs(0) << endl; }

int main(void)
{
  cin >> N;
  solve();
  return 0;
}
