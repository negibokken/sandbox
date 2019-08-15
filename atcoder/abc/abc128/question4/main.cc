#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;

// Self settings
// clang-format off
#define MAX_N 10000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

int N, K;
int V[MAX_N];

int main(void)
{
  deque<int> dqe;
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> V[i];
    dqe.push_back(V[i]);
  }

  ll ans = 0;

  for (int a = 0; a <= min(N, K); a++) {
    deque<int> dq = dqe;
    priority_queue<int, vector<int>, greater<int>> que;
    int aa = a;
    while (aa > 0 && !dq.empty()) {
      que.push(dq.front());
      dq.pop_front();
      aa--;
    }

    for (int b = 0; b <= min(N, K) - a; b++) {
      deque<int> dqq = dq;
      priority_queue<int, vector<int>, greater<int>> qu = que;
      int bb = b;
      while (bb > 0 && !dqq.empty()) {
        qu.push(dqq.back());
        dqq.pop_back();
        bb--;
      }

      for (int k = 0; k <= K - (a + b); k++) {
        int kk = k;
        priority_queue<int, vector<int>, greater<int>> q = qu;
        while (kk > 0) {
          if (!q.empty() && q.top() < 0) {
            q.pop();
          }
          kk--;
        }
        ll sum = 0;
        while (!q.empty()) {
          sum += q.top();
          q.pop();
        }
        ans = max(ans, sum);
      }
    }
  }
  cout << ans << endl;

  return 0;
}
