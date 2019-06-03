#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

  int N;
  cin >> N;
  string S;
  cin >> S;

  vector<int> black(N + 1);
  vector<int> white(N + 1);

  black[0] = 0;
  white[0] = 0;

  for (int i = 1; i < N + 1; i++) {
    if (S[i - 1] == '.') {
      black[i] = black[i - 1] + 1;
      white[i] = white[i - 1];
    } else {
      black[i] = black[i - 1];
      white[i] = white[i - 1] + 1;
    }
  }
  /*
      for(int i = 0; i < N + 1; i++){
          cout << black[i] << " " << white[i] << endl;
      }
  */

  int min = N;
  int count;

  if (white[N] == N) {
    min = 0;
  } else {
    for (int i = 0; i < N + 1; i++) {
      count = white[i] + (black[N] - black[i]);
      if (min > count) {
        min = count;
      }
    }
  }
  cout << min << endl;

  return 0;
}
