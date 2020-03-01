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

int A[3][3];
bool checked[3][3];
bool c() {
  REP(i, 3) {
    bool f = true;
    REP(j, 3) {
      if (!checked[i][j]) {
        f = false;
        break;
      }
    }
    if (f) return true;
  }
  REP(i, 3) {
    bool f = true;
    REP(j, 3) {
      if (!checked[j][i]) {
        f = false;
        break;
      }
    }
    if (f) return true;
  }
  bool f = true;
  REP(i, 3) f &= checked[i][i];
  if (f) return true;
  if (checked[0][2] && checked[1][1] && checked[2][0]) return true;
  return false;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  REP(i, 3) REP(j, 3) cin >> A[i][j];

  int N;
  cin >> N;
  vector<int> b(N);

  REP(i, 3) REP(j, 3) checked[i][j] = false;

  REP(i, N) {
    cin >> b[i];
    REP(j, 3) REP(k, 3) {
      if (A[j][k] == b[i]) checked[j][k] = true;
    }
  }

  cout << (c() ? "Yes" : "No") << endl;

  return 0;
}
