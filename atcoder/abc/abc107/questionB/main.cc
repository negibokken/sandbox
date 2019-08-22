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
#define MAX_H 100
#define MAX_W 100
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
const ll MOD = 1e9+7;
const ll INF = 1LL << 60;
const int inf = 1 << 31;
// clang-format on

int H, W;
char a[MAX_H][MAX_W];

int main(void)
{
  cin >> H >> W;
  REP(i, H) REP(j, W) cin >> a[i][j];

  map<int, int> h, w;
  for (int i = 0; i < H; i++) {
    bool f = true;
    for (int j = 0; j < W; j++) {
      if (a[i][j] != '.') {
        f = false;
        break;
      }
    }
    if (f) h[i]++;
  }

  for (int i = 0; i < W; i++) {
    bool f = true;
    for (int j = 0; j < H; j++) {
      if (a[j][i] != '.') {
        f = false;
        break;
      }
    }
    if (f) w[i]++;
  }

  if (w.size() == W || h.size() == H) {
    cout << "#" << endl;
    return 0;
  }

  for (int i = 0; i < H; i++) {
    if (h.count(i) > 0) continue;
    for (int j = 0; j < W; j++) {
      if (w.count(j) > 0) continue;
      cout << a[i][j];
    }
    cout << endl;
  }

  return 0;
}
