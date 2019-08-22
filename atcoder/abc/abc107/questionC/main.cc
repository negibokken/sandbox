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
const int inf = INT_MAX;
// clang-format on

int N, K;
int x[MAX_N + 1];
int w[MAX_N + 2];

int main(void)
{
  cin >> N >> K;
  REP(i, N) { cin >> x[i]; }
  int ans = INT_MAX;
  for (int l = 0; l < N - K + 1; l++) {
    int r = l + K - 1;
    ans = min(ans, abs(x[l]) + abs(x[r] - x[l]));
    ans = min(ans, abs(x[r]) + abs(x[r] - x[l]));
  }
  cout << ans << endl;
}
