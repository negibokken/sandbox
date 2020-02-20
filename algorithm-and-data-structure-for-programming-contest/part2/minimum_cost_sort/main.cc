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
ll fact(ll n) { ll res = 1; for(ll i=2;i<=n;++i) res = res * i; return res;}
ll nCr(ll n, ll r) {return (fact(n)/fact(n-r)*fact(r)) ;}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
const ll MOD = 1e9+7;
const ll INF = 1LL << 60;
const int inf = 1000100011;
// clang-format on

#define MAX 1000
#define VMAX 10000

int n, A[MAX], s;
int B[MAX], T[VMAX + 1];

int solve() {
  int ans = 0;
  bool V[MAX];
  for (int i = 0; i < n; i++) {
    B[i] = A[i];
    V[i] = false;
  }
  sort(B, B + n);
  for (int i = 0; i < n; i++) T[B[i]] = i;
  for (int i = 0; i < n; i++) {
    if (V[i]) continue;
    int cur = i;
    int S = 0;
    int m = VMAX;
    int an = 0;
    while (1) {
      V[cur] = true;
      an++;
      int v = A[cur];
      m = min(m, v);
      S += v;
      cur = T[v];
      if (V[cur]) break;
    }
    ans += min(S + (an - 2) * m, m + S + (an + 1) * s);
  }
  return ans;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n;
  s = VMAX;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    s = min(s, A[i]);
  }
  int ans = solve();
  cout << ans << endl;

  return 0;
}
