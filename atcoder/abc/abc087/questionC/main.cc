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
ll fact(ll n) { ll res = 1; for(ll i=2;i<=n;++i) res = res * i; return res;}
ll nCr(ll n, ll r) {return (fact(n)/fact(n-r)*fact(r)) ;}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
const ll MOD = 1e9+7;
const ll INF = 1LL << 60;
const int inf = 1 << 31;
// clang-format on

int N;
int A[2][MAX_N];
int dp[2][MAX_N];

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  REP(i, 2) REP(j, N) cin >> A[i][j];

  dp[0][0] = A[0][0];
  for (int j = 1; j < N; j++) {
    dp[0][j] = dp[0][j - 1] + A[0][j];
  }
  for (int j = 0; j < N; j++) {
    // 上からか左からか
    if (j - 1 < 0) {
      dp[1][j] = dp[0][j] + A[1][j];
    }
    else {
      dp[1][j] = max(dp[0][j], dp[1][j - 1]) + A[1][j];
    }
  }

  cout << dp[1][N - 1] << endl;

  return 0;
}
