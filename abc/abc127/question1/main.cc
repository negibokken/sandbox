#include <stdio.h>

int A, B;

int main(void)
{
  scanf("%d %d", &A, &B);
  if (A <= 5) {
    printf("0\n");
  }
  else if (A >= 6 && A <= 12) {
    printf("%d\n", B / 2);
  }
  else {
    printf("%d\n", B);
  }
  return 0;
}
