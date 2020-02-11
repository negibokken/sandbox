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
#define MAX_N 100005
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

int is_prime[MAX_N + 1];
int d[MAX_N + 5];

void init_shieve() {
  for (int i = 1; i <= MAX_N; i++) is_prime[i] = true;
  is_prime[0] = false, is_prime[1] = false;
  for (int i = 2; i <= MAX_N; i++) {
    if (is_prime[i]) {
      for (int j = i + i; j <= MAX_N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

bool like2017(int n) { return (is_prime[n] && is_prime[(n + 1) / 2]); }

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  init_shieve();

  // REP(i, MAX_N + 5) { cout << is_prime[i]; }

  d[0] = 0;
  REP(i, MAX_N + 5) {
    if (like2017(i)) {
      d[i + 1] = d[i] + 1;
    } else {
      d[i + 1] = d[i];
    }
  }

  int Q;
  cin >> Q;
  vector<int> l(Q), r(Q);
  REP(i, Q) { cin >> l[i] >> r[i]; }

  REP(i, Q) { cout << d[r[i] + 1] - d[l[i]] << endl; }

  return 0;
}
