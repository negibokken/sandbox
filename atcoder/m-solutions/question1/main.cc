#include <stdio.h>

int n;

int main(void)
{
  scanf("%d", &n);
  long long ans = (n - 2) * 180;
  printf("%lld", ans);
  return 0;
}
