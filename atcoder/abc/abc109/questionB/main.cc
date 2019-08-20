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
  vector<string> w(N);
  map<string, int> mp;
  for (int i = 0; i < N; i++) {
    cin >> w[i];
    // 過去に言った発言があったらしりとり失敗
    if (mp.count(w[i]) > 0) {
      cout << "No" << endl;
      return 0;
    }
    // 発言を記録する
    mp[w[i]]++;

    if (i == 0) continue;
    // 最初と最後が一致してなければしりとり失敗
    if (*(w[i - 1].end() - 1) != *(w[i].begin())) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
