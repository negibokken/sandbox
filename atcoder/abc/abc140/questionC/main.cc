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
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
const ll MOD = 1e9+7;
const ll INF = 1LL << 60;
const int inf = 1 << 31;
// clang-format on

int N;
int A[MAX_N];
int B[MAX_N];

int main(void)
{
  cin >> N;
  REP(i, N - 1) cin >> B[i];

  A[0] = B[0];
  for (int i = 1; i < N - 1; i++) {
    A[i] = min(B[i], B[i - 1]);
  }
  A[N - 1] = B[N - 2];
  int ans = 0;
  for (int i = 0; i < N; i++) ans += A[i];
  cout << ans << endl;

  return 0;
}
