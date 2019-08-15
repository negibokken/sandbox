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

int A[MAX_N];
int L[MAX_N + 1];
int R[MAX_N + 1];
int M[MAX_N + 1];

int gcdd(int a, int b)
{
  if (b == 0) {
    return a;
  }
  return gcdd(b, a % b);
}

int gcd(int a, int b)
{
  if (a == 0) {
    return b;
  }
  else if (b == 0) {
    return a;
  }
  return gcdd(a, b);
}

int main(void)
{
  std::ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  REP(i, N) cin >> A[i];

  ll sum = 0;
  L[0] = 0;
  for (int i = 0; i < N; i++) {
    L[i + 1] = gcd(L[i], A[i]);
  }

  R[N] = 0;
  for (int i = N - 1; i >= 0; i--) {
    R[i] = gcd(R[i + 1], A[i]);
  }

  for (int i = 0; i < N; i++) {
    M[i] = gcd(L[i], R[i + 1]);
  }

  int ans = 0;
  REP(i, N) { ans = max(ans, M[i]); }
  cout << ans << endl;

  return 0;
}
