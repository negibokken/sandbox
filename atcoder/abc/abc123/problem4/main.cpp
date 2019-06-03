#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(vector<long long> v) {
  for (vector<long long>::iterator i = v.begin(); i != v.end(); i++) {
    cout << *i;
  }
  cout << endl;
}

int main() {
  int x, y, z, k;
  cin >> x >> y >> z >> k;

  vector<long long> a(x), b(y), c(z);
  for (int i = 0; i < x; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < y; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < z; i++) {
    cin >> c[i];
  }

  // sort all cakes
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  print(a);
  print(b);
  print(c);
  for ()
}

