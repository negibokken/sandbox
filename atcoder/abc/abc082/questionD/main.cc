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

int dpx[8000 + 1][(8000 + 1) * 2];
int dpy[8000 + 1][(8000 + 1) * 2];

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> s;
  cin >> x >> y;

  const int base = 8000;
  bool isHorz = true;
  int ns = s.size();
  dpx[0][0 + base] = true;
  for (int i = 0; i < ns; i++) {
    if (s[i] == 'T') isHorz = !isHorz;
    int dic = (s[i] == 'F' ? 1 : 0);
    for (int j = 0; j < ns; j++) {
      dpx[i + 1][j + dic + base] = dpx[i][j + base];
      dpx[i + 1][j - dic + base] = dpx[i][j + base];
    }
  }

  bool isVert = false;
  dpy[0][0 + base] = true;
  for (int i = 0; i < ns; i++) {
    if (s[i] == 'T') isVert = !isVert;
    int dic = (s[i] == 'F' ? 1 : 0);
    for (int j = 0; j < ns; j++) {
      printf("%d %d\n", j + dic + base, j - dic + base);
      dpy[i + 1][j + dic + base] = dpy[i][j + base];
      dpy[i + 1][j - dic + base] = dpy[i][j + base];
    }
  }

  cout << endl;
  for (int i = 0; i <= ns; i++) {
    for (int j = -5; j <= 5; j++) {
      cout << dpx[i][j + base] << SLN(j, 6);
    }
  }
  if (dpx[ns][x + base] && dpy[ns][y + base]) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }

  return 0;
}
