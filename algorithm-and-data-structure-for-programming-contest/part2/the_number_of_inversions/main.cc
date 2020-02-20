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

#define MAX 20000
#define SENTINEL 2000000000

int L[MAX / 2 + 2], R[MAX / 2 + 2];

ll merge(int A[], int n, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  REP(i, n1) L[i] = A[left + i];
  REP(i, n2) R[i] = A[mid + i];
  L[n1] = SENTINEL, R[n2] = SENTINEL;
  ll cnt = 0;
  int i = 0, j = 0;
  for (int k = left; k < right; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
      cnt += (mid - left) - i;
    }
  }

  return cnt;
}

ll mergeSort(int A[], int n, int left, int right) {
  int mid;
  ll v1, v2, v3;
  if (left + 1 < right) {
    mid = (left + right) / 2;
    v1 = mergeSort(A, n, left, mid);
    v2 = mergeSort(A, n, mid, right);
    v3 = merge(A, n, left, mid, right);
    return v1 + v2 + v3;
  } else {
    return 0;
  }
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int A[MAX], n, i;
  cin >> n;
  REP(i, n) cin >> A[i];

  ll ans = mergeSort(A, n, 0, n);
  cout << ans << endl;

  return 0;
}
