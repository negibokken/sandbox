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
const int inf = 1 << 31;
// clang-format on

int N, H;
int a[MAX_N], b[MAX_N];

typedef tuple<int, int, int> T;
struct CustomCompare {
  bool operator()(const T &t1, const T &t2) { return get<2>(t2) > get<2>(t1); }
};

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> N >> H;
  REP(i, N) cin >> a[i] >> b[i];

  int idx = 0;
  int ma = 0;
  for (int i = 0; i < N; i++) {
    if (ma < a[i]) {
      ma = max(ma, a[i]);
      idx = i;
    }
  }

  priority_queue<T, vector<T>, CustomCompare> q;
  REP(i, N) if (i != idx) q.push({i, a[i], b[i]});

  int ans = 0;
  int h = H;
  while (!q.empty()) {
    T t = q.top();
    q.pop();
    int ii = get<0>(t), aa = get<1>(t), bb = get<2>(t);
    // 倒せるなら振るための刀でも使ってよい
    if (b[idx] >= h) {
      h -= b[idx];
      ans++;
      break;
    }
    // そうでなければ基本的には上から順番に投げる
    // が、ただし a[idx] の方がつよければそちらを使う
    if (bb < a[idx]) {
      h -= a[idx];
      ans++;
      break;
    }
    else {
      h -= bb;
      ans++;
    }
    if (h <= 0) {
      break;
    }
  }

  if (h > 0) {
    h -= b[idx];
    ans++;
    ans += ceil((double)h / a[idx]);
  }

  cout << ans << endl;

  return 0;
}
