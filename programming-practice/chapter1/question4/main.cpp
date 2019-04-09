#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  string str1;
  map<char, int> m;
  int odd = 0, even = 0;
  getline(cin, str1);
  for (string::iterator i = str1.begin(); i != str1.end(); i++) {
    if (*i == ' ') {
      continue;
    }
    m[*i]++;
  }
  for (auto i = m.begin(); i != m.end(); i++) {
    if (i->second % 2 == 0) {
      even++;
    } else {
      odd++;
    }
  }
  if (odd <= 1) {
    cout << "True\n";
  } else {
    cout << "False\n";
  }
  return 0;
}
