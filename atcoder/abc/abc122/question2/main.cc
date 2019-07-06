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
// clang-format on

char S[11];

bool C(char c) { return c == 'A' || c == 'C' || c == 'G' || c == 'T'; }

int main(void)
{
  cin >> S;
  int ans = 0;
  int cnt = 0;
  for (int i = 0; S[i] != '\0'; i++) {
    if (C(S[i]))
      cnt++;
    else
      cnt = 0;
    ans = max(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}
