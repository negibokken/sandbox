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

int parent(int i) { return i / 2; }
int left(int i) { return 2 * i; }
int right(int i) { return 2 * i + 1; }
int H;

int A[MAX_N];

void maxHeapify(int i) {
  int l = left(i);
  int r = right(i);
  int largest;
  if (l <= H && A[l] > A[i]) {
    largest = l;
  } else {
    largest = i;
  }
  if (r <= H && A[r] > A[largest]) {
    largest = r;
  }
  if (largest != i) {
    swap(A[i], A[largest]);
    maxHeapify(largest);
  }
}

void buildMaxHeap() {
  for (int i = H / 2; i >= 1; i--) {
    maxHeapify(i);
  }
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> H;
  for (int i = 1; i <= H; i++) cin >> A[i];
  buildMaxHeap();
  for (int i = 1; i <= H; i++) {
    if (i) cout << " ";
    cout << A[i];
  }
  cout << endl;

  return 0;
}
