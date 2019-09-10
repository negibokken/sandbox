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
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
const ll MOD = 1e9+7;
const ll INF = 1LL << 60;
const int inf = 1 << 31;
// clang-format on

int n;
int a[MAX_N];

int mymax(int arr[], int n)
{
  int m = 0;
  for (int i = 0; i < n; i++) {
    m = max(m, arr[i]);
  }
  return m;
}

int main(void)
{
  cin >> n;
  REP(i, n) cin >> a[i];

  int amax = mymax(a, n);

  int half = amax / 2;

  int idx = 0;
  int m = INT_MAX;
  // search near by half
  for (int i = 0; i < n; i++) {
    if (a[i] == amax) continue;
    if (abs(a[i] - half) < m) {
      m = abs(a[i] - half);
      idx = i;
    }
  }

  printf("%d %d\n", amax, a[idx]);

  return 0;
}
