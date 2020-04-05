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
  Node* next;
  Node(int val) : val(val), next(NULL) {}
};

Node* addNode(Node* node1, Node* node2, int carry) {
  if (node1 == NULL && node2 == NULL) {
    return new Node(0 + carry);
  } else if (node1 == NULL) {
    return new Node(node2->val + carry);
  } else if (node2 == NULL) {
    return new Node(node1->val + carry);
  } else {
    return new Node(node1->val + node2->val + carry);
  }
}

Node* addList(Node* list1, Node* list2) {
  Node *ans = NULL, *cans = NULL;
  Node *cur1 = list1, *cur2 = list2;
  int carry = 0;
  while (cur1 != NULL || cur2 != NULL) {
    Node* ele = addNode(cur1, cur2, carry);
    carry = 0;
    carry = ele->val / 10;
    ele->val = ele->val % 10;
    if (ans == NULL) {
      ans = ele;
      cans = ele;
    } else {
      cans->next = ele;
      cans = ele;
    }
    if (cur1 != NULL) cur1 = cur1->next;
    if (cur2 != NULL) cur2 = cur2->next;
  }
  if (carry) {
    cans->next = new Node(1);
  }
  return ans;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  Node *head1, *head2, *prev;
  int a;
  REP(i, N) {
    cin >> a;
    Node* node = new Node(a);
    if (head1 == NULL) {
      head1 = node;
    } else {
      prev->next = node;
    }
    prev = node;
  }
  REP(i, M) {
    cin >> a;
    Node* node = new Node(a);
    if (head2 == NULL) {
      head2 = node;
    } else {
      prev->next = node;
    }
    prev = node;
  }

  Node* ansList = addList(head1, head2);

  vector<int> an;
  Node* cur = ansList;
  while (cur != NULL) {
    an.push_back(cur->val);
    cur = cur->next;
  }
  reverse(an.begin(), an.end());
  for (int i = 0; i < an.size(); i++) {
    cout << an[i];
  }
  cout << endl;

  return 0;
}
