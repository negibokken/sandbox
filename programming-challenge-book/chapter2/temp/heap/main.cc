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

int heap[MAX_N], sz = 0;

void push(int x) {
  int i = sz++;
  while (i > 0) {
    int p = (i - 1) / 2;
    if (heap[p] <= x) break;

    heap[i] = heap[p];
    i = p;
  }
  heap[i] = x;
}

int pop() {
  int ret = heap[0];
  int x = heap[--sz];

  int i = 0;
  while (i * 2 + 1 < sz) {
    int a = i * 2 + 1, b = i * 2 + 2;
    if (b < sz && heap[b] < heap[a]) a = b;
    if (heap[a] >= x) break;

    heap[i] = heap[a];
    i = a;
  }
  heap[i] = x;
  return ret;
}

int N;
int a[MAX_N];
int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N;
  REP(i, N) cin >> a[i];

  REP(i, N) push(a[i]);
  REP(i, N) cout << pop();

  return 0;
}
