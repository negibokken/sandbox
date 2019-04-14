#include <stdio.h>
#include <string.h>

int main() {
  char buffer[256];

  if (fgets(buffer, 256, stdin) == NULL) {
    return 1;
  }
  printf("%s", buffer);
  int n = strlen(buffer);
  return 0;
}
