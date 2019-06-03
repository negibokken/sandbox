#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int h;
  int cnt = 0;
  int max = 0;
  for (int i = 0; i < n; i++) {
    cin >> h;
    if (max <= h) {
      max = h;
      cnt++;
    }
  }
  cout << cnt;
  return 0;
}
