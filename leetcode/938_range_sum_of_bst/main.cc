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
struct Node { int data; Node *left, *right; Node(int data) : data(data), left(NULL), right(NULL) {} };
// clang-format on

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

int rangeSumBST(TreeNode *root, int L, int R) {
  if (!root) return 0;
  int sum = 0;
  sum += rangeSumBST(root->left, L, R);
  if (L <= root->val && root->val <= R) sum += root->val;
  sum += rangeSumBST(root->right, L, R);
  return sum;
}

void dfs(TreeNode *root) {
  if (!root) return;
  dfs(root->left);
  cout << root->val << endl;
  if (root->left) cout << "left: " << root->left->val << endl;
  if (root->right) cout << "right: " << root->right->val << endl;
  dfs(root->right);
}

TreeNode *buildTree(vector<int> &nums) {
  if (nums.size() == 0) return nullptr;
  int idx = 0;
  TreeNode *root = new TreeNode(nums[idx]);
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode *cur = q.front();
    q.pop();
    TreeNode *left = nullptr, *right = nullptr;
    if (idx + 1 < nums.size() && nums[idx + 1] != -1) {
      left = new TreeNode(nums[idx + 1]);
    }
    if (idx + 2 < nums.size() && nums[idx + 2] != -1) {
      right = new TreeNode(nums[idx + 2]);
    }
    idx += 2;
    cur->left = left, cur->right = right;
    if (cur->left != nullptr) q.push(cur->left);
    if (cur->right != nullptr) q.push(cur->right);
  }
  return root;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n, l, r;
  cin >> n >> l >> r;
  vector<int> arr(n);
  arrin(arr, n);
  TreeNode *root = buildTree(arr);
  // dfs(root);
  cout << rangeSumBST(root, l, r) << endl;

  return 0;
}
