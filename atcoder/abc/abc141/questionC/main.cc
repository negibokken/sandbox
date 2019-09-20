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

int N, K, Q;
int A[MAX_N];
int ANS[MAX_N + 1];

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N >> K >> Q;
  REP(i, Q) cin >> A[i];

  ll sum = 0;
  REP(i, Q) ANS[A[i]]++;

  for (int i = 1; i <= N; i++) {
    if (K - (Q - ANS[i]) <= 0) {
      cout << "No" << endl;
    }
    else {
      cout << "Yes" << endl;
    }
  }

  return 0;
}
