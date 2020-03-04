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

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int H, i, A[MAX_N + 1];
  cin >> H;
  for (i = 1; i <= H; i++) cin >> A[i];

  for (int i = 0; i <= H; i++) {
    cout << "node " << i << ": key = " << A[i] << ", ";
    if (parent(i) >= 1) cout << "parent key = " << A[parent(i)] << ", ";
    if (left(i) <= H) cout << "left key = " << A[left(i)] << ", ";
    if (right(i) <= H) cout << "right key = " << A[right(i)] << ", ";
    cout << endl;
  }

  return 0;
}
