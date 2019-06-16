#include <stdio.h>
#include <iostream>
#include <map>
#include <queue>
#include <set>
using namespace std;

// Self settings
// clang-format off
#define MAX_N 10000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

typedef long long ll;

int N;
ll x[MAX_N], y[MAX_N];
ll p, q;
typedef pair<ll, ll> P;

map<P, ll> a;
map<double, ll> b;
priority_queue<P> que;

void solve()
{
  set<P> st;
  for (int i = 0; i < N; i++) {
    st.insert(P(x[i], y[i]));
  }

  int ret = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) continue;
      P p = P(x[i] - x[j], y[i] - y[j]);
      int cnt = 0;
      for (int k = 0; k < N; k++) {
        P q = P(p.first + x[k], p.second + y[k]);
        if (st.count(q)) cnt++;
      }
      ret = max(ret, cnt);
    }
  }
  cout << N - ret << endl;
}

int main(void)
{
  cin >> N;
  REP(i, N) cin >> x[i] >> y[i];
  solve();
  return 0;
}
