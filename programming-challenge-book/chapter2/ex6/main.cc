#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 10000;
int N, S[MAX_N], T[MAX_N];
pair<int, int> itv[MAX_N];

void solve()
{
  for (int i = 0; i < N; ++i) {
    itv[i].first = T[i];
    itv[i].second = S[i];
  }
  sort(itv, itv + N);

  int ans = 0, t = 0;
  for (int i = 0; i < N; ++i) {
    if (t < itv[i].second) {
      ans++;
      t = itv[i].first;
    }
  }
  printf("%d\n", ans);
}

int main(void)
{
  int n;
  cin >> n;
  N = n;
  vector<int> s(n);
  vector<int> t(n);

  for (int i = 0; i < n; i++) cin >> S[i];
  for (int i = 0; i < n; i++) cin >> T[i];
  solve();

  return 0;
}
