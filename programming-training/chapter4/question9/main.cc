#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <list>
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
  int data;
  Node *left, *right;
  Node(int data) : data(data), left(NULL), right(NULL) {}
};

void weaveLists(list<int>& first, list<int>& second, vector<list<int>>& results,
                list<int>& prefix) {
  if (first.size() == 0 || second.size() == 0) {
    list<int> result = list<int>(prefix);
    result.insert(result.end(), first.begin(), first.end());
    result.insert(result.end(), second.begin(), second.end());
    results.push_back(result);
    return;
  }

  int headFirst = *first.begin();
  first.pop_front();
  prefix.push_back(headFirst);
  weaveLists(first, second, results, prefix);

  prefix.pop_back();
  first.push_front(headFirst);

  int headSecond = *second.begin();
  second.pop_front();
  prefix.push_back(headSecond);
  weaveLists(first, second, results, prefix);
  prefix.pop_back();
  second.push_front(headSecond);
}

vector<list<int>> allsequences(Node* node) {
  vector<list<int>> result = vector<list<int>>();
  if (node == NULL) {
    result.push_back(list<int>());
    return result;
  }
  list<int> prefix = list<int>();
  prefix.push_back(node->data);

  vector<list<int>> leftSeq = allsequences(node->left);
  vector<list<int>> rightSeq = allsequences(node->right);

  for (list<int> left : leftSeq) {
    for (list<int> right : rightSeq) {
      vector<list<int>> weaved = vector<list<int>>();
      weaveLists(left, right, weaved, prefix);
      result.insert(result.end(), weaved.begin(), weaved.end());
    }
  }
  return result;
}

Node* make_tree() {
  Node* head = new Node(2);
  head->left = new Node(1);
  head->right = new Node(3);
  return head;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  Node* root = make_tree();
  vector<list<int>> results = allsequences(root);

  int cnt = 0;
  for (auto result : results) {
    if (cnt++) cout << ",";
    cout << "{";
    int i = 0;
    for (auto r : result) {
      if (i++) cout << ",";
      cout << r;
    }
    cout << "}";
  }

  return 0;
}
