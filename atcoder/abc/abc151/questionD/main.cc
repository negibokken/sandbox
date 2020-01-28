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
const int inf = 1 << 30;
// clang-format on

int h, w;

int ans;
int maze[50][50];
bool visited[50][50];
char S[50][50];

// first が y, second が x
int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> h >> w;
  vector<string> s(h);
  REP(i, h) cin >> s[i];
  int ans = 0;
  REP(si, h) REP(sj, w) {
    if (s[si][sj] == '#') continue;
    vector<vector<int>> dist(h, vector<int>(w, inf));
    queue<P> q;
    auto update = [&](int i, int j, int x) {
      if (dist[i][j] != inf) return;
      dist[i][j] = x;
      q.push(P(i, j));
    };
    update(si, sj, 0);
    while (!q.empty()) {
      int i = q.front().first;
      int j = q.front().second;
      q.pop();
      REP(dir, 4) {
        int ni = i + dy[dir], nj = j + dx[dir];
        if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
        if (s[ni][nj] == '#') continue;
        update(ni, nj, dist[i][j] + 1);
      }
      REP(i, h) REP(j, w) {
        if (dist[i][j] == inf) continue;
        ans = max(ans, dist[i][j]);
      }
    }
  }

  cout << ans << endl;

  return 0;
}
