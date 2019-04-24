#include <iostream>
#include <vector>
using namespace std;

// matrix[y][x]
bool rotate(vector<vector<int>> &matrix)
{
  if (matrix.size() == 0 || matrix.size() != matrix[0].size()) {
    return false;
  }
  int n = matrix.size();
  for (int layer = 0; layer < n / 2; layer++) {
    int first = layer;
    int last = n - layer - 1;
    for (int i = first; i < last; i++) {
      // Top を tmp へ退避
      int tmp = matrix[first][i];
      // Left を Top へ
      matrix[first][i] = matrix[last - i + first][first];
      // Bottom を Left へ
      matrix[last - i + first][first] = matrix[last][last - i + first];
      // Right を Bottom へ
      matrix[last][last - i + first] = matrix[i][last];
      // tmp を Right へ
      matrix[i][last] = tmp;
    }
  }
  return true;
}

int main(void)
{
  int n;
  cin >> n;

  vector<vector<int>> matrix(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> matrix[i][j];
    }
  }

  rotate(matrix);

  cout << endl << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}

