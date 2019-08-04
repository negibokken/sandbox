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

int N;
int H[MAX_N + 5];

void solve()
{
  bool flag = true;
  for (int i = N - 1; i > 0; i--) {
    if (H[i] < H[i - 1]) H[i - 1]--;
    if (H[i - 1] > H[i]) {
      flag = false;
      break;
    }
  }
  cout << (flag ? "Yes" : "No") << endl;
}

int main(void)
{
  cin >> N;
  REP(i, N) cin >> H[i];
  solve();
  return 0;
}
