#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

// Self settings
// clang-format off
#define MAX_N 100000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
// clang-format on

int N;

void prime_factor(int n, map<int, int> &mp)
{
  for (int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      mp[i]++;
      n /= i;
    }
  }
  if (n != 1) mp[n]++;
}

int num(map<int, int> mp, int num)
{
  int cnt = 0;
  for (auto m : mp) {
    if (m.second >= num - 1) {
      cnt++;
    }
  }
  return cnt;
}

int main(void)
{
  cin >> N;

  map<int, int> mp;
  for (int i = 1; i <= N; i++) {
    prime_factor(i, mp);
  }

  ll ans = (num(mp, 75) + num(mp, 25) * (num(mp, 3) - 1) +
            num(mp, 15) * (num(mp, 5) - 1) +
            num(mp, 5) * (num(mp, 5) - 1) * (num(mp, 3) - 2) / 2);

  cout << ans << endl;
  return 0;
}

