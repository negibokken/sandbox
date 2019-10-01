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
const int inf = 1 << 30;
// clang-format on

int A, B, C, X;

int dp[4][50000];

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> A >> B >> C >> X;
  vector<int> a(3);
  const int coins[] = {50, 100, 500};
  a[2] = A, a[1] = B, a[0] = C;

  for (int i = 0; i <= 3; i++) {
    for (int j = 0; j <= 20000; j++) {
      dp[i][j] = inf;
    }
  }

  // for (int i = 0; i < 4; i++) dp[0][0] = 1;
  // for (int i = 0; i < 4; i++) dp[i][0] = 1;

  dp[0][0] = 1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j <= 20000; j++) {
      if (j - coins[i] < 0) {
        if (j == 0) continue;
        dp[i + 1][j] = dp[i][j];
      }
      else {
        if (a[i] <= 0 || dp[i + 1][j - coins[i]] == inf) continue;
        dp[i + 1][j] = dp[i + 1][j - coins[i]] + dp[i][j - coins[i]];
        a[i]--;
      }
    }
  }

  cout << endl;
  for (int i = 0; i <= 3; i++) {
    for (int j = 0; j <= 100; j++) {
      cout << (dp[i][j] == inf ? "*" : to_string(dp[i][j])) << " ";
    }
    cout << endl;
  }

  cout << (dp[3][X] == inf ? 0 : dp[3][X]) << endl;

  return 0;
}
