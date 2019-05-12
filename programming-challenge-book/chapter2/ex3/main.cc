#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// clang-format off
typedef long long ll;
int fact(int n) { int res = 1; for(int i=2;i<=n;++i) res = res * i; return res;}
int nCr(int n, int r) {return (fact(n)/fact(n-r)*fact(r)) ;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
// clang-format on

const int INF = 1000000000;

typedef pair<int, int> P;

int bfs(vector<vector<char>> &maze, vector<vector<int>> &d, int sx, int sy,
        int gx, int gy)
{
  int n = maze.size();
  int m = maze[0].size();
  queue<P> que;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) d[i][j] = INF;

  que.push(P(sx, sy));
  d[sx][sy] = 0;
  while (que.size()) {
    P p = que.front();
    que.pop();
    if (p.first == gx && p.second == gy) {
      break;
    }

    for (int i = 0; i < 4; i++) {
      int nx = p.first + dx[i], ny = p.second + dy[i];
      if (0 <= nx && nx < n && 0 <= ny && ny < m && maze[nx][ny] != '#' &&
          d[nx][ny] == INF) {
        que.push(P(nx, ny));
        d[nx][ny] = d[p.first][p.second] + 1;
      }
    }
  }
  return d[gx][gy];
}

int main(void)
{
  int n, m;
  cin >> n >> m;

  int sx, sy;
  int gx, gy;
  vector<vector<char>> maze(n, vector<char>(m, 0));
  vector<vector<int>> d(n, vector<int>(m, 0));

  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < m; ++i) {
      cin >> maze[i][j];
      if (maze[i][j] == 'S') sy = j, sx = i;
      if (maze[i][j] == 'G') gy = j, gx = i;
    }
  }

  int res = bfs(maze, d, sx, sy, gx, gy);

  printf("%d\n", res);

  return 0;
}
