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

int A, B;
string S;

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> A >> B;
  cin >> S;

  if (A + B + 1 != S.length()) {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 0; i < A; i++) {
    if (!('0' <= S[i] && S[i] <= '9')) {
      cout << "No" << endl;
      return 0;
    }
  }
  if (S[A] != '-') {
    cout << "No" << endl;
    return 0;
  }
  for (int i = A + 1; i < A + 1 + B; i++) {
    if (!('0' <= S[i] && S[i] <= '9')) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;

  return 0;
}
