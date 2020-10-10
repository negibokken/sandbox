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
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "bokken.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, char> Pc;
typedef pair<int, string> Ps;

const int dx8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const string dir8[8] = {"U", "RU", "R", "RD", "D", "LD", "L", "LU"};

// Self settings
// clang-format off
#define MAX_N 100000
#define MAX 100000
#define INFTY (1<<30)
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
#define arrin(arr,N) REP(i,(N)) { cin >> arr[i]; }
ll fact(ll n) { ll res = 1; for(ll i=2;i<=n;++i) res = res * i; return res;}
ll nCr(ll n, ll r) {return (fact(n)/fact(n-r)*fact(r)) ;}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
const ll MOD = 1e9+7;
const ll INF = 1LL << 60;
const int inf = 1000100011;
class Point { public: double x, y; Point(double x = 0, double y = 0) : x(x), y(y) {} Point operator+(Point p) { return Point(x + p.x, y + p.y); } Point operator-(Point p) { return Point(x - p.x, y - p.y); } Point operator*(double a) { return Point(a * x, a * y); } Point operator/(double a) { return Point(x / a, y / a); } double abs() { return sqrt(norm()); } double norm() { return x * x + y * y; } bool operator<(const Point& p) const { return x != p.x ? x < p.x : y < p.y; } bool operator==(const Point& p) const { return fabs(x - p.y) < EPS && fabs(y - p.y) < EPS; } };
typedef Point Vector;
double norm(Vector a) { return a.x * a.x + a.y * a.y; }
double abs(Vector a) { return sqrt(norm(a));}
double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }
struct Segment { Point p1, p2; };
typedef Segment Line;
struct Node { int data; Node *left, *right; Node(int data) : data(data), left(NULL), right(NULL) {} };
// clang-format on

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
bool rec(vector<vector<char>>& board, vector<vector<bool>> visited, string word,
         int idx, int x, int y) {
  if (idx == word.size() - 1) return true;
  // cout << word[idx] << ", " << board[y][x] << endl;
  if (word[idx] != board[y][x]) return false;
  visited[y][x] = true;
  bool f = false;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i], nx = x + dx[i];
    if (nx < 0 || nx >= board[0].size()) continue;
    if (ny < 0 || ny >= board.size()) continue;
    if (visited[ny][nx]) continue;
    if (idx + 1 < word.size() && word[idx + 1] != board[ny][nx]) continue;
    f |= rec(board, visited, word, idx + 1, nx, ny);
    if (f) return true;
  }
  return f;
}

bool initCompleted = false;
map<char, vector<pair<int, int>>> chars;

void init(vector<vector<char>>& board,
          map<char, vector<pair<int, int>>>& chars) {
  if (initCompleted) return;
  int height = board.size();
  int width = board[0].size();
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (chars.count(board[i][j]) == 0) {
        chars[board[i][j]] = vector<pair<int, int>>();
      }
      chars[board[i][j]].push_back({i, j});
    }
  }
  initCompleted = true;
}

bool exist(vector<vector<char>>& board, string word) {
  if (board.size() == 0) return false;
  init(board, chars);
  // for (auto p : chars) {
  //   cout << p.first << endl;
  //   for (int i = 0; i < p.second.size(); i++) {
  //     cout << p.second[i].first << ", " << p.second[i].second << " ";
  //   }
  //   cout << endl;
  // }

  bool found = false;
  char start = word[0];
  // cout << "start: " << start << endl;
  // for (int i = 0; i < chars[start].size(); i++) {
  //   pair<int, int> s = chars[start][i];
  //   cout << s.first << ", " << s.second << endl;
  // }
  // cout << "====" << endl;
  for (int i = 0; i < chars[start].size(); i++) {
    pair<int, int> s = chars[start][i];
    // cout << s.first << ", " << s.second << endl;
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size()));
    found = rec(board, visited, word, 0, s.second, s.first);
    if (found) {
      return true;
    }
  }
  return false;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int l, n, m;
  cin >> l >> n;
  vector<vector<char>> board(l, vector<char>(n));
  REP(i, l) {
    REP(j, n) { cin >> board[i][j]; }
  }

  cin >> m;
  string s;
  REP(i, m) {
    if (i) cout << " ";
    cin >> s;
    cout << (exist(board, s) ? "true" : "false");
  }
  cout << endl;

  return 0;
}
