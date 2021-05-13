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
struct Node { int data; Node *left, *right; Node(int data) : data(data), left(NULL), right(NULL) {} };
// clang-format on
using namespace bokken;

bool isLeftChild(TreeNode* parent, TreeNode* child) {
  if (!parent) return false;
  return parent->left == child;
}

bool flipEquivHelper(TreeNode* node1, TreeNode* node2, TreeNode* parent1,
                     TreeNode* parent2) {
  // 両方とも端点にたどり着いた
  if (!node1 && !node2) {
    return true;
  }

  if (node1 && node2 && node1->val == node2->val) {
    bool left = flipEquivHelper(node1->left, node2->left, node1, node2);
    if (!left) return false;
    bool right = flipEquivHelper(node1->right, node2->right, node1, node2);
    if (!right) return false;
    return true;
  } else {
    if (isLeftChild(parent1, node1)) {
      swap(parent2->left, parent2->right);
      node2 = parent2->left;
    } else {
      return false;
    }

    if (!node1 && !node2) {
      return true;
    } else if (node1 && node2 && node1->val == node2->val) {
      bool left = flipEquivHelper(node1->left, node2->left, node1, node2);
      if (!left) return false;
      bool right = flipEquivHelper(node1->right, node2->right, node1, node2);
      if (!right) return false;
      return true;
    } else {
      return false;
    }
  }
}

bool flipEquiv(TreeNode* root1, TreeNode* root2) {
  return flipEquivHelper(root1, root2, nullptr, nullptr);
}

void traversal(TreeNode* root) {
  if (!root) return;
  traversal(root->left);
  cout << root->val << endl;
  traversal(root->right);
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);

  int n, m;
  cin >> n;
  vector<string> arr1(n);
  REP(i, n) cin >> arr1[i];

  cin >> m;
  vector<string> arr2(m);
  REP(i, m) cin >> arr2[i];

  TreeNode* root1 = buildTree(arr1);
  TreeNode* root2 = buildTree(arr2);

  cout << (flipEquiv(root1, root2) ? "true" : "false") << endl;

  return 0;
}
