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

bool isDeleted(TreeNode* node, vector<int>& to_delete) {
  if (!node) return true;
  auto it = find(to_delete.begin(), to_delete.end(), node->val);
  return it != to_delete.end();
}

void rec(TreeNode* root, TreeNode* prev, vector<int>& to_delete,
         vector<TreeNode*>& ans) {
  if (ans.size() == 0 && !isDeleted(root, to_delete)) ans.push_back(root);
  if (!root) return;
  if (isDeleted(root, to_delete)) {
    if (prev && prev->left == root) prev->left = nullptr;
    if (prev && prev->right == root) prev->right = nullptr;
    if (root->left && !isDeleted(root->left, to_delete))
      ans.push_back(root->left);
    if (root->right && !isDeleted(root->right, to_delete))
      ans.push_back(root->right);
  }
  rec(root->left, root, to_delete, ans);
  rec(root->right, root, to_delete, ans);
}

vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
  sort(to_delete.begin(), to_delete.end());
  vector<TreeNode*> ans;
  rec(root, nullptr, to_delete, ans);
  return ans;
}

vector<string> to_array(TreeNode* root) {
  vector<string> ans;
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode* node = q.front();
    q.pop();
    if (!node) {
      if (!q.empty())
        if (q.front() != nullptr) ans.push_back("null");
      continue;
    }
    ans.push_back(to_string(node->val));
    q.push(node->left);
    q.push(node->right);
  }
  return ans;
}

string to_string(vector<string> arr) {
  string res = "[";
  for (int i = 0; i < arr.size(); i++) {
    if (i) res += ",";
    res += arr[i];
  }
  res += "]";
  return res;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int m, n;
  cin >> m;
  vector<string> arr(m);
  REP(i, m) cin >> arr[i];
  cin >> n;
  vector<int> to_delete(n);
  REP(i, n) cin >> to_delete[i];
  TreeNode* root = buildTree(arr);
  vector<TreeNode*> ans = delNodes(root, to_delete);

  string str = "[";
  for (int i = 0; i < ans.size(); i++) {
    if (i) str += ",";
    str += to_string(to_array(ans[i]));
  }
  str += "]";
  cout << str;

  return 0;
}
