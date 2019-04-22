#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void printArr(vector<int> a) {
  for (int i = 0; i < a.size(); i++) {
    cout << a[i];
    if (i != a.size() - 1) {
      cout << " ";
    }
  }
  cout << endl;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int cnt = 0;
  bool flag = true;
  while (flag) {
    flag = false;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] > a[i + 1]) {
        int tmp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = tmp;
        flag = true;
        ++cnt;
      }
    }
  }

  printArr(a);
  cout << cnt << endl;
  return 0;
}
