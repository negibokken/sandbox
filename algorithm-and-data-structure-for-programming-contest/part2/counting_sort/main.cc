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
int C[MAX_N];

void countingSort(vector<int> A, vector<int> &B, int k) {
  REP(i, k + 1) C[i] = 0;
  REP(i, A.size()) C[A[i]]++;
  for (int i = 1; i <= k; i++) C[i] = C[i] + C[i - 1];
  for (int i = A.size() - 1; i >= 0; i--) {
    B[C[A[i]] - 1] = A[i];
    C[A[i]]--;
  }
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> A(n), B(n);
  REP(i, n) cin >> A[i];

  int ma = 0;
  REP(i, n) ma = max(ma, A[i]);
  countingSort(A, B, ma + 1);

  REP(i, n) cout << B[i] << SLN(i, A.size());

  return 0;
}
