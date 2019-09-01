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

int N, C, X;
int D[30][39];
int t[3][30];

int main(void)
{
  cin >> N >> C;
  REP(i, C) REP(j, C) cin >> D[i][j];
  REP(i, N) REP(j, N)
  {
    cin >> X;
    t[(i + j) % 3][X - 1]++;
  }

  int res = 1 << 30;
  for (int i = 0; i < C; i++) {
    for (int j = 0; j < C; j++) {
      if (i == j) continue;
      for (int k = 0; k < C; k++) {
        if (i != k && j != k) {
          int tt = 0;
          REP(l, C) tt += D[l][i] * t[0][l];
          REP(l, C) tt += D[l][j] * t[1][l];
          REP(l, C) tt += D[l][k] * t[2][l];
          if (tt < res) res = tt;
        }
      }
    }
  }
  cout << res << endl;
  return 0;
}
