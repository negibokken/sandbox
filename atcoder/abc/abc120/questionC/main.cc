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
#include <stack>
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

char S[MAX_N + 1];

void solve()
{
  stack<char> stu;
  int i = 0;
  char prev;
  int cnt = 0;
  while (S[i] != '\0') {
    if (!stu.empty()) {
      // 一致してなければ追加せずに取り出ししてジャンプする
      if (S[i] != stu.top()) {
        cnt += 2;
        stu.pop();
        i++;
        continue;
      }
    }
    stu.push(S[i]);
    i++;
  }
  int ans = cnt;
  // 逆からのパターン
  i = strlen(S);
  stack<char> stb;
  while (S[i] != '\0') {
    if (!stu.empty()) {
      // 一致してなければ追加せずに取り出ししてジャンプする
      if (S[i] != stu.top()) {
        cnt += 2;
        stu.pop();
        i--;
        continue;
      }
    }
    stu.push(S[i]);
    i--;
  }
  ans = max(ans, cnt);
  cout << ans << endl;
}

int main(void)
{
  cin >> S;
  solve();
  return 0;
}
