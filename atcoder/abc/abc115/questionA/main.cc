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
  int D;
  cin >> D;
  if (D == 22) {
    cout << "Christmas Eve Eve Eve" << endl;
  }
  else if (D == 23) {
    cout << "Christmas Eve Eve" << endl;
  }
  else if (D == 24) {
    cout << "Christmas Eve" << endl;
  }
  else if (D == 25) {
    cout << "Christmas" << endl;
  }
  return 0;
}
