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

int W, H;
char canvas[50][50];

bool check(int i, int j)
{
  bool f = false;
  for (int k = 0; k < 4; k++) {
    int x = i + dx[k], y = j + dy[k];
    if (x < 0 || x >= W) continue;
    if (y < 0 || y >= H) continue;
    if (canvas[x][y] == '#') {
      f = true;
      break;
    }
  }
  return f;
}

int main(void)
{
  cin >> W >> H;
  REP(i, W) REP(j, H) cin >> canvas[i][j];

  for (int i = 0; i < W; i++) {
    for (int j = 0; j < H; j++) {
      if (canvas[i][j] == '#') {
        if (!check(i, j)) {
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
