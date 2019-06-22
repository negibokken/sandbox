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

// Self settings
// clang-format off
#define MAX_N 100000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

char s[5];

int main(void)
{
  scanf("%s", s);
  bool f = true;
  char prev = 'X';
  for (int i = 0; i < 5; i++) {
    if (prev == s[i]) {
      f = false;
    }
    prev = s[i];
  }
  printf("%s\n", (f ? "Good" : "Bad"));
  return 0;
}
