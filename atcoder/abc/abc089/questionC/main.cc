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
const int inf = 1 << 31;
// clang-format on

int N;
string S;

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;

  map<char, int> mp;
  REP(i, N)
  {
    cin >> S;
    mp[S[0]]++;
  }

  ll ans = 0;
  const char charset[5] = {'M', 'A', 'R', 'C', 'H'};
  for (int i = 0; i < 5; i++) {
    int ni = mp[charset[i]];
    for (int j = i + 1; j < 5; j++) {
      int nj = mp[charset[j]];
      for (int k = j + 1; k < 5; k++) {
        int nk = mp[charset[k]];
        ans += (ll)ni * nj * nk;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
