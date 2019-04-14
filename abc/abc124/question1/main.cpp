#include <iostream>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  int sum = 0;
  for (int i = 0; i < 2; i++) {
    if (a > b) {
      sum += a--;
    } else {
      sum += b--;
    }
  }
  cout << sum;
  return 0;
}
