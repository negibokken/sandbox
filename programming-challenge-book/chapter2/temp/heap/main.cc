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
const int inf = 1000000;
// clang-format on

int N;
int a[MAX_N];

void heapify(int A[], int idx, int max) {
  int largest = idx;
  int left = 2 * idx + 1;
  int right = 2 * idx + 2;

  if (left < max && A[left] > A[idx]) {
    largest = left;
  }
  if (right < max && A[right] > A[largest]) {
    largest = right;
  }
  if (largest != idx) {
    swap(A[idx], A[largest]);
    heapify(A, largest, max);
  }
}

void buildHeap(int A[]) {
  for (int i = N / 2 - 1; i >= 0; i--) {
    heapify(A, i, N);
  }
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N;
  REP(i, N) cin >> a[i];

  buildHeap(a);
  for (int i = N - 1; i >= 1; i--) {
    swap(a[0], a[i]);
    heapify(a, 0, i);
  }

  REP(i, N) cout << a[i];
  cout << endl;

  return 0;
}
