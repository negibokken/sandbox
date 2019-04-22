#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void printArr(vector<int> arr) {
  for (int i = 0; i < (int)arr.size(); i++) {
    cout << arr[i];
    if (i != (int)arr.size() - 1) {
      cout << " ";
    }
  }
  cout << endl;
  return;
}

int main(void) {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i < n; i++) {
    int v = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > v) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = v;
    printArr(a);
  }

  printArr(a);

  return 0;
}
