#include <iostream>
using namespace std;

int main(void)
{
  string s;
  cin >> s;
  int lose = 0;
  for (string::iterator i = s.begin(); i != s.end(); ++i) {
    if (*i == 'x') ++lose;
  }
  if (lose <= 7)
    cout << "YES";
  else
    cout << "NO";

  return 0;
}
