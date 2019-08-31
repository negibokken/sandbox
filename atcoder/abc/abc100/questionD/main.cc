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
#define MAX_N 1000
#define MAX_M 1000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
const ll MOD = 1e9+7;
const ll INF = 1LL << 60;
const int inf = 1 << 31;
// clang-format on

// i 番目までで M 個を達成するときの
// 0 : 最大値, 1: 最小値
int N, M;
ll x[MAX_N], y[MAX_N], z[MAX_N];

int main(void)
{
  cin >> N >> M;
  REP(i, N) { cin >> x[i] >> y[i] >> z[i]; }

  ll ans = 0;
  // 1 なら -1 とする
  for (int i = 0; i < (1 << 3); i++) {
    priority_queue<ll> q;
    for (int j = 0; j < N; j++) {
      ll sum = 0;
      sum += (int)pow(-1, (i & 1)) * x[j];
      sum += (int)pow(-1, ((i & 2) >> 1)) * y[j];
      sum += (int)pow(-1, ((i & 4) >> 2)) * z[j];
      q.push(sum);
    }
    ll sum = 0;
    for (int j = 0; j < M; j++) {
      ll p = q.top();
      q.pop();
      sum += p;
    }
    ans = max(ans, sum);
  }

  cout << ans << endl;

  return 0;
}
