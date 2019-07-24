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
ll A[MAX_N];

ll gcd(ll a, ll b)
{
  if (a == 0) return b;
  return gcd(b % a, a);
}

void solve()
{
  int ans = A[0];
  for (int i = 1; i < N; i++) {
    ans = gcd(ans, A[i]);
  }
  cout << ans << endl;
}

int main(void)
{
  cin >> N;
  REP(i, N) cin >> A[i];
  solve();
  return 0;
}