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
#define MAX_N 200000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

int N;
int A[MAX_N];
priority_queue<P> que;
priority_queue<P> que2;

void solve()
{
  REP(i, N) que.push(P(A[i], i));
  for (int i = 0; i < N; i++) {
    int t = A[i];
    while (1) {
      P p = que.top();
      que.pop();
      que2.push(p);
      if (p.second == i) continue;
      cout << p.first << endl;
      break;
    }
    while (!que2.empty()) {
      P p = que2.top();
      que2.pop();
      que.push(p);
    }
  }
}

int main(void)
{
  cin >> N;
  REP(i, N) cin >> A[i];
  solve();
  return 0;
}
