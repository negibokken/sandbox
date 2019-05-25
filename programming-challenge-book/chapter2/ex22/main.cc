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

int N, L, P;
int A[MAX_N + 1], B[MAX_N + 1];

void solve()
{
  A[N] = L;
  B[N] = 0;
  N++;

  priority_queue<int> que;

  int ans = 0, pos = 0, tank = P;

  for (int i = 0; i < N; ++i) {
    int d = A[i] - pos;
    while (tank - d < 0) {
      if (que.empty()) {
        puts("-1");
        return;
      }
      tank += que.top();
      que.pop();
      ans++;
    }
    tank -= d;
    pos = A[i];
    que.push(B[i]);
  }
  printf("%d\n", ans);
}

int main(void)
{
  scanf("%d %d %d", &N, &L, &P);
  const char *fmt = "%d ";
  myscanf(fmt, N, A);
  myscanf(fmt, N, B);
  solve();
  return 0;
}
