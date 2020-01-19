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
ll nPr(ll n, ll r) {return (fact(n)/fact(n-r)) ;}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
const ll MOD = 1e9+7;
const ll INF = 1LL << 60;
const int inf = 1000000;
// clang-format on

int N;
int lsn(int n) { return n % 10; }

int msn(int n) {
  int d = n;
  while (n >= 10) {
    d = n;
    n /= 10;
  }
  return n;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N;

  map<int, map<int, int>> mp;
  for (int i = 1; i <= N; i++) {
    mp[lsn(i)][msn(i)]++;
  }

  ll ans = 0;
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      ll m = (mp[i][j] * mp[j][i]);
      ans += (ll)m;
    }
  }
  cout << ans << endl;

  return 0;
}
