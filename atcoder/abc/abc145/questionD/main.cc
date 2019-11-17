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

const ll mod =  1000000007;
// Self settings
// clang-format off
#define MAX_N 1000000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
// clang-format on

ll fact(ll m) {
  ll res = 1;
  for(int i = 2; i <= m; i++) {
    res = (res * i) % mod;
  }
  return res;
}

ll mypow(ll m, ll p) {
  if(m == 0) return 0;
  ll res = 1;
  while(p) {
    if(p & 1) res = (res * m) % mod;
    p >>= 1;
    m = (m*m) % mod;
  }
  return res;
}

int X, Y;
int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> X >> Y;

  ll n = (2*Y-X)/3;
  ll m = (2*X-Y)/3;

  if((X+Y) % 3 != 0) {
    cout << 0 << endl;
    return 0;
  }
  if(n < 0 || m < 0 ) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = fact(n+m) * (ll)mypow(fact(n),mod-2) % mod * (ll)mypow(fact(m),mod-2) % mod;
  cout << ans << endl;
  return 0;
}
