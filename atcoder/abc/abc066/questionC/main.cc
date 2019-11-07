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
#define MAX_N 200000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
ll fact(ll n) { ll res = 1; for(ll i=2;i<=n;++i) res = res * i; return res;}
ll nCr(ll n, ll r) {return (fact(n)/fact(n-r)*fact(r)) ;}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
const ll MOD = 1e9+7;
const ll INF = 1LL << 60;
const int inf = 1 << 30;
// clang-format on

int n;
int a[MAX_N + 1];

vector<int> evenArr(int n)
{
  vector<int> result;
  for (int i = 2; i <= n; i += 2) {
    result.push_back(a[i]);
  }
  return result;
}

vector<int> oddArr(int n)
{
  vector<int> result;
  for (int i = 1; i <= n; i += 2) {
    result.push_back(a[i]);
  }
  return result;
}

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n;
  // 1-indexed
  REP(i, n) cin >> a[i + 1];

  vector<int> odd = oddArr(n);
  vector<int> even = evenArr(n);

  // Even
  if (n % 2 == 0) {
    if (even.size() > 1) reverse(even.begin(), even.end());
    REP(i, odd.size()) even.push_back(odd[i]);
    REP(i, even.size()) cout << even[i] << SLN(i, even.size());
  }
  else {
    if (odd.size() > 1) reverse(odd.begin(), odd.end());
    REP(i, even.size()) odd.push_back(even[i]);
    REP(i, odd.size()) cout << odd[i] << SLN(i, odd.size());
  }

  return 0;
}
