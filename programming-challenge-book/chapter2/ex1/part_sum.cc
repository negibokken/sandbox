#include <iostream>
#include <vector>
using namespace std;

bool dfs(int i, int sum, int n, int k, vector<int> arr)
{
  if (i == n) return sum == k;
  if (dfs(i + 1, sum, n, k, arr)) return true;
  if (dfs(i + 1, sum + arr[i], n, k, arr)) return true;
  return false;
}

int main(void)
{
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) cin >> arr[n];
}
