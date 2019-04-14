#include <cmath>
#include <iostream>
#include <string>
using namespace std;

string b2a(bool result) {
  if(result) {
    return "Yay!";
  } else {
    return ":(";
  }
}

bool check(int points[], int size, int k) {
  for (int i = 0; i < 5; i++) {
    for (int j = i + 1; j < 5; j++) {
      if (abs(points[i] - points[j]) > k) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  int points[5];
  int k;
  for (int i = 0; i < 5; i++) {
    cin >> points[i];
  }
  cin >> k;
  bool result = check(points, 5, k);
  cout << b2a(result);
  return 0;
}
