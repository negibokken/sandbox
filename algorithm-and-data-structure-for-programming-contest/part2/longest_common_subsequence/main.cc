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
const int inf = 1000100011;
// clang-format on
int dp[MAX_N][MAX_N];

void init(int n) { REP(i, n + 1) REP(j, n + 1) dp[i][j] = 0; }

int lcs(string X, string Y) {
  for (int i = 0; i < X.size(); i++) {
    for (int j = 0; j < Y.size(); j++) {
      if (X[i] == Y[j]) {
        dp[i + 1][j + 1] = dp[i][j] + 1;
      } else {
        dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
      }
    }
  }
  return dp[X.size()][Y.size()];
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  string X, Y;
  REP(i, n) {
    cin >> X >> Y;
    init(max(X.size(), Y.size()));
    int ans = lcs(X, Y);
    cout << ans << endl;
  }

  return 0;
}
