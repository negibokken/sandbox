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

int a[3];
int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  REP(i, 3) cin >> a[i];

  sort(a, a + 3);

  int ans = 0;
  // 他の 2 要素の差は偶数倍か？
  if ((a[1] - a[0]) % 2 == 0) {
    ans += (a[1] - a[0]) / 2;
    ans += (a[2] - a[1]);
  }
  // 他の 2 要素の差は奇数倍か？
  else {
    ans += (a[1] - a[0]) / 2;
    ans += (a[2] - a[1]) - 1;  // a[0] = a[2] - 2, a[1] = a[2] - 1  にする
    ans++;                     // 操作1 a[1] = a[2], a[2] = a[2] + 1
    ans++;                     // 操作2 a[0] = a[2]
    ans++;                     // 操作2 a[0] = a[2] + 1, a[1] = a[2] + 1
  }

  cout << ans << endl;

  return 0;
}
