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

int main(void)
{
  // char year[5], month[3], date[3];
  int yeari, monthi, datei;
  scanf("%d/%d/%d", &yeari, &monthi, &datei);
  // 2019年以降で平成になるのは 4 / 30 まで
  if (yeari == 2019 && monthi <= 4) {
    cout << "Heisei" << endl;
    return 0;
  }
  cout << "TBD" << endl;
  return 0;
}
