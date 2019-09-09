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

int N, M, X;
int A[MAX_N];

bool check(int n)
{
  for (int i = 0; i < M; i++) {
    if (A[i] == n) return true;
  }
  return false;
}

int main(void)
{
  cin >> N >> M >> X;
  REP(i, M) cin >> A[i];

  int ans = INT_MAX;
  int cost = 0;
  for (int i = X; i >= 0; i--)
    if (check(i)) cost++;
  ans = min(ans, cost);
  cost = 0;
  for (int i = X; i < N; i++)
    if (check(i)) cost++;
  ans = min(ans, cost);

  cout << ans << endl;

  return 0;
}
