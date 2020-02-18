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
const ll SENTINEL = 1e9 + 7;

typedef struct {
  char suit;
  int value;
} Card;

Card L[MAX_N / 2 + 2], R[MAX_N / 2 + 2];

void merge(Card A[], int n, int left, int mid, int right) {
  int i, j, k;
  int n1 = mid - left;
  int n2 = right - mid;
  for (i = 0; i < n1; i++) L[i] = A[left + i];
  for (i = 0; i < n2; i++) R[i] = A[mid + i];
  L[n1].value = R[n2].value = SENTINEL;
  i = j = 0;
  for (k = left; k < right; k++) {
    if (L[i].value <= R[j].value) {
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
  }
}

void mergeSort(Card A[], int n, int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergeSort(A, n, left, mid);
    mergeSort(A, n, mid, right);
    merge(A, n, left, mid, right);
  }
}

int partition(Card A[], int n, int p, int r) {
  int i, j;
  Card t, x;
  x = A[r];
  i = p - 1;
  for (int j = p; j < r; j++) {
    if (A[j].value <= x.value) {
      i++;
      swap(A[i], A[j]);
    }
  }
  swap(A[i + 1], A[r]);
  return i + 1;
}

void quickSort(Card A[], int n, int p, int r) {
  int q;
  if (p < r) {
    q = partition(A, n, p, r);
    quickSort(A, n, p, q - 1);
    quickSort(A, n, q + 1, r);
  }
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, i, v;
  Card A[MAX_N], B[MAX_N];
  char S[10];
  int stable = 1;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%s %d", S, &v);
    A[i].suit = B[i].suit = S[0];
    A[i].value = B[i].value = v;
  }

  mergeSort(A, n, 0, n);
  quickSort(B, n, 0, n - 1);

  for (i = 0; i < n; i++) {
    if (A[i].suit != B[i].suit) stable = 0;
  }

  if (stable == 1)
    printf("Stable\n");
  else
    printf("Not stable\n");

  REP(i, n) printf("%c %d\n", B[i].suit, B[i].value);
  // REP(i, n) printf("%c %d\n", A[i].suit, A[i].value);

  return 0;
}
