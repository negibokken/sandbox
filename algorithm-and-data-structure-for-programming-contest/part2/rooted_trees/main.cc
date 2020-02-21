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
  int id;
  int parent;
  int depth;
  int num;
  string type;
  vector<int> child;
} Node;

void printNode(Node *n) {
  printf("node %d: parent = %d, depth = %d, %s, ", n->id, n->parent, n->depth,
         n->type.c_str());
  printf("[");
  REP(i, n->num) {
    printf("%c", n->child[i]);
    if (i != n->num - 1) printf(",");
  }
  printf("]\n");
}

void dfs(int v, int depth, Node *nodes[]) {
  nodes[v]->depth = depth;
  if (nodes[v]->num == 0)
    nodes[v]->type = "leaf";
  else if (nodes[v]->num != 0 && nodes[v]->parent != -1) {
    nodes[v]->type = "internal node";
  }
  for (auto child : nodes[v]->child) {
    dfs(child, depth + 1, nodes);
  }
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  Node *nodes[n];
  REP(i, n) nodes[i] = (Node *)malloc(sizeof(Node));
  REP(i, n) {
    nodes[i]->parent = -1;
    nodes[i]->depth = 0;
    int id, num;
    cin >> id >> num;
    nodes[i]->id = id;
    nodes[i]->num = num;

    int c;
    REP(j, nodes[i]->num) {
      cin >> c;
      nodes[i]->child.push_back(c);
      nodes[c]->parent = i;
    }
  }
  printNode(nodes[0]);
  printNode(nodes[1]);
  // depth と type を求める必要がある
  // root を探す
  int root = 0;
  REP(i, n) if (nodes[i]->parent == -1) root = i;
  nodes[root]->type = "root";
  nodes[root]->depth = 0;

  dfs(root, 0, nodes);

  REP(i, n) printNode(nodes[i]);

  return 0;
}
