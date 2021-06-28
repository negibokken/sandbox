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
// clang-format on

class Node {
 public:
  int val;
  Node *left;
  Node *right;
  Node *parent;
  Node(int v) : val(v), left(nullptr), right(nullptr), parent(nullptr) {}
};

Node *lowestCommonAncestor(Node *p, Node *q) {
  Node *qcur = q, *pcur = p;
  while (1) {
    qcur = q;
    while (qcur) {
      if (pcur->val == qcur->val) {
        return pcur;
      }
      qcur = qcur->parent;
    }
    pcur = pcur->parent;
  }
}

void rec(Node *node) {
  if (!node) return;
  cout << node->val << " ";
  rec(node->left);
  rec(node->right);
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n;
  cin >> n;
  Node *nodes[n];
  string s;
  REP(i, n) {
    cin >> s;
    if (s == "null") {
      nodes[i] = nullptr;
      continue;
    }
    Node *node = new Node(std::atoi(s.c_str()));
    nodes[i] = node;
  }

  Node *p, *q;
  int pn, qn;
  cin >> pn >> qn;

  for (int i = 0; i < n; ++i) {
    if (nodes[i] && nodes[i]->val == pn) p = nodes[i];
    if (nodes[i] && nodes[i]->val == qn) q = nodes[i];

    if (2 * i + 1 < n && nodes[2 * i + 1]) {
      nodes[2 * i + 1]->parent = nodes[i];
      if (nodes[i]) nodes[i]->left = nodes[2 * i + 1];
    }
    if (2 * i + 2 < n && nodes[2 * i + 2]) {
      nodes[2 * i + 2]->parent = nodes[i];
      if (nodes[i]) nodes[i]->right = nodes[2 * i + 2];
    }
  }

  cout << lowestCommonAncestor(p, q)->val << endl;

  return 0;
}

