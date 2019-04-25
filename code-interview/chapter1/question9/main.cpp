#include <iostream>
#include <vector>
using namespace std;

bool isSubstring(string s, string sub)
{
  int j = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == sub[j]) {
      ++j;
    }
  }
  return (s.size() / 2) == j;
}

int main(void)
{
  string a, b;
  cin >> a >> b;
  bool result = isSubstring(a + a, b);
  cout << result << endl;
  return 0;
}
