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
// clang-format on

int N, M;
vector<int> G[MAX_N];
bool visited[MAX_N];

int main(void)
{
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    // 0-indexed
    x--, y--;
    // create undirected graph
    G[x].push_back(y);
    G[y].push_back(x);
  }

  int cnum = 0;
  for (int u = 0; u < N; u++) {
    queue<int> q;
    if (!visited[u]) {
      q.push(u);
      cnum++;
    }
    // bfs
    while (!q.empty()) {
      int uu = q.front();
      q.pop();
      visited[uu] = true;
      for (int v : G[uu]) {
        if (!visited[v]) q.push(v);
      }
    }
  }

  cout << cnum << endl;

  return 0;
}
