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
// clang-format on

int N, M;
int A[MAX_N], B[MAX_N];

class UnionFind {
  public:
  vector<int> Parent;
  UnionFind(int N) { Parent = vector<int>(N, -1); }
  int root(int A)
  {
    if (Parent[A] < 0) return A;
    return Parent[A] = root(Parent[A]);
  }
  int size(int A) { return -Parent[root(A)]; }
  bool connect(int A, int B)
  {
    A = root(A);
    B = root(B);
    if (A == B) return false;
    if (size(A) < size(B)) swap(A, B);
    Parent[A] += Parent[B];
    Parent[B] = A;
    return true;
  }
};

void solve()
{
  UnionFind Uni(N);
  ll ans[MAX_N + 1];
  ans[M - 1] = (ll)N * (N - 1) / 2;
  for (int i = M - 1; i > 0; i--) {
    int u = A[i], v = B[i];
    ans[i - 1] = ans[i];
    if (Uni.root(u) != Uni.root(v)) {
      ans[i - 1] -= (ll)Uni.size(u) * Uni.size(v);
      Uni.connect(u, v);
    }
  }
  REP(i, M) cout << ans[i] << (i == M - 1 ? "\n" : " ");
  // REP(i, M) cout << ans[i + 1] << endl;
}

int main(void)
{
  cin >> N >> M;
  REP(i, M)
  {
    int u, v;
    cin >> u >> v;
    // 0-indexed
    u--, v--;
    A[i] = u, B[i] = v;
  }
  solve();
  return 0;
}
