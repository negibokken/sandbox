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
  Node(int val) : val(val) {}
};

Node* rec(int l, int r, vector<int> a) {
  if (l >= r) return NULL;
  int mid = (l + r) / 2;
  Node* n = new Node(a[mid]);
  n->left = rec(l, mid, a);
  n->right = rec(mid + 1, r, a);
  return n;
}

Node* solve(vector<int> a) {
  int N = a.size();
  Node* head = rec(0, N, a);
  return head;
}

vector<Node*> V[100];
int maxdepth = 0;

void dfs(Node* head, int depth) {
  if (head == NULL) return;
  maxdepth = max(maxdepth, depth);
  V[depth].push_back(head);
  dfs(head->left, depth + 1);
  dfs(head->right, depth + 1);
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> a(N);
  REP(i, N) cin >> a[i];
  sort(a.begin(), a.end());
  Node* head = solve(a);

  stack<Node*> q;
  q.push(head);
  while (!q.empty()) {
    Node* n = q.top();
    q.pop();
    cout << n->val << " ";
    if (n->right != NULL) q.push(n->right);
    if (n->left != NULL) q.push(n->left);
  }

  dfs(head, 0);

  REP(i, maxdepth + 1) {
    cout << i << ": ";
    for (auto v : V[i]) {
      cout << v->val << " ";
    }
    cout << endl;
  }

  return 0;
}
