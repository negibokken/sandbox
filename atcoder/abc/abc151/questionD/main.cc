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

int H, W;

int ans;
int maze[50][50];
bool visited[50][50];
char S[50][50];

void print() {
  cout << endl;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (maze[i][j] == inf)
        cout << "*";
      else
        cout << maze[i][j];
    }
    cout << endl;
  }
}

void init() {
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 50; j++) {
      maze[i][j] = inf;
      visited[i][j] = false;
    }
  }
}

void search(int xx, int yy, int dist) {
  queue<P> q;
  q.push(P(yy, xx));

  while (!q.empty()) {
    P p = q.front();
    q.pop();
    int x = p.second, y = p.first;
    visited[y][x] = true;
    REP(i, 4) {
      int ny = y + dy[i], nx = x + dx[i];
      if (ny < 0 || ny >= H) continue;
      if (nx < 0 || nx >= W) continue;
      if (S[ny][nx] == '#') continue;
      if (visited[ny][nx]) continue;
      q.push(P(ny, nx));
      maze[ny][nx] = min(maze[ny][nx], maze[y][x] + 1);
      // 更新があったとき visited を false にする
      // if (maze[ny][nx] > maze[y][x] + 1) {
      //   maze[ny][nx] = maze[y][x] + 1;
      //   visited[ny][nx] = false;
      // } else {
      //   maze[ny][nx] = maze[ny][nx];
      // }
    }
  }
}

void solve(P start) {
  init();
  maze[start.first][start.second] = 0;
  search(start.second, start.first, 0);
}

// first が y, second が x
int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> H >> W;

  REP(i, H) REP(j, W) { cin >> S[i][j]; }

  int ans = 0;
  REP(si, H) REP(sj, W) {
    if (S[si][sj] == '#') continue;
    vector<vector<int>> dist(H, vector<int>(W, inf));
    queue<P> q;
    auto update = [&](int i, int j, int x) {
      if (dist[i][j] != inf) return;
      maze[i][j] = x;
      q.push(P(i, j));
    };
    update(si, sj, 0);
    while (!q.empty()) {
      int i = q.front().first;
      int j = q.front().second;
      q.pop();
      REP(dir, 4) {
        int ni = i + dy[dir], nj = j + dx[dir];
        if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
        if (S[ni][nj] == '#') continue;
        update(ni, nj, dist[i][j] + 1);
      }
    }
    REP(i, H) REP(j, W) {
      if (dist[i][j] == inf) continue;
      ans = max(ans, dist[i][j]);
    }
  }

  cout << ans << endl;

  return 0;
}
