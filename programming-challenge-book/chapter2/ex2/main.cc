#include <iostream>
#include <vector>
using namespace std;

void dfs(int x, int y, vector<vector<char>> &field)
{
  int n = field.size();
  int m = field[0].size();

  field[x][y] = '.';

  for (int dx = -1; dx <= 1; dx++) {
    for (int dy = -1; dy <= 1; dy++) {
      int nx = x + dx, ny = y + dy;
      if (0 <= nx && nx < n && 0 <= ny && ny < m && field[nx][ny] == 'W')
        dfs(nx, ny, field);
    }
  }
}

void solve(vector<vector<char>> &field)
{
  int res = 0;
  int n = field.size();
  int m = field[0].size();

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (field[i][j] == 'W') {
        dfs(i, j, field);
        res++;
      }
    }
  }
  printf("%d\n", res);
}

int main(void)
{
  int n, m;
  cin >> n >> m;

  vector<vector<char>> field(n, vector<char>(m, '.'));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> field[i][j];
    }
  }

  solve(field);

  return 0;
}
