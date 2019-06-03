#include <stdio.h>
#include <iostream>
using namespace std;

int r, D, x[11];

int main(void)
{
  scanf("%d %d %d", &r, &D, &x[0]);
  for (int i = 1; i <= 10; ++i) {
    x[i] = r * x[i - 1] - D;
    printf("%d\n", x[i]);
  }
  return 0;
}
