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
#define MAX_N 300000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
const ll MOD = 1e9+7;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
// clang-format on

int N;
char S[MAX_N + 1];

int main(void)
{
  cin >> N >> S;

  vector<int> wa(N + 1), ea(N + 1);

  wa[0] = 0;
  // wa
  for (int i = 0; i < N; i++) {
    if (S[i] == 'W') {
      wa[i + 1] = wa[i] + 1;
    }
    else {
      wa[i + 1] = wa[i];
    }
  }

  ea[N - 1] = 0;
  // ea
  for (int i = N - 1; i > 0; i--) {
    if (S[i] == 'E') {
      ea[i - 1] = ea[i] + 1;
    }
    else {
      ea[i - 1] = ea[i];
    }
  }

  // cout << endl;
  // for (int i = 0; i < N; i++) cout << wa[i] << SLN(i, N);
  // for (int i = 0; i < N; i++) cout << ea[i] << SLN(i, N);

  ll ans = inf;
  for (int i = 0; i < N; i++) {
    ans = min(ans, (ll)wa[i] + ea[i]);
  }

  cout << ans << endl;

  return 0;
}
