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

// void test() {
//   string exp180[8] = {"D", "LD", "L", "LU", "U", "RU", "R", "RD"};
//   REP(i, 8) { assert(myassert(turn180(dir8[i]), exp180[i])); }
//   string expLR[8] = {"U", "LU", "L", "LD", "D", "RD", "R", "RU"};
//   REP(i, 8) { assert(myassert(turnLR(dir8[i]), expLR[i])); }
//   string expTB[8] = {"D", "RD", "R", "RU", "U", "LU", "L", "LD"};
//   REP(i, 8) { assert(myassert(turnTB(dir8[i]), expTB[i])); }
//   bool expisWSk[8] = {0, 1, 0, 1, 0, 1, 0, 1};
//   REP(i, 8) { assert(myassert(isWSk(dir8[i]), expisWSk[i])); }
//   bool expisWSt[8] = {1, 0, 1, 0, 1, 0, 1, 0};
//   REP(i, 8) { assert(myassert(isWSt(dir8[i]), expisWSt[i])); }
//   bool expisLR[9] = {1, 0, 0, 0, 0, 0, 0, 0, 1};
//   REP(i, 9) { assert(myassert(isLR(i, i), expisLR[i])); }
//   bool expisTB[9] = {1, 0, 0, 0, 0, 0, 0, 0, 1};
//   REP(i, 9) { assert(myassert(isTB(i, i), expisTB[i])); }
//   bool expisOver[] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
//   FOR(i, -1, 10) { assert(myassert(isOver(i, i), expisOver[i + 1])); }
//   bool expisCorner[] = {1, 0, 0, 0, 0, 0, 0, 0, 1};
//   REP(i, 9) { assert(myassert(isCorner(i, i), expisCorner[i])); }
//   REP(i, 8) { assert(myassert(w2i(dir8[i]), i)); }
//
//   // const string dir8[8] = {"U", "RU", "R", "RD", "D", "LD", "L", "LU"};
//   vector<tuple<int, int, string, string>> testCases = {
//       {0, 0, "U", "D"}, {0, 0, "LU", "RD"}, {0, 0, "L", "R"},
//       {0, 1, "U", "U"}, {0, 1, "LU", "RU"}, {0, 1, "L", "R"},
//       {0, 1, "U", "U"}, {0, 1, "L", "R"},   {0, 1, "R", "R"},
//       {8, 0, "U", "D"}, {8, 0, "RU", "LD"}, {8, 0, "R", "L"},
//       {8, 1, "U", "U"}, {8, 1, "RU", "LU"}, {8, 1, "R", "L"},
//       {0, 8, "D", "U"}, {0, 8, "LD", "RU"}, {0, 8, "L", "R"},
//       {1, 8, "D", "U"}, {1, 8, "LD", "LU"}, {1, 8, "L", "L"},
//       {1, 8, "U", "U"}, {1, 8, "RD", "RU"}, {1, 8, "RU", "RU"},
//       {8, 8, "D", "U"}, {8, 8, "RD", "LU"}, {8, 8, "R", "L"},
//       {7, 8, "D", "U"}, {7, 8, "RD", "RU"}, {7, 8, "R", "R"},
//   };
//   for (auto t : testCases) {
//     int x = get<0>(t), y = get<1>(t);
//     string w = get<2>(t), exp = get<3>(t);
//     string act = next(x, y, w);
//     assert(myassert(act, exp));
//   }
// }

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

  int dx = 0, dy = 0;
  if (W.find("R") != string::npos) dx = 1;
  if (W.find("L") != string::npos) dx = -1;
  if (W.find("U") != string::npos) dy = -1;
  if (W.find("D") != string::npos) dy = 1;

  string ans;
  for (int i = 0; i < 4; i++) {
    cout << a[y][x];
    if (x == 0 && dx == -1) {
      dx = 1;
    }
    if (x == 8 && dx == 1) {
      dx = -1;
    }
    if (y == 0 && dy == -1) {
      dy = 1;
    }
    if (y == 8 && dy == 1) {
      dy = -1;
    }
    x += dx, y += dy;
  }
  cout << ans << endl;

  return 0;
}
