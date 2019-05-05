#include <iostream>
#include <vector>
using namespace std;

void visit(int i, vector<vector<int>> mat, vector<bool> &visited)
{
  if (visited[i]) {
    return;
  }
  visited[i] = true;
  for (int k = 0; k < mat.size(); ++k) {
    if (mat[i][k] == 1 && !visited[k]) {
      visit(k, mat, visited);
    }
  }
}

int main(void)
{
  int n, s, e;
  cin >> n >> s >> e;

  vector<vector<int>> mat(n, vector<int>(n, 0));
  vector<bool> visited(n, false);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> mat[i][j];
    }
  }

  visit(s, mat, visited);
  cout << (visited[e] ? "true" : "false") << endl;
  return 0;
}
