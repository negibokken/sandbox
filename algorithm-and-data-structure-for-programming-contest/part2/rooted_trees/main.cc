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

typedef struct {
  int id, parent, depth;
  string nodeType;
  vector<int> children;
} Node;

void dfs(int id, vector<Node*> nodes, int depth) {
  nodes[id]->depth = depth;

  if (nodes[id]->children.size() == 0)
    nodes[id]->nodeType = "leaf";
  else if (depth == 0)
    nodes[id]->nodeType = "root";
  else
    nodes[id]->nodeType = "internal node";

  for (auto child : nodes[id]->children) {
    dfs(child, nodes, depth + 1);
  }
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<Node*> nodes(n);

  REP(i, n) nodes[i] = (Node*)malloc(sizeof(Node));
  REP(i, n) {
    int id;
    cin >> id;
    nodes[i]->id = id;
    nodes[i]->parent = -1;
    nodes[i]->depth = 0;
    nodes[i]->nodeType = "";
    int num, child;
    cin >> num;
    REP(j, num) {
      cin >> child;
      nodes[i]->children.push_back(child);
      nodes[child]->parent = i;
    }
  }
  int root = 0;
  REP(i, n) {
    if (nodes[i]->parent == -1) {
      root = i;
      break;
    }
  }

  dfs(root, nodes, 0);

  REP(i, n) {
    printf("node: %d: parent = %d, depth = %d, %s,", nodes[i]->id,
           nodes[i]->parent, nodes[i]->depth, nodes[i]->nodeType.c_str());
    printf("[");
    REP(j, nodes[i]->children.size()) {
      printf("%d", nodes[i]->children[j]);
      if (j != nodes[i]->children.size() - 1) printf(", ");
    }
    printf("]\n");
  }

  return 0;
}
