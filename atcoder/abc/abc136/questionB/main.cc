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

int main(void)
{
  cin >> N;

  int cnt = 0;
  for (int i = 1; i <= N; i++) {
    int d = 0;
    int n = i;
    while (n > 0) n /= 10, d++;
    if (d % 2 == 1) cnt++;
  }
  cout << cnt << endl;
  return 0;
}
