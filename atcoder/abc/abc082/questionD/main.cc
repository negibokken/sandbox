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

int x, y;
string s;

const vector<int> dirs[] = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
// 0: 右
// 1: 下
// 2: 左
// 3: 上
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

void operate(int _x, int _y, int dir, int cur, set<P> &st)
{
  if (s[cur] == '\0') {
    st.insert(P(_x, _y));
    return;
  }
  if (s[cur] == 'F') {
    int nx = _x + dx[dir], ny = _y + dy[dir];
    operate(nx, ny, dir, cur + 1, st);
  }
  else if (s[cur] == 'T') {
    for (auto d : dirs[dir]) {
      operate(_x, _y, d, cur + 1, st);
    }
  }
}

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> s;
  cin >> x >> y;

  set<P> st;
  operate(0, 0, 0, 0, st);

  if (st.count(P(x, y)) > 0) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }

  return 0;
}
