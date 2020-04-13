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

struct Node {
  int val;
  Node *left, *right;
  Node* parent;
  Node(int val) : val(val), left(NULL), right(NULL), parent(NULL) {}
};

Node* make_model() {
  Node* head = new Node(4);
  head->parent = NULL;

  head->left = new Node(2);
  head->left->parent = head;
  head->right = new Node(7);
  head->right->parent = head;

  head->left->left = new Node(1);
  head->left->left->parent = head->left;
  head->left->right = new Node(3);
  head->left->right->parent = head->left;
  head->right->left = new Node(6);
  head->right->left->parent = head->right;

  head->right->left->left = new Node(5);
  head->right->left->left->parent = head->right->left;
  head->right->right = new Node(8);
  head->right->right->parent = head->right;
  return head;
}

Node* leftMostChild(Node* n) {
  if (n == NULL) {
    return NULL;
  }
  while (n->left != NULL) {
    n = n->left;
  }
  return n;
}

Node* inorderSucc(Node* n) {
  if (n == NULL) return NULL;
  if (n->right != NULL) {
    return leftMostChild(n->right);
  } else {
    Node* q = n;
    Node* x = n->parent;
    while (x != NULL && x->left != q) {
      q = x;
      x = x->parent;
    }
    return x;
  }
}

Node* findNode(Node* node, int val) {
  if (node == NULL) {
    return NULL;
  }
  if (node->val == val) {
    return node;
  } else if (node->val > val) {
    return findNode(node->left, val);
  } else {
    return findNode(node->right, val);
  }
}

void search(Node* node) {
  if (node == NULL) return;
  search(node->left);
  cout << "node: " << node->val;
  if (node->parent != NULL) cout << ", parent: " << node->parent->val;
  cout << endl;
  search(node->right);
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, a;
  cin >> n;
  Node* head = make_model();

  // search(head);
  REP(i, n) {
    cin >> a;
    Node* node = findNode(head, a);
    if (i) cout << " ";
    Node* next = inorderSucc(node);
    cout << node->val << "->";
    if (next != NULL)
      cout << next->val;
    else
      cout << 0;
  }
  cout << endl;

  return 0;
}
