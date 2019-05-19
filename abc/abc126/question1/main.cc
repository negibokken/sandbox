#include <stdio.h>
#include "ctype.h"

int N, K;
char str[50 + 1];

int main(void)
{
  scanf("%d %d\n", &N, &K);
  scanf("%s", str);
  str[K - 1] = tolower(str[K - 1]);
  printf("%s\n", str);
  return 0;
}
