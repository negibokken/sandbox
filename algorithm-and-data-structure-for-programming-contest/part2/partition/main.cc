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

int partition(vector<int> &A, int p, int r) {
  int x = A[r];
  int i = 0;
  for (int j = 1; j < r; j++) {
    if (A[j] < x) {
      swap(A[i], A[j]);
      i++;
    }
  }
  swap(A[i], A[r]);
  return i;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> A(n);
  REP(i, n) cin >> A[i];
  int q = partition(A, 0, n - 1);

  for (int i = 0; i < n; i++) {
    if (i == q) cout << "[";
    cout << A[i];
    if (i == q)
      cout << "] ";
    else
      cout << " ";
  }

  return 0;
}
