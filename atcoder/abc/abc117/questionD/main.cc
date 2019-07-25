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
ll K;
ll A[MAX_N];
int bits[41];

int main(void)
{
  cin >> N >> K;
  REP(i, N) cin >> A[i];
  ll orgsum = 0;
  ll k = 0;
  for (int i = 0; i < N; i++) {
    orgsum += k ^ A[i];
  }

  int bit = 1;
  ll ansK = 0;
  while ((ll)K >= bit) {
    ll sum = 0;
    for (int i = 0; i < N; i++) {
      sum += bit ^ A[i];
    }
    if (sum > orgsum) ansK |= bit;
    bit <<= 1;
  }
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    ans += ansK ^ A[i];
  }
  cout << ans << endl;
  return 0;
}
