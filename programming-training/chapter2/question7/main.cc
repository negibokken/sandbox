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

Node* commonNode(Node* head1, Node* head2) {
  int l1 = 0, l2 = 0;
  if (head1 == NULL || head2 == NULL) return NULL;
  Node *cur1 = head1, *cur2 = head2;
  while (cur1->next != NULL) l1++, cur1 = cur1->next;
  while (cur2->next != NULL) l2++, cur2 = cur2->next;
  l1++, l2++;
  if (cur1 != cur2) return NULL;
  cur1 = head1, cur2 = head2;

  if (l1 > l2) {
    for (int i = 0; i < l1 - l2; i++) {
      cur1 = cur1->next;
    }
  } else if (l2 > l1) {
    for (int i = 0; i < l2 - l1; i++) {
      cur2 = cur2->next;
    }
  }
  while (cur1 != NULL && cur2 != NULL) {
    if (cur1 == cur2) return cur1;
    cur1 = cur1->next;
    cur2 = cur2->next;
  }
  return NULL;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  Node *head = NULL, *prev = NULL;
  Node* node7 = NULL;
  int a;
  REP(i, N) {
    cin >> a;
    Node* node = new Node(a);
    if (head == NULL) {
      head = node;
    } else {
      prev->next = node;
    }
    if (a == 7) node7 = node;
    prev = node;
  }

  Node* head2 = new Node(4);
  head2->next = new Node(6);
  head2->next->next = node7;

  Node* ans = commonNode(head, head2);

  if (ans == NULL) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
    cout << ans->val << endl;
  }

  return 0;
}
