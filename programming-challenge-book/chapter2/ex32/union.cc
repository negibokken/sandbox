#include <iostream>
using namespace std;

#define MAX_K 100000
#define MAX_N 100000

int N, K;
struct Info {
  int t, x, y;
};
Info info[MAX_K];
int par[MAX_N];
int rnk[MAX_N];

void init(int n)
{
  for (int i = 0; i < n; ++i) {
    par[i] = i;
    rnk[i] = 0;
  }
}

int find(int x)
{
  if (par[x] == x) {
    return x;
  }
  else {
    return par[x] = find(par[x]);
  }
}

bool same(int x, int y) { return find(x) == find(y); }

void unite(int x, int y)
{
  if (rnk[x] < rnk[y]) {
    par[x] = y;
  }
  else {
    par[y] = x;
    if (rnk[x] == rnk[y]) rnk[x]++;
  }
}

void solve()
{
  int ans = 0;
  init(N * 3);
  for (int i = 0; i < K; ++i) {
    Info inf = info[i];
    int t = inf.t;
    int x = inf.x - 1, y = inf.y - 1;

    if (x < 0 || N <= x || y < 0 || N <= y) {
      ans++;
      continue;
    }

    if (t == 1) {
      if (same(x, y + N) || same(x, y + 2 * N)) {
        ans++;
      }
      else {
        unite(x, y);
        unite(x, y + N);
        unite(x, y + 2 * N);
      }
    }
    else {
      if (same(x, y) || same(x, y + 2 * N)) {
        ans++;
      }
      else {
        unite(x, y + N);
        unite(x + N, y + 2 * N);
        unite(x + 2 * N, y);
      }
    }
  }
  cout << ans << endl;
}

int main()
{
  cin >> N >> K;
  for (int i = 0; i < K; ++i) {
    int t, x, y;
    cin >> t >> x >> y;
    info[i] = {t, x, y};
  }
  solve();
  for (int i = 0; i < 3 * N; ++i) {
    cout << par[i] << " ";
    if (i % 100 == 99) cout << endl;
  }
  return 0;
}
