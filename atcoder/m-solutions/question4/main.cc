#include <stdio.h>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

// Self settings
// clang-format off
#define MAX_N 20000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

int N;
int a[MAX_N], b[MAX_N], c[MAX_N];

typedef pair<int, int> P;
vector<int> G[MAX_N];
map<int, int> deg;
int res[MAX_N];
bool used[MAX_N];
vector<P> edge;

int main(void)
{
  priority_queue<P, vector<P>, less<P>> q;
  cin >> N;
  fill(used, used + N, false);

  for (int i = 0; i < N - 1; ++i) {
    int v1, v2;
    cin >> v1 >> v2;
    G[v1].push_back(v2);
    G[v2].push_back(v1);
    deg[v1]++;
    deg[v2]++;
    edge.push_back(P(v1, v2));
  }
  REP(i, N) cin >> c[i];

  sort(c, c + N, greater<int>());

  for (map<int, int>::iterator i = deg.begin(); i != deg.end(); ++i) {
    q.push(P(i->first, i->second));
  }

  int ci = 0;
  priority_queue<P> ve;
  while (!q.empty()) {
    P p = q.top();
    q.pop();
    int v1 = p.first;
    if (used[v1]) continue;
    used[v1] = true;
    res[v1] = c[ci++];
    // 次数順で入れる
    for (int i = 0; i < G[v1].size(); ++i) ve.push(P(G[v1][i], deg[G[v1][i]]));
    while (!ve.empty()) {
      P p2 = ve.top();
      ve.pop();
      int v2 = p2.first;
      if (used[v2]) continue;
      used[v2] = true;
      res[v2] = c[ci++];
      for (int i = 0; i < G[v2].size(); ++i)
        ve.push(P(G[v2][i], deg[G[v2][i]]));
    }
  }

  long long sum = 0;
  for (int i = 0; i < edge.size(); ++i) {
    P pp = edge[i];
    sum += min(res[pp.first], res[pp.second]);
  }
  cout << sum << endl;
  for (int i = 0; i < N; ++i) {
    cout << res[i + 1];
    if (i != N - 1) cout << " ";
  }
  cout << endl;

  return 0;
}
