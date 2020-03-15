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
#define MAX 1000
#define INFTY (1<<30)
#define EPS (1e-10)
#define equals(a, b) (fabs((a) - (b)) < EPS)
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
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
// clang-format on

struct Rectangle {
  int height;
  int pos;
};

int getLargestRectangle(int size, int buffer[]) {
  stack<Rectangle> S;
  int maxv = 0;
  buffer[size] = 0;

  for (int i = 0; i <= size; i++) {
    Rectangle rect;
    rect.height = buffer[i];
    rect.pos = i;
    if (S.empty()) {
      S.push(rect);
    } else {
      if (S.top().height < rect.height) {
        S.push(rect);
      } else if (S.top().height > rect.height) {
        int target = i;
        while (!S.empty() && S.top().height >= rect.height) {
          Rectangle pre = S.top();
          S.pop();
          int area = pre.height * (i - pre.pos);
          maxv = max(maxv, area);
          target = pre.pos;
        }
        rect.pos = target;
        S.push(rect);
      }
    }
  }
  return maxv;
}

int H, W;
int buffer[MAX][MAX];
int T[MAX][MAX];

int getLargestRectangle() {
  for (int j = 0; j < W; j++) {
    for (int i = 0; i < H; i++) {
      if (buffer[i][j]) {
        T[i][j] = 0;
      } else {
        T[i][j] = (i > 0) ? T[i - 1][j] + 1 : 1;
      }
    }
  }
  int maxv = 0;
  for (int i = 0; i < H; i++) {
    maxv = max(maxv, getLargestRectangle(W, T[i]));
  }
  return maxv;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> H >> W;
  REP(i, H) {
    REP(j, W) { scanf("%d", &buffer[i][j]); }
  }

  cout << getLargestRectangle() << endl;

  return 0;
}
