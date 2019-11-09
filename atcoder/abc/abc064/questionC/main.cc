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

int N;
int a[MAX_N];

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N;
  REP(i, N) cin >> a[i];
  map<string, bool> mp;
  int freeC = 0;

  for (int i = 0; i < N; i++) {
    if (1 <= a[i] && a[i] <= 399)
      mp["gray"] = true;
    else if (400 <= a[i] && a[i] <= 799)
      mp["brown"] = true;
    else if (800 <= a[i] && a[i] <= 1199)
      mp["green"] = true;
    else if (1200 <= a[i] && a[i] <= 1599)
      mp["aqua"] = true;
    else if (1600 <= a[i] && a[i] <= 1999)
      mp["blue"] = true;
    else if (2000 <= a[i] && a[i] <= 2399)
      mp["yellow"] = true;
    else if (2400 <= a[i] && a[i] <= 2799)
      mp["orange"] = true;
    else if (2800 <= a[i] && a[i] <= 3199)
      mp["red"] = true;
    else
      freeC++;
  }

  int ans = 0;
  for (auto m : mp) {
    if (m.second > 0) ans++;
  }

  int offset = 0;
  if (ans == 0 && freeC > 0) {
    offset++;
  }

  printf("%d %d\n", ans + offset, ans + freeC);

  return 0;
}
