#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<int> v(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int diff = v[i] - c[i];
    if (diff > 0) {
      sum += diff;
    }
  }
  cout << sum;
}
