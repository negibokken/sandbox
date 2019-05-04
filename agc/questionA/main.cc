#include <algorithm>
#include <iostream>
#include <vector>
#define MAX_DIST 10000
using namespace std;

int visit(int i, int j, vector<vector<char>> arr, vector<vector<bool>> arrc,
          int dist)
{
  if (i <= -1 || i >= arr.size()) {
    return MAX_DIST;
  }
  if (j <= -1 || j >= arr[0].size()) {
    return MAX_DIST;
  }

  arrc[i][j] = true;

  if (arr[i][j] == '#') {
    return dist;
  }
  int hh = MAX_DIST;
  int jj = MAX_DIST;
  int kk = MAX_DIST;
  int ll = MAX_DIST;
  // left
  if (j - 1 >= 0 && !arrc[i][j - 1]) {
    hh = visit(i, j - 1, arr, arrc, dist + 1);
  }
  // Up
  if (i - 1 >= 0 && !arrc[i - 1][j]) {
    jj = visit(i - 1, j, arr, arrc, dist + 1);
  }
  // Right
  if (j + 1 < arr[0].size() && !arrc[i][j + 1]) {
    ll = visit(i, j + 1, arr, arrc, dist + 1);
  }
  // Down
  if (i + 1 < arr.size() && !arrc[i + 1][j]) {
    kk = visit(i + 1, j, arr, arrc, dist + 1);
  }
  return min({hh, jj, ll, kk});
}

int main(void)
{
  std::ios_base::sync_with_stdio(false);
  int w, h;
  cin >> w >> h;

  vector<vector<char>> arr(w, vector<char>(h, '.'));

  for (int i = 0; i < w; ++i) {
    for (int j = 0; j < h; ++j) {
      cin >> arr[i][j];
    }
  }

  int maxd = 0;
  for (int i = 0; i < w; ++i) {
    for (int j = 0; j < h; ++j) {
      vector<vector<bool>> arrc(w, vector<bool>(h, false));
      if (arr[i][j] == '.') {
        maxd = max(maxd, visit(i, j, arr, arrc, 0));
      }
    }
  }
  cout << maxd << endl;
  return 0;
}
