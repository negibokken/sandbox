#include <algorithm>
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

  for (int i = 0; i < n; i++) {
    int minj = i;
    for (int j = i; j < n; j++) {
      if (a[minj] > a[j]) {
        minj = j;
      }
    }
    int tmp = a[i];
    a[i] = a[minj];
    a[minj] = tmp;
  }

  printArr(a);

  return 0;
}
