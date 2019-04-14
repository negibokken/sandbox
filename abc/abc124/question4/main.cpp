#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  vector<int> Nums;
  int now = 1;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == (char)('0' + now))
      cnt++;
    else {
      Nums.push_back(cnt);
      now = 1 - now;
      cnt = 1;
    }
  }
  if (cnt != 0) {
    Nums.push_back(cnt);
  }

  if (Nums.size() % 2 == 0) {
    Nums.push_back(0);
  }

  int Add = 2 * k + 1;
  int right = 0, left = 0;
  int ans = 0;
  int sum = 0;
  for (int i = 0; i < Nums.size(); i += 2) {
    int nextLeft = i;
    int nextRight = min(i + Add, (int)Nums.size());
    while (nextLeft > left) {
      sum -= Nums[left];
      left++;
    }
    while (nextRight > right) {
      sum += Nums[right];
      right++;
    }
    ans = max(sum, ans);
  }
  cout << ans;
  return 0;
}
