#include <map>
#include <stdio.h>
using namespace std;

#define MAX_SIZE 256

int main() {
  map<char, int> m;
  char *args[] = {
      (char *)malloc(MAX_SIZE),
      (char *)malloc(MAX_SIZE),
  };
  for (int i = 0; i < 2; i++) {
    scanf("%s", args[i]);
    if (args[i] == NULL) {
      printf("Standard IO Error\n");
      exit(1);
    }
  }
  for (int i = 0; args[0][i] != '\0'; i++) {
    m[args[0][i]]++;
  }
  for (int i = 0; args[1][i] != '\0'; i++) {
    m[args[1][i]]--;
  }

  int onecnt = 0, monecnt = 0;
  for (map<char, int>::iterator i = m.begin(); i != m.end(); i++) {
    // can not create if the diff is more than 1
    if (i->second < -1 || i->second > 1) {
      return 0;
    }
    if (i->second == -1) {
      monecnt++;
    }
    if (i->second == 1) {
      onecnt++;
    }
    if (monecnt >= 2 || onecnt >= 2) {
      return 0;
    }
  }
  return 1;
}
