#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Self settings
// clang-format off
#define MAX_N 1000000
#define mo 1000000007
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

typedef long long ll;
int n, m;
vector<int> a;

int main(void)
{
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  a.push_back(n + 1);
  ll ans = 0;
  int cur = 0;
  int cnt = 0;
  for (int i = 0; i <= n + 1; ++i) {
    if (binary_search(a.begin(), a.end(), i)) {
      cnt = i - cur;
      cur = i + 1;
      cout << cnt - 0;
      ans = ans * (ll)pow(2.0, (double)(cnt - 1)) % (ll)mo;
      // cout << ans;
    }
  }
  cout << ans << endl;
  return 0;
}
