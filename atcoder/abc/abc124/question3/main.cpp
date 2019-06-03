#include <iostream>
using namespace std;

char toggle(char s) {
  if (s == '1') {
    return '0';
  } else {
    return '1';
  }
}

int main() {
  string s;
  cin >> s;

  int num = 0;
  char p = *s.begin();
  for (string::iterator i = s.begin() + 1; i != s.end(); i++) {
    p = toggle(p);
    if (*i != p) {
      num++;
    }
  }
  cout << num;
  return 0;
}
