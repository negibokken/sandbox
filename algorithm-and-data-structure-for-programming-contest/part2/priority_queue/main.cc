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
int H, A[MAX_N];

int parent(int i) { return i / 2; }
int left(int i) { return 2 * i; }
int right(int i) { return 2 * i + 1; }

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

void heapIncreaseKey(int i, int key) {
  if (key < A[i]) {
  }
  A[i] = key;
  while (i > 1 && A[parent(i)] < A[i]) {
    swap(A[i], A[parent(i)]);
    i = parent(i);
  }
}

void insert(int k) {
  H++;
  A[H] = -inf;
  heapIncreaseKey(H, k);
}

int extractMax() {
  if (H < 1) throw "error";
  int m = A[1];
  A[1] = A[H];
  H--;
  maxHeapify(1);
  return m;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string order;

  int num;
  while (cin >> order) {
    if (order == "insert") {
      scanf("%d", &num);
      insert(num);
    } else if (order == "extract") {
      int e = extractMax();
      cout << e << endl;
    } else if (order == "end") {
      break;
    } else {
      break;
    }
  }

  return 0;
}
