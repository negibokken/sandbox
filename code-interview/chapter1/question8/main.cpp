#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
  // x, y
  int m, n;
  cin >> m >> n;

  bool column[n];
  bool row[m];
  // matrix[y][x]
  vector<vector<int>> matrix(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> matrix[i][j];
      if (matrix[i][j] == 0) {
        column[i] = true;
        row[j] = true;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!column[i] || !row[j]) {
        matrix[i][j] = 0;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
