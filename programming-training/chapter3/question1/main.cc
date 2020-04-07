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

class ThreeStack {
 private:
  vector<int> a;
  int sizes[3];
  int capacities[3];
  int idxes[3], popidxes[3];
  int n;

  int getPushIdx(int idx) { return idx * (n / 3) + idxes[idx]; }
  void incrementPushIdx(int idx) {
    idxes[idx] = (idxes[idx] + 1) % (n / 3);
    sizes[idx]++;
  }
  int getPopIdx(int idx) { return idx * (n / 3) + popidxes[idx]; }
  void incrementPopIdx(int idx) {
    popidxes[idx] = (popidxes[idx] + 1) % (n / 3);
    sizes[idx]--;
  }

 public:
  ThreeStack(int N) {
    n = N;
    a.resize(n, 0);
    for (int i = 0; i < 3; i++) {
      capacities[i] = n / 3;
      idxes[i] = popidxes[i] = sizes[i] = 0;
    }
  }
  bool isEmpty(int idx) { return !sizes[idx]; }
  bool isFull(int idx) { return sizes[idx] == n / 3; }
  bool size(int idx) { return sizes[idx]; }
  void push(int idx, int val) {
    if (isFull(idx)) return;
    a[getPushIdx(idx)] = val;
    incrementPushIdx(idx);
  }
  void pop(int idx) {
    if (isEmpty(idx)) return;
    incrementPopIdx(idx);
  }
  int front(int idx) {
    if (isEmpty(idx)) return 0;
    int val = a[getPopIdx(idx)];
    return val;
  }
};

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  ThreeStack t = ThreeStack(N);

  int idx, a;
  REP(i, N) {
    cin >> idx >> a;
    t.push(idx, a);
  }

  for (int i = 0; i < N / 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << t.front(j) << endl;
      t.pop(j);
    }
  }

  return 0;
}
