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
int A[MAX_N];

int main(void)
{
  cin >> N;
  REP(i, N) cin >> A[i];

  int zero = 0;
  int minus = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] < 0) minus++;
    if (A[i] == 0) zero++;
  }

  ll ans = 0;
  if (minus % 2 == 0 || zero > 0) {
    // Add all
    for (int i = 0; i < N; i++) ans += abs(A[i]);
  }
  else {
    int mi = 1000000001;
    for (int i = 0; i < N; i++) {
      mi = min(mi, abs(A[i]));
    }
    for (int i = 0; i < N; i++) ans += abs(A[i]);
    ans -= 2 * mi;
  }

  cout << ans << endl;

  return 0;
}
