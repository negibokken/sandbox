#include <iostream>
#include <map>
#include <vector>
using namespace std;

int gcda(vector<int> a, map<int, int> diffs)
{
  int maxn = 1;
  for (int i = 0; i < a.size(); i++) {
    vector<int> b = a;
    b.erase(b.begin() + i);
    for (auto v = diffs.begin(); v != diffs.end(); v++) {
      bool flag = true;
      for (auto bi = b.begin(); bi != b.end(); bi++) {
        if (*bi % v->first != 0) {
          flag = false;
          break;
        }
      }
      if (flag) {
        maxn = max(v->first, maxn);
      }
    }
  }

  return maxn;
}

int main(void)
{
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;

  int ans;
  vector<int> a(n);
  map<int, int> diffs;
  int maxa = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (maxa < a[i]) {
      maxa = a[i];
    }
    for (int j = i - 1; j >= 0; --j) {
      diffs[abs(a[j] - a[i])]++;
    }
  }
  if (n == 2) {
    cout << maxa << endl;
    return 0;
  }
  int maxn = gcda(a, diffs);
  cout << maxn << endl;

  return 0;
}
