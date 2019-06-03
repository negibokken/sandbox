#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MAX_DIST 10000

int main(void)
{
  std::ios_base::sync_with_stdio(false);
  int w, h;
  cin >> h >> w;

  vector<vector<char>> arr(h, vector<char>(w, '.'));
  vector<vector<int>> arrd(h, vector<int>(w, MAX_DIST));

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> arr[i][j];
    }
  }

  int maxd = 0;
  for (int i = 0; i < h; ++i) {
    bool flag = false;
    int cnt = 0;
    for (int j = 0; j < w; ++j) {
      if (arr[i][j] == '#') {
        flag = true;
        cnt = 0;
        int cnt2 = 0;
        for (int k = j; k >= 0; --k) {
          if (cnt2 >= arrd[i][k]) {
            break;
          }
          arrd[i][k] = min(cnt2, arrd[i][k]);
          ++cnt2;
        }
      }
      if (flag) {
        arrd[i][j] = cnt;
        ++cnt;
      }
    }
  }
  for (int j = 0; j < w; ++j) {
    for (int i = 0; i < h; ++i) {
      if (arrd[i][j] != MAX_DIST) {
        continue;
      }
      int k;
      for (k = i - 1; k >= 0; --k) {
        if (arrd[k][j] != MAX_DIST) {
          break;
        }
      }
      if (k >= 0 && arrd[k][j] != MAX_DIST) {
        arrd[i][j] = min(arrd[k][j] + (i - k), arrd[i][j]);
      }
      for (k = i + 1; k < h; ++k) {
        if (arrd[k][j] != MAX_DIST) {
          break;
        }
      }
      if (k < h && arrd[k][j] != MAX_DIST) {
        arrd[i][j] = min(arrd[k][j] + (k - i), arrd[i][j]);
      }
    }
  }

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      maxd = max(maxd, arrd[i][j]);
    }
  }

  cout << maxd << endl;
  return 0;
}
