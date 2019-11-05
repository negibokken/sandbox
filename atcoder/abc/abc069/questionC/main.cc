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
const int inf = 1 << 30;
// clang-format on

int N;
int a[MAX_N];

int prime2(int n)
{
  int result = 0;
  while (n % 2 == 0) {
    n /= 2;
    result++;
  }
  return result;
}

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N;
  REP(i, N) cin >> a[i];

  map<int, int> mp;
  for (int i = 0; i < N; i++) {
    mp[prime2(a[i])]++;
  }

  int total = 0;
  for (auto m : mp) {
    if (m.first != 0 && m.first != 1) {
      total += m.second;
    }
  }

  int num0 = mp.count(0) > 0 ? mp[0] : 0;
  int num1 = mp.count(1) > 0 ? mp[1] : 0;

  if (total < (num0 - 1)) {
    cout << "No" << endl;
    return 0;
  }
  if (total - num0 < (num1 % 2) - 1) {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  return 0;
}
