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

string S, T;

vector<int> findStart(string S, char t)
{
  vector<int> result;
  for (int i = 0; i < S.size(); i++) {
    if (S[i] == '?' || S[i] == t) result.push_back(i);
  }
  return result;
}

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> S >> T;

  int idx = inf;
  vector<int> starts = findStart(S, T[0]);
  for (auto start : starts) {
    int cnt = 0;
    for (int i = start; i < min(start + T.size(), S.size()); i++) {
      if (S[i] != T[cnt] && S[i] != '?') break;
      cnt++;
    }
    if (cnt == T.size()) idx = start;
  }

  // idx なければ復元不可
  if (idx == inf) {
    cout << "UNRESTORABLE" << endl;
    return 0;
  }

  int ti = 0;
  for (int i = 0; i < T.size(); i++) {
    S[idx + i] = T[ti++];
  }

  for (int i = 0; i < S.size(); i++) {
    if (S[i] == '?') S[i] = 'a';
  }

  cout << S << endl;

  return 0;
}
