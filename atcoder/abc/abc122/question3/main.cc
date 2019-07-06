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

int N, Q;
char S[MAX_N + 1];
int l[MAX_N], r[MAX_N];
int d[MAX_N];

void solve()
{
  int cnt = 0;
  for (int i = 1; i < N; i++) {
    if (S[i - 1] == 'A' && S[i] == 'C') cnt++;
    d[i] = cnt;
  }
  for (int i = 0; i < Q; i++) {
    cout << d[r[i] - 1] - d[l[i] - 1] << endl;
  }
}

int main(void)
{
  cin >> N >> Q;
  cin >> S;
  REP(i, Q) cin >> l[i] >> r[i];
  solve();
  return 0;
}
