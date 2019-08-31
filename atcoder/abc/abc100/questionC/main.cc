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

map<int, int> prime_factor(int n)
{
  map<int, int> mp;
  for (int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      mp[i]++;
      n /= i;
    }
  }
  if (n != 1) mp[n] = 1;
  return mp;
}

int main(void)
{
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i, n) cin >> a[i];

  ll ans = 0;
  REP(i, n)
  {
    map<int, int> m = prime_factor(a[i]);
    if (m.count(2) > 0) ans += m[2];
  }
  cout << ans << endl;
  return 0;
}
