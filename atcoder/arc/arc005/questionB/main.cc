#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
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
typedef pair<int, char> Pc;
typedef pair<int, string> Ps;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

const int dx8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const string dir8[8] = {"U", "RU", "R", "RD", "D", "LD", "L", "LU"};

// clang-format off
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
// clang-format on

// clang-format off
int w2i(string W) {
  for (int i = 0; i < 8; i++) if (dir8[i] == W) return i;
  return 0;
}
bool isCorner(int x, int y) {
  return (x == 0 && y == 0) || (x == 0 && y == 8) || (x == 8 && y == 0) || (x == 8 && y == 8);
}
// const string dir8[8] = {"U", "RU", "R", "RD", "D", "LD", "L", "LU"};
bool isLR(int x, int y) { return (x == 0 || x == 8); }
bool isTB(int x, int y) { return (y == 0 || y == 8); }
bool isWSk(string s) { return w2i(s) % 2 == 1; }
bool isWSt(string s) { return w2i(s) % 2 == 0; }
string turn180(string W) { return dir8[(w2i(W) + 4) % 8]; }
string turnLR(string W)  { return dir8[(8 - (w2i(W))) % 8]; }
string turnTB(string W) { return dir8[(12 - (w2i(W))) % 8]; }
bool isOver(int x, int y) { return x < 0 || x > 8 || y < 0 || y > 8; }
// clang-format on
string next(int x, int y, string W) {
  int di = w2i(W);
  int nx = x + dx8[di], ny = y + dy8[di];
  if (isOver(nx, ny)) {
    if (isWSt(W)) {
      W = turn180(W);
    } else if (isWSk(W)) {
      if (isCorner(x, y)) {
        W = turn180(W);
      } else if (isLR(x, y)) {
        W = turnLR(W);
      } else if (isTB(x, y)) {
        W = turnTB(W);
      }
    }
  }
  return W;
}

template <typename T>
bool myassert(T act, T exp) {
  if (act != exp) cout << "Expected: " << exp << ", but got " << act << endl;
  return act == exp;
}

void test() {
  string exp180[8] = {"D", "LD", "L", "LU", "U", "RU", "R", "RD"};
  REP(i, 8) { assert(myassert(turn180(dir8[i]), exp180[i])); }
  string expLR[8] = {"U", "LU", "L", "LD", "D", "RD", "R", "RU"};
  REP(i, 8) { assert(myassert(turnLR(dir8[i]), expLR[i])); }
  string expTB[8] = {"D", "RD", "R", "RU", "U", "LU", "L", "LD"};
  REP(i, 8) { assert(myassert(turnTB(dir8[i]), expTB[i])); }
  bool expisWSk[8] = {0, 1, 0, 1, 0, 1, 0, 1};
  REP(i, 8) { assert(myassert(isWSk(dir8[i]), expisWSk[i])); }
  bool expisWSt[8] = {1, 0, 1, 0, 1, 0, 1, 0};
  REP(i, 8) { assert(myassert(isWSt(dir8[i]), expisWSt[i])); }
  bool expisLR[9] = {1, 0, 0, 0, 0, 0, 0, 0, 1};
  REP(i, 9) { assert(myassert(isLR(i, i), expisLR[i])); }
  bool expisTB[9] = {1, 0, 0, 0, 0, 0, 0, 0, 1};
  REP(i, 9) { assert(myassert(isTB(i, i), expisTB[i])); }
  bool expisOver[] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
  FOR(i, -1, 10) { assert(myassert(isOver(i, i), expisOver[i + 1])); }
  bool expisCorner[] = {1, 0, 0, 0, 0, 0, 0, 0, 1};
  REP(i, 9) { assert(myassert(isCorner(i, i), expisCorner[i])); }
  REP(i, 8) { assert(myassert(w2i(dir8[i]), i)); }

  // const string dir8[8] = {"U", "RU", "R", "RD", "D", "LD", "L", "LU"};
  for (auto w : dir8) {
    vector<vector<string>> expNext(9, vector<string>(9, w));
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (isWSt(w)) {
          expNext[i][j] = turn180(expNext[i][j]);
        } else {
          if (isCorner(i, j)) {
            expNext[i][j] = turn180(expNext[i][j]);
          } else if (isLR(i, j)) {
            expNext[i][j] = turnLR(expNext[i][j]);
          } else {
            expNext[i][j] = turnTB(expNext[i][j]);
          }
        }
        assert(myassert(next(i, j, w), expNext[i][j]));
      }
    }
  }
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  vector<string> a(9);
  int x, y;
  string W;
  cin >> x >> y >> W;
  x--, y--;
  REP(i, 9) cin >> a[i];

  test();
  return 0;

  string ans;
  for (int i = 0; i < 4; i++) {
    ans += a[y][x];
    int di = w2i(W);
    W = next(x, y, W);
    di = w2i(W);
    x = x + dx8[di], y = y + dy8[di];
  }
  cout << ans << endl;

  return 0;
}
