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

int M, N;

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N >> M;
  vector<string> A(N), B(M);
  REP(i, N) cin >> A[i];
  REP(i, M) cin >> B[i];

  bool flag = true;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      flag = true;
      for (int k = 0; k < M; k++) {
        for (int l = 0; l < M; l++) {
          if (i + k >= N || j + l >= N) {
            flag = false;
            break;
          }
          if (A[i + k][j + l] != B[k][l]) {
            flag = false;
            break;
          }
        }
      }
      if (flag) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;

  return 0;
}
