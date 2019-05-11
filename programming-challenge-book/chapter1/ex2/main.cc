#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> a, int l)
{
  int minT = 0;
  for (int i = 0; i < a.size(); ++i) {
    minT = max(minT, min(a[i], l - a[i]));
  }

  int maxT = 0;
  for (int i = 0; i < a.size(); ++i) {
    maxT = max(maxT, max(a[i], l - a[i]));
  }
  printf("%d %d\n", minT, maxT);
}

int main(void)
{
  int l, n;
  cin >> l >> n;

  vector<int> x(n);
  for (int i = 0; i < n; ++i) cin >> x[i];
  solve(x, l);

  return 0;
}
