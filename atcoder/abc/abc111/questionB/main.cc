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

int main(void)
{
  int N;
  cin >> N;
  vector<int> a(3);
  for (int i = 0; i < 3; i++) {
    a[i] = N % 10;
    N /= 10;
  }

  // 0: 1 の位
  // 1: 10 の位
  // 2: 100 の位
  if (a[2] < a[1] || ((a[2] == a[1]) && a[1] < a[0])) a[2]++;
  a[1] = a[2];
  a[0] = a[2];
  for (int i = 2; i >= 0; i--) {
    cout << a[i];
  }
  cout << endl;
  return 0;
}
