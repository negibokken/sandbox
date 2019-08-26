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

#define MAX_D 10
#define MAX_C 1000000
int D, G;
int p[10], c[10];
int dp[10 + 1][100 + 1][100 * 10 + 1];

int main(void)
{
  cin >> D >> G;
  REP(i, D) cin >> p[i] >> c[i];

  int idx = 0;
  for (int i = 1; i < 100 * 1000; i++) {
    if (dp[D][p[D - 1]][i] >= G) {
      idx = i;
      break;
    }
  }
  cout << idx << endl;

  return 0;
}
