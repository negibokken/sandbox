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
typedef pair<ll, int> Pl;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

// Self settings
// clang-format off
#define MAX_N 100000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

int N, M;
int A[MAX_N], B[MAX_N];

priority_queue<Pl, vector<Pl>, greater<Pl>> que;

void solve()
{
  ll price = 0;
  int n = 0;
  while (!que.empty() && n <= M) {
    Pl p = que.top();
    que.pop();
    int ad = min(M - n, p.second);
    price += p.first * ad;
    n += ad;
  }
  cout << price << endl;
}

int main(void)
{
  cin >> N >> M;
  REP(i, N)
  {
    ll a;
    int b;
    cin >> a >> b;
    que.push(Pl(a, b));
  }
  solve();
  return 0;
}
