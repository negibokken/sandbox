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
#define MAX_N 500
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

int N;
int C[MAX_N], S[MAX_N], F[MAX_N];
int dp[MAX_N * 100000 + 5];

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N;
  REP(i, N) cin >> C[i] >> S[i] >> F[i];
  deque<int> ans;
  ans.push_back(0);

  // C, S, F
  // S後に C掛けて到達、F ごとに出発

  for (int i = 0; i < N; i++) {
    int t = 0;
    for (int j = i; j < N - 1; j++) {
      if (t < S[j])
        t = S[j];
      else if (t % F[j] == 0)
        ;
      else
        t = t + F[j] - t % F[j];
      t += C[j];
    }
    printf("%d\n", t);
  }

  return 0;
}
