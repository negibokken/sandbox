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

int N;
int H[MAX_N];
int S[MAX_N];

int main(void)
{
  cin >> N;
  REP(i, N) cin >> H[i];

  S[N - 1] = 0;
  for (int i = N - 1; i > 0; i--) {
    if (H[i - 1] >= H[i]) {
      S[i - 1] = S[i] + 1;
    }
    else {
      S[i - 1] = 0;
    }
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    ans = max(ans, S[i]);
  }
  cout << ans << endl;
  return 0;
}
