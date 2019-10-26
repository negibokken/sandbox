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

const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

// Self settings
// clang-format off
#define MAX_N 100000
#define MAX_W 50
#define MAX_H 50
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

int H, W;
char S[MAX_H][MAX_W];
char ans[MAX_H][MAX_W];

char bombSearch(int h, int w)
{
  int res = 0;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      int nh = h + i, nw = w + j;
      if (nh < 0 || nh >= H) continue;
      if (nw < 0 || nw >= W) continue;
      if (S[nh][nw] == '#') res++;
    }
  }
  return res + '0';
}

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> H >> W;
  REP(i, H) REP(j, W) cin >> S[i][j];

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (S[i][j] == '.') {
        ans[i][j] = bombSearch(i, j);
      }
      else {
        ans[i][j] = '#';
      }
    }
  }

  REP(i, H)
  {
    REP(j, W) { cout << ans[i][j]; }
    cout << endl;
  }

  return 0;
}
