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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// clang-format on

// long long res = 0;
// int totalSum(TreeNode *root) {
//   if (root == nullptr) return 0;
//   return root->val + totalSum(root->left) + totalSum(root->right);
// }
//
// void maxProduct(TreeNode *root, int total) {
//   if (root == nullptr) return;
//   int sub = totalSum(root);
//   res = max<long long>(res, (total - sub) * sub);
//   maxProduct(root->left, total);
//   maxProduct(root->right, total);
// }
//
// int maxProduct(TreeNode *root) {
//   int total = totalSum(root);
//   maxProduct(root, total);
//   return res % (int)(1e9 + 7);
// }

long res = 0, total = 0, sub;
int s(TreeNode *root) {
  if (!root) return 0;
  sub = root->val + s(root->left) + s(root->right);
  res = max(res, sub * (total - sub));
  return sub;
}
int maxProduct(TreeNode *root) {
  total = s(root), s(root);
  return res % (int)(1e9 + 7);
}

void bfs(TreeNode *root) {
  if (root == nullptr) return;
  cout << "val: " << root->val << endl;
  if (root->left)
    cout << "left: " << root->left->val << endl;
  else
    cout << "left: null" << endl;
  if (root->right)
    cout << "right: " << root->right->val << endl;
  else
    cout << "right: null" << endl;
  cout << endl;
  bfs(root->left);
  bfs(root->right);
}

TreeNode *buildTree(TreeNode *root, vector<int> arr) {
  root = new TreeNode(arr[0]);
  queue<TreeNode *> q;
  q.push(root);
  for (int i = 1; i < arr.size(); i++) {
    TreeNode *node = q.front();
    if (node->left == nullptr && arr[i - 1] != -1) {
      if (arr[i] != -1) {
        node->left = new TreeNode(arr[i]);
        q.push(node->left);
      }
    } else if (node->right == nullptr && arr[i - 1] != -1) {
      node->right = new TreeNode(arr[i]);
      if (arr[i] != -1) q.push(node->right);
      q.pop();
    }
  }
  return root;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n;
  cin >> n;
  vector<int> arr(n);
  REP(i, n) cin >> arr[i];
  TreeNode *root = buildTree(root, arr);
  bfs(root);
  cout << maxProduct(root) << endl;

  return 0;
}
