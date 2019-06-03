#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool BinarySearch(vector<int> arr, int x)
{
  int l = 0;
  int r = arr.size() - 1;
  while (r - l >= 1) {
    int mid = (l + r) / 2;
    if (arr[mid] == x) {
      return true;
    }
    else if (arr[mid] < x) {
      l = mid + 1;
    }
    else {
      r = mid;
    }
  }
  return false;
}

int main(void)
{
  int r, g, b, n;
  scanf("%d %d %d %d", &r, &g, &b, &n);
  vector<int> arr;
  vector<vector<int>> a(n, vector<int>(n, 0));

  int cnt = 0;
  int i, j, k;

  for (k = 0; b * k <= n; ++k) {
    arr.push_back(b * k);
  }

  for (i = 0; r * i <= n; ++i) {
    for (j = 0; g * j <= (n - r * i); ++j) {
      // a[i][j] = r * i + g * j;
      if (BinarySearch(arr, n - (r * i + g * j))) ++cnt;
    }
  }
  printf("%d\n", cnt);

  return 0;
}
