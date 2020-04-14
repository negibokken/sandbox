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
  char val;
  Node *left, *right;
  Node(char val) : val(val), left(NULL), right(NULL) {}
};

void bfs(int u, vector<vector<int>> v, vector<int> &deg, vector<bool> &visited,
         vector<int> &ans) {
  queue<int> q;
  q.push(u);
  visited[u] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    ans.push_back(u);
    for (auto uu : v[u]) {
      deg[uu]--;
      if (deg[uu] == 0 && !visited[uu]) {
        visited[uu] = true;
        q.push(uu);
      }
    }
  }
}

void tsort(vector<vector<int>> v, vector<int> &deg, vector<bool> &visited,
           vector<int> &ans) {
  int N = v.size();
  for (int u = 0; u < N; u++) {
    if (deg[u] == 0 && !visited[u]) bfs(u, v, deg, visited, ans);
  }
  for (int i = 0; i < ans.size(); i++) {
    if (i) cout << " ";
    cout << (char)(ans[i] + 'a');
  }
  cout << endl;
}
int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n);
  vector<int> deg(n);
  vector<bool> visited(n);
  vector<int> ans;
  char a, b;
  REP(i, m) {
    cin >> a >> b;
    v[a - 'a'].push_back(b - 'a');
    deg[b - 'a']++;
  }

  // REP(i, n) {
  //   cout << i << ":  ";
  //   for (auto u : v[i]) {
  //     cout << u << "  ";
  //   }
  //   cout << "(" << deg[i] << ")" << endl;
  // }
  // return 0;
  tsort(v, deg, visited, ans);

  return 0;
}
