#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int n;
  cin >> n;

  long long minR = pow(10, 9);
  long long maxR = pow(-10, 9);
  long long cur;
  for (int i = 0; i < n; i++) {
    cin >> cur;
    maxR = max(maxR, cur - minR);
    minR = min(minR, cur);
  }

  cout << maxR << endl;

  return 0;
}
