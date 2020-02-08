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

typedef struct {
  char c;
  int scolar;
} D;

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;

  vector<vector<D>> orders(4);
  // 一往復目
  orders[0] = {{'U', ty - sy}, {'R', tx - sx}};
  orders[1] = {{'D', ty - sy}, {'L', tx - sx}};

  // 二往復目
  orders[2] = {{'D', 1},
               {'R', orders[0][1].scolar + 1},
               {'U', orders[0][0].scolar + 1},
               {'L', 1}};
  orders[3] = {{'U', 1},
               {'L', orders[1][1].scolar + 1},
               {'D', orders[1][0].scolar + 1},
               {'R', 1}};

  for (int i = 0; i < 4; i++) {
    for (auto order : orders[i]) {
      for (int j = 0; j < order.scolar; j++) {
        cout << order.c;
      }
    }
  }
  cout << endl;

  return 0;
}
