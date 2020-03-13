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
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

// Self settings
// clang-format off
#define MAX_N 100000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
ll fact(ll n) { ll res = 1; for(ll i=2;i<=n;++i) res = res * i; return res;}
ll nCr(ll n, ll r) {return (fact(n)/fact(n-r)*fact(r)) ;}
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
const ll MOD = 1e9+7;
const ll INF = 1LL << 60;
const int inf = 1000100011;
// clang-format on
#define MAX 10000
#define INFTY (1 << 29)

class DisjointSet {
 private:
  int n;
  vector<int> A, rnk;

 public:
  DisjointSet(int n) : n(n) {
    A = vector<int>(n), rnk = vector<int>(n), init(n);
  }
  void init(int n) { REP(i, n) A[i] = i, rnk[i] = 0; }
  int find(int x) { return x == A[x] ? x : A[x] = find(A[x]); }
  int same(int x, int y) { return find(x) == find(y); }
  void unite(int x, int y) {
    int u = find(x), v = find(y);
    if (u == v) return;
    if (rnk[u] < rnk[v]) {
      A[u] = v;
    } else {
      A[v] = u;
      if (rnk[u] == rnk[y]) rnk[u]++;
    }
  }
};

class Edge {
 public:
  int source, target, cost;
  Edge(int source = 0, int target = 0, int cost = 0)
      : source(source), target(target), cost(cost) {}
  bool operator<(const Edge &e) const { return cost < e.cost; }
};

int kruskal(int N, vector<Edge> edges) {
  int totalCost = 0;
  sort(edges.begin(), edges.end());
  DisjointSet dest = DisjointSet(N + 1);

  int source, target;
  for (int i = 0; i < edges.size(); i++) {
    Edge e = edges[i];
    if (!dest.same(e.source, e.target)) {
      totalCost += e.cost;
      dest.unite(e.source, e.target);
    }
  }
  return totalCost;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, M, cost;
  int source, target;

  cin >> N >> M;
  vector<Edge> edges;

  REP(i, M) {
    cin >> source >> target >> cost;
    edges.push_back(Edge(source, target, cost));
  }
  cout << kruskal(N, edges) << endl;

  return 0;
}
