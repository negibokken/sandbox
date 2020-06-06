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
struct Node { int data; Node *left, *right; Node(int data) : data(data), left(NULL), right(NULL) {} };
// clang-format on

bool hasSame(pair<int, int> p1, pair<int, int> p2) {
  set<int> st;
  st.insert(p1.first);
  st.insert(p1.second);
  st.insert(p2.first);
  st.insert(p2.second);
  return st.size() != 4;
}

vector<int> sortPairs(pair<int, int> p1, pair<int, int> p2) {
  vector<int> arr = {p1.first, p1.second, p2.first, p2.second};
  sort(arr.begin(), arr.end());
  return arr;
}

string v2str(vector<int> arr) {
  string s = "";
  int i = 0;
  for (auto a : arr) {
    if (i++) s += ",";
    s += a;
  }
  return s;
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
  map<int, vector<pair<int, int>>> mp;
  // a + b (c + d) (N^2)
  for (int i = 0; i < nums.size(); i++) {
    for (int j = i + 1; j < nums.size(); j++) {
      mp[nums[i] + nums[j]].push_back(pair<int, int>(i, j));
    }
  }

  vector<vector<int>> result;
  set<string> st;
  for (auto t : mp) {
    int tar = target - t.first;
    if (mp.count(tar) > 0) {
      vector<pair<int, int>> ps = mp[tar];
      for (auto tt : t.second) {
        for (auto p : ps) {
          if (!hasSame(tt, p)) {
            vector<int> cand = sortPairs(tt, p);
            string str = v2str(cand);
            if (!st.count(str)) {
              st.insert(str);
              vector<int> s;
              for (auto c : cand) s.push_back(nums[c]);
              result.push_back(s);
            }
          }
        }
      }
    }
  }

  return result;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);

  int N, target;
  cin >> N >> target;
  vector<int> nums(N);
  REP(i, N) cin >> nums[i];
  vector<vector<int>> ans = fourSum(nums, target);

  int i = 0;
  cout << "[";
  for (auto an : ans) {
    if (i++) cout << ",";
    int j = 0;
    cout << "[";
    for (auto a : an) {
      if (j++) cout << ",";
      cout << a;
    }
    cout << "]" << endl;
  }
  cout << "]" << endl;

  return 0;
}
