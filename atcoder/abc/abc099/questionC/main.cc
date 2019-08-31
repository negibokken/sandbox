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

int main(void)
{
  int N;
  cin >> N;

  int res = N;
  for (int i = 0; i <= N; i++) {
    int cc = 0;
    int t = i;
    cout << t << endl;
    while (t > 0) cc += t % 6, t /= 6;
    t = N - i;
    cout << t << endl;
    while (t > 0) cc += t % 9, t /= 9;
    cout << t << endl;
    if (res > cc) res = cc;
  }

  cout << res << endl;

  return 0;
}
