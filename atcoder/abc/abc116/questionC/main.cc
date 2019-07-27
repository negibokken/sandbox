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
int h[MAX_N + 1];

int main(void)
{
  cin >> N;
  REP(i, N) cin >> h[i];
  int cnt = 0;
  int s = 0, t = 0;
  while (s < N) {
    t = s;
    while (t < N && h[t] != 0) h[t]--, t++;
    if (t != s) cnt++;
    while (s < N && h[s] == 0) s++;
  }
  cout << cnt << endl;
  cout << cnt << endl;
  return 0;
}
