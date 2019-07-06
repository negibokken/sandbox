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
char b;
int main(void)
{
  cin >> b;
  char res;
  if (b == 'A')
    res = 'T';
  else if (b == 'C')
    res = 'G';
  else if (b == 'G')
    res = 'C';
  else if (b == 'T')
    res = 'A';
  cout << res << endl;
  return 0;
}
