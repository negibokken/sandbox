#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

#define BUF_SIZE 256

int main() {
  char *str = (char *)malloc(BUF_SIZE);
  scanf("%s", str);
  if (str == NULL) {
    printf("No Input Error");
    exit(1);
  }

  vector<int> v;
  vector<char> vc;
  char prev = '\0';
  int cnt = 0;
  int i = 0;
  while (1) {
    if (prev == '\0') {
      prev = str[i];
      cnt = 1;
    } else if (str[i] == prev) {
      cnt++;
    } else {
      vc.push_back(prev);
      v.push_back(cnt);
      prev = str[i];
      cnt = 1;
    }
    if (str[i] == '\0') {
      break;
    }
    i++;
  }
  int dec = 0;
  for (vector<int>::iterator i = v.begin(); i != v.end(); i++) {
    dec += *i - 2;
  }

  // Not compressed return
  if (dec <= 0) {
    printf("%s", str);
    return 0;
  }

  for (int j = 0; j < (int)v.size(); j++) {
    printf("%c%d", vc[j], v[j]);
  }
  return 0;
}
