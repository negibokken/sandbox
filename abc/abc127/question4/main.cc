#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

#define MAX_AC 100000

typedef long long ll;
ll N, M;
ll A[MAX_AC + 1], B[MAX_AC + 1], C[MAX_AC + 1];
typedef pair<ll, ll> Pair;

int main(void)
{
  cin >> N >> M;
  std::priority_queue<Pair> queue;
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
    Pair p = Pair(A[i], 1);
    queue.push(p);
  }

  for (ll i = 0; i < M; ++i) {
    cin >> B[i] >> C[i];
    Pair p = Pair(C[i], B[i]);
    queue.push(p);
  }

  long long ans = 0;
  for (ll i = 0; i < N; ++i) {
    Pair p = queue.top();
    queue.pop();
    if (p.second > 1) {
      p.second--;
      queue.push(p);
    }
    ans += p.first;
  }

  printf("%lld\n", ans);

  return 0;
}
