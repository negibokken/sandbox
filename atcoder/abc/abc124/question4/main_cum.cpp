#include <iostream>
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
    if (s[i] == (char)('0' + now)) {
      cnt++;
    } else {
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

  vector<int> cum(Nums.size() + 1);
  for (int i = 0; i < (int)Nums.size(); i++) {
    cum[i + 1] = cum[i] + Nums[i];
  }

  // 1 0 1 0 1  0  1
  // 0 1 3 5 8 10 14
  int Add = 2 * k + 1;
  int ans = 0;
  for (int i = 0; i < (int)Nums.size(); i += 2) {
    int left = i;
    int right = min(i + Add, (int)Nums.size());
    int tmp = cum[right] - cum[left];
    ans = max(tmp, ans);
  }
  cout << ans;
  return 0;
}
