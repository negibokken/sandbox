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
typedef pair<ll, ll> P;

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

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, K;
  cin >> N >> K;
  vector<int> t(N), d(N);
  REP(i, N) cin >> t[i] >> d[i];

  priority_queue<P> q;
  priority_queue<P, vector<P>, greater<P>> qans;
  REP(i, N) q.push(P(d[i], t[i]));

  ll x = 0;
  ll ans = 0, score = 0;
  map<ll, int> mp;
  for (int i = 0; i < K; i++) {
    P p = q.top();
    q.pop();
    if (mp.count(p.second) == 0) x++;
    mp[p.second]++;
    score += p.first;
    qans.push(p);
    ans = max(ans, (score + x * x));
  }

  while (!qans.empty() && !q.empty()) {
    P p = qans.top();
    qans.pop();
    // 一個しかなければ取り除かない
    if (mp[p.second] <= 1) continue;
    score -= p.first;
    mp[p.second]--;

    // 新しいものの中で、初めての種類のものを抽出する
    P pp = q.top();
    q.pop();
    while (!q.empty() && mp[pp.second] != 0) {
      pp = q.top();
      q.pop();
    }
    if (mp[pp.second] != 0) break;
    score += pp.first;
    mp[pp.second]++;
    x++;
    qans.push(pp);
    ans = max(ans, (score + x * x));
  }
  cout << ans << endl;

  return 0;
}
