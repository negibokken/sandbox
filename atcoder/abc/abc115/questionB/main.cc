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
int p[MAX_N];

int main(void)
{
  cin >> N;
  REP(i, N) cin >> p[i];
  int sum = 0;
  int m = 0;
  for (int i = 0; i < N; i++) {
    m = max(m, p[i]);
    sum += p[i];
  }
  sum -= (m / 2);
  cout << sum << endl;
  return 0;
}
