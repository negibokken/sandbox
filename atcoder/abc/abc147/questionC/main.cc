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
#define MAX_N 20
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

int N;
int A[MAX_N];
int x[MAX_N][MAX_N], y[MAX_N][MAX_N];

int par[MAX_N];
int rnk[MAX_N];
const int LIEAR = -1;

void init(int n) { REP(i, n) par[i] = i, rnk[i] = 0; }

int find(int x) {
  if (par[x] == LIEAR) return LIEAR;
  if (par[x] == x) {
    return x;
  } else {
    return par[x] = find(par[x]);
  }
}

// おかしいとき false
bool unite(int x, int y) {
  x = find(x), y = find(y);
  // x は正直者のはずなのに、LIEAR なのはおかしい
  if (x == LIEAR) return false;
  // x は正直者のはずなのに、LIEAR と統合するのはおかしい
  if (y == LIEAR) return false;
  if (x == y) return true;

  if (rnk[x] < rnk[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if (rnk[x] == rnk[y]) rnk[x]++;
  }
  return true;
}

bool same(int x, int y) { return find(x) == find(y); }

int count(int n) {
  int cnt = 0;
  map<int, int> mp;
  REP(i, n) if (par[i] != LIEAR) mp[par[i]]++;
  for (auto m : mp) {
    cnt = max(cnt, m.second);
  }
  return cnt;
}

bool setAttr(int n, int val) {
  // n でもなく、 val でもないときはすでに設定をしているのに違う値
  if (par[n] != n && par[n] != val) {
    return false;
  }
  par[n] = val;
  return true;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  REP(i, N) {
    cin >> A[i];
    REP(j, A[i]) {
      int xx;
      cin >> xx >> y[i][j];
      x[i][j] = xx - 1;
    }
  }

  int ans = 0;
  for (int i = 0; i < (1 << N); i++) {
    // 0000000000 1 の人が正直者であり、それ以外の人は不親切
    // cout << i << endl;
    bool isAntinomy = false;
    int n = i, cnt = 0, truman = 0;
    init(N);
    while (n > 0) {
      if (n & 1) {
        truman++;
        REP(j, A[cnt]) {
          // 正直ものの仮定と違ってたら break する
          if (y[cnt][j] != ((i >> (x[cnt][j])) & 1)) {
            isAntinomy = true;
            break;
          }
          // 正直者なら同じグループにする
          if (y[cnt][j]) isAntinomy = !unite(cnt, x[cnt][j]);
          // 不明なら不明と印をつける
          else
            isAntinomy = !setAttr(x[cnt][j], LIEAR);
          if (isAntinomy) break;
        }
      }
      if (isAntinomy) {
        truman = 0;
        break;
      }
      cnt++;
      n >>= 1;
    }
    // int sum = count(N);
    // cout << "矛盾: " << isAntinomy << "正: " << truman << endl;
    // REP(k, N) cout << par[k] << " ";
    // cout << endl;
    // cout << "(" << sum << ")" << endl;
    if (!isAntinomy) ans = max(ans, truman);
  }
  cout << ans << endl;

  return 0;
}
