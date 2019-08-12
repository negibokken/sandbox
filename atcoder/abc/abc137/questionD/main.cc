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
#define MAX_W 10000
#define INF 10000000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
// clang-format on

int N, M;
int A[MAX_N], B[MAX_N];

class comp {
  public:
  bool operator()(const P &i, const P &j)
  {
    if (i.first > j.first) {
      return true;
    }
    if (i.first == j.first) {
      if (i.second < j.second) {
        return true;
      }
    }
    return false;
  }
};

void solve()
{
  priority_queue<P, vector<P>, comp> que;
  REP(i, N) que.push(P(A[i], B[i]));
  int i = 0;
  ll ans = 0;
  while (!que.empty()) {
    P p = que.top();
    que.pop();
    cout << p.first << ":" << p.second << endl;
    if (M - i - p.first < 0) continue;
    ans += p.second;
    i++;
  }
  cout << ans << endl;
}

int main(void)
{
  cin >> N >> M;
  REP(i, N) cin >> A[i] >> B[i];

  solve();
  return 0;
}
