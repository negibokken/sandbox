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

  double a = 0;
  ll all = 1;
  REP(i, N) { a += 1.0 / A[i]; }
  printf("%.10f\n", 1.0 / (double)a);
  return 0;
}
