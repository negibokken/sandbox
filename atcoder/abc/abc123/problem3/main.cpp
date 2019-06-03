#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long time = 0;
  long long n;
  vector<long long> city;
  cin >> n;
  for (int i = 0; i < 5; i++) {
    long long cap;
    cin >> cap;
    city.push_back(cap);
  }
  vector<long long>::iterator m = min_element(city.begin(), city.end());
  time = ((n + *m - 1) / *m) + 4;
  // time = (n / *m) + 5;
  cout << time << endl;
  return 0;
}
