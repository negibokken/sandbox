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

int M, K;

int main(void)
{
  cin >> M >> K;
  if (K >= (int)pow(2, M)) {
    cout << -1 << endl;
    return 0;
  }

  if (M == 0) {
    cout << "0 0" << endl;
  }
  else if (M == 1 && K == 1) {
    cout << -1 << endl;
  }
  else if (M == 1 && K == 0) {
    cout << 0 << " " << 0 << " " << 1 << " " << 1 << endl;
  }
  else if (M >= 2) {
    vector<int> b;
    for (int i = 0; i < (1 << (M)); i++) {
      if (i == K) continue;
      b.push_back(i);
    }
    vector<int> c = b;
    reverse(c.begin(), c.end());
    int si = b.size();
    for (int i = 0; i < si; i++) {
      cout << b[i] << " ";
    }
    cout << K << " ";
    for (int i = 0; i < si; i++) {
      cout << c[i] << " ";
    }
    cout << K << endl;
    cout << endl;
  }

  return 0;
}
