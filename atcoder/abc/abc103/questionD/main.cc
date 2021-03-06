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

int N, M;
int a[MAX_N], b[MAX_N];

int main(void)
{
  cin >> N >> M;
  REP(i, M) cin >> a[i] >> b[i];
  priority_queue<P, vector<P>, greater<P>> q;
  REP(i, M) q.push(P(b[i], a[i]));

  int cnt = 0;
  // 中心
  int x = 0;
  while (!q.empty()) {
    P p = q.top();
    q.pop();
    int ai = p.second, bi = p.first;
    // a[i] <= x なら OK
    if (ai > x) {
      x = max(x, bi - 1);
      cnt++;
    }
  }

  cout << cnt << endl;

  return 0;
}
