#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 1000

void solve(vector<int> a)
{
  int ans = 0;
  int n = a.size();

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      for (int k = j + 1; k < n; ++k) {
        int len = a[i] + a[j] + a[k];
        int ma = max({a[i], a[j], a[k]});
        int rest = len - ma;

        if (ma < rest) {
          ans = max(ans, len);
        }
      }
    }
  }
  printf("%d\n", ans);
}

int main(void)
{
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  solve(a);

  return 0;
}
