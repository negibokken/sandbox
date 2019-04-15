#include<iostream>
using namespace std;

int main() {
  char str[50] = "Mr John Smith hello";
  int size = 19;
  int cnt = 0;
  // Count space number
  for (int i = 0; i <= size - 1; i++) {
    if (str[i] == ' ') {
      ++cnt;
    }
  }
  int j = size - 1 + (cnt * 2);
  str[j + 1] = '\0';
  // URLified string length = space_num * 2 + length
  for (int i = size - 1; i >= 0; --i) {
    if (str[i] == ' ') {
      str[j] = '0';
      --j;
      str[j] = '2';
      --j;
      str[j] = '%';
      --i;
      --j;
    }
    str[j] = str[i];
    --j;
  }
  cout << str << endl;
  return 0;
}
