#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

// Self settings
// clang-format off
#define MAX_N 10000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
void myscanf(const char *fmt, int num, int *s, int *v) { REP(i,num) scanf(fmt, &s[i], &v[i]); }
void myscanf(const char *fmt, int num, int *s) { REP(i,num) scanf(fmt, &s[i]); }
// clang-format on

int N, K;
int V[MAX_N];

int main(void)
{
  deque<int> dq;
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    cin >> V[i];
    dq.push_back(V[i]);
  }
  for (int i = 0; i < N; ++i) {
    cout << V[i];
  }
  return 0;
}
