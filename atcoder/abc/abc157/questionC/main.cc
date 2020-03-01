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

int N, M;

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> M;

  vector<int> sum(N);
  REP(i, N) sum[i] = -1;

  vector<int> s(N), c(N);
  REP(i, M) {
    cin >> s[i] >> c[i];
    s[i]--;  // 0-indexed
    if ((sum[s[i]] != -1 && sum[s[i]] != c[i]) || s[i] > N) {
      cout << -1 << endl;
      return 0;
    }
    sum[s[i]] = c[i];
  }

  vector<int> ans(N);
  REP(i, N) {
    if (sum[i] != -1) {
      ans[i] = sum[i];
    } else {
      ans[i] = 0;
    }
  }

  bool flag = false;
  REP(i, M) flag |= (s[i] == 0);
  if (N != 1 && ans[0] == 0 && !flag) ans[0] = 1;

  int zeroNum = 0;
  REP(i, N) {
    if (ans[i] == 0) zeroNum += 1;
  }
  if (zeroNum == N && N != 1) {
    cout << -1 << endl;
    return 0;
  }
  REP(i, N) cout << ans[i];
  cout << endl;

  return 0;
}
