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

bool isnum(char& c) { return '0' <= c && c <= '9'; }
bool isop(char& c) { return c == '+' || c == '-' || c == '(' || c == ')'; }
bool isbr(char& c) { return c == '(' || c == ')'; }

int op2pr(char& c) {
  switch (c) {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    case '(':
    case ')':
      return 3;
    default:
      return -1;
  }
}

bool isHighPriorityOp(char cur, char prev) { return op2pr(cur) > op2pr(prev); }

string e2rpn(string s) {
  string ans;
  stack<char> opq;
  for (int i = 0; i < s.size(); i++) {
    char c = s[i];
    if (isnum(c)) {
      string tmp;
      while (i < s.size() && isnum(s[i])) {
        tmp += s[i];
        i++;
      }
      reverse(tmp.begin(), tmp.end());
      ans += tmp;
      ans += '|';
      i--;
    } else if (isop(c)) {
      if (c == '(') {
        opq.push(c);
      } else if (c == ')') {
        while (!opq.empty() && c != '(') {
          c = opq.top();
          opq.pop();
          if (c != '(') ans += c;
        }
      } else if (!opq.empty() && opq.top() != '(' &&
                 !isHighPriorityOp(c, opq.top())) {
        ans += opq.top();
        opq.pop();
        opq.push(c);
      } else {
        opq.push(c);
      }
    } else {
      // space, skip
    }
  }
  while (!opq.empty()) {
    ans += opq.top();
    opq.pop();
  }
  return ans;
}

int calculate(string s) {
  s = e2rpn(s);
  stack<int> nums;
  for (int i = 0; i < s.size(); i++) {
    char c = s[i];
    if (isnum(c)) {
      int sum = 0;
      int cnt = 0;
      while (i < s.size() && s[i] != '|') {
        sum += (long)(s[i] - '0') * pow(10, cnt);
        cnt++, i++;
      }
      i--;
      nums.push(sum);
    } else if (isop(c)) {
      int opr2 = nums.top();
      nums.pop();
      int opr1 = nums.top();
      nums.pop();
      if (c == '+') {
        nums.push(opr1 + opr2);
      } else if (c == '-') {
        nums.push(opr1 - opr2);
      }
    }
  }
  return nums.top();
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  string s;
  getline(std::cin, s);
  // cout << e2rpn(s) << endl;
  cout << calculate(s) << endl;

  return 0;
}
