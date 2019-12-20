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
const int inf = 1 << 30;
// clang-format on

int N, M;
int a[MAX_N], b[MAX_N], c[MAX_N], d[MAX_N];

int manhatand(int x1, int y1, int x2, int y2) {
  return (abs(x1 - x2) + abs(y1 - y2));
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N >> M;

  REP(i, N) cin >> a[i] >> b[i];
  REP(i, M) cin >> c[i] >> d[i];

  vector<int> ans(N);

  for (int i = 0; i < N; i++) {
    int mini = 0, minv = inf;
    for (int j = 0; j < M; j++) {
      int dist = manhatand(a[i], b[i], c[j], d[j]);
      if (dist < minv) {
        minv = dist;
        mini = j + 1;
      }
    }
    ans[i] = mini;
  }

  REP(i, N) cout << ans[i] << endl;

  return 0;
}
