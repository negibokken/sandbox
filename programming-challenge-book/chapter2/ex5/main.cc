#include <stdio.h>
#include <iostream>
using namespace std;

const int V[6] = {1, 5, 10, 50, 100, 500};
int C[6];
int A;

void solve()
{
  int ans = 0;
  for (int i = 5; i >= 0; --i) {
    int t = min(A / V[i], C[i]);
    A -= t * V[i];
    ans += t;
  }
  printf("%d\n", ans);
}

int main(void)
{
  scanf("%d %d %d %d %d %d", &C[0], &C[1], &C[2], &C[3], &C[4], &C[5]);
  scanf("%d", &A);

  solve();

  return 0;
}
