#include <iostream>
#include <vector>
using namespace std;

int MAX_NUM = 100000;

int main(void)
{
  int n;
  cin >> n;

  int tmp;
  vector<int> a(MAX_NUM, 0);
  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    ++a[tmp];
  }
  for (int i = 0; i < (int)a.size(); ++i) {
    while (a[i] > 0) {
      cout << i << " ";
      --a[i];
    }
  }
  return 0;
}
