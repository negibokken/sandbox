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

void merge(int l, int mid, int r, vector<int> &A) {
  vector<int> B = A;
  int idx = 0, i = 0, j = mid;
  while (1) {
    if (B[i] < B[j]) {
      A[idx++] = B[i];
      i++;
    } else {
      A[idx++] = B[j];
      j++;
    }

    if (i == mid) {
      while (j < r) A[idx++] = B[j++];
      break;
    } else if (j == r) {
      while (i < mid) A[idx++] = B[i++];
      break;
    }
  }
}

void mergeSort(int l, int r, vector<int> &A) {
  if (r - l > 1) {
    int mid = (l + r) / 2;
    mergeSort(l, mid, A);
    mergeSort(mid, r, A);
    merge(l, mid, r, A);
  }
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> A(n);
  REP(i, n) cin >> A[i];

  mergeSort(0, n, A);

  REP(i, n) cout << A[i] << SLN(i, n);

  return 0;
}
