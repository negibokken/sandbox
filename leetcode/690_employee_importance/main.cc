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

class Employee {
 public:
  int id;
  int importance;
  vector<int> subordinates;
};

class Node {
 public:
  int id;
  int value;
  vector<Node*> children;
};

int getImportance(vector<Employee*> employees, int id) {
  int maxid = 0;
  for (auto employee : employees) {
    cout << employee->id << endl;
    maxid = max(maxid, employee->id);
  }
  vector<Node*> nodes = vector<Node*>(maxid + 1, new Node());
  for (auto employee : employees) {
    int eid = employee->id;
    nodes[eid]->id = employee->id;
    nodes[eid]->value = employee->importance;
    for (int i = 0; i < employee->subordinates.size(); i++) {
      int sid = employee->subordinates[i];
      nodes[eid]->children.push_back(nodes[sid]);
    }
  }
  Node* root = nullptr;
  for (auto node : nodes) {
    cout << node->id << endl;
    if (node != nullptr && node->id == id) {
      root = node;
      break;
    }
  }
  cout << root->id << endl;

  int total = 0;
  queue<int> q;
  q.push(root->id);
  while (!q.empty()) {
    int id = q.front();
    q.pop();
    total += nodes[id]->value;
    for (auto child : nodes[id]->children) {
      q.push(child->id);
    }
  }
  return total;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int target, N;
  cin >> N >> target;
  vector<Employee*> res;
  REP(i, N) {
    int id, value, num;
    cin >> id >> value >> num;
    vector<int> subordinates;
    int sub;
    REP(j, num) {
      cin >> sub;
      subordinates.push_back(sub);
    }
    Employee* emp = new Employee();
    emp->id = id;
    emp->importance = value;
    emp->subordinates = subordinates;
    res.push_back(emp);
  }
  cout << getImportance(res, target) << endl;

  return 0;
}
