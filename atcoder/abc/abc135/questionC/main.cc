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
// clang-format on

int N;
ll A[MAX_N + 1];
ll B[MAX_N];
ll C[MAX_N + 1];

void solve()
{
  ll ans = 0;
  ll c = 0;
  for (int i = 0; i < N; i++) {
    // 対象のものから余力を引く
    // 余力は引き継ぎできないので、先に消費する
    ll d = min(A[i], c);
    // 倒せたモンスターの数
    ans += min(A[i], B[i] + c);
    // 余力は勇者の力から、使ってしまったパワーを引く
    c = max(B[i] - (A[i] - d), (ll)0);
    // cout << ans << endl;
    // cout << c << endl;
  }
  ans += min(A[N], c);
  cout << ans << endl;
}

int main(void)
{
  cin >> N;
  REP(i, N + 1) cin >> A[i];
  REP(i, N) cin >> B[i];
  solve();
  return 0;
}
