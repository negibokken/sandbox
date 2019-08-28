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
#define MAX_N 200000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
const ll MOD = 1e9+7;
const ll INF = 1LL << 60;
const int inf = 1 << 31;
// clang-format on

int N;
int A[MAX_N];
ll S[MAX_N + 1];

int main(void)
{
  cin >> N;
  REP(i, N) cin >> A[i];

  S[0] = 0;
  REP(i, N) S[i + 1] = S[i] + A[i];

  int l = 1, r = 3;
  ll ans = INT_MAX;
  for (int i = 2; i < N - 1; i++) {
    while (abs(S[i] - 2 * S[l]) > abs(S[i] - 2 * S[l + 1])) l++;
    while (abs(S[N] - S[i] - 2 * (S[r] - S[i])) >
           abs(S[N] - S[i] - 2 * (S[r + 1] - S[i])))
      r++;
    ll w = S[l], x = S[i] - S[l], y = S[r] - S[i], z = S[N] - S[r];
    ans = min(ans, max({w, x, y, z}) - min({w, x, y, z}));
  }

  cout << ans << endl;

  return 0;
}
