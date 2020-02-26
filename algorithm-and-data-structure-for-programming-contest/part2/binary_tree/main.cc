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
  int depth, height;
  int left, right;
  int sibling, parent;
  int degree;
  string nodeType;
} Node;

int setHeight(int id, vector<Node *> nodes) {
  int h1 = 0, h2 = 0;
  if (nodes[id]->left != -1) {
    h1 = setHeight(nodes[id]->left, nodes) + 1;
  }
  if (nodes[id]->right != -1) {
    h2 = setHeight(nodes[id]->right, nodes) + 1;
  }
  return nodes[id]->height = max(h1, h2);
}

void setDepth(int id, vector<Node *> nodes, int depth) {
  nodes[id]->depth = depth;
  if (nodes[id]->parent == -1) {
    nodes[id]->nodeType = "parent";
  } else if (nodes[id]->right == -1 && nodes[id]->left == -1) {
    nodes[id]->nodeType = "leaf";
  } else {
    nodes[id]->nodeType = "internal node";
  }

  int deg = 0;
  if (nodes[id]->left != -1) {
    setDepth(nodes[id]->left, nodes, depth + 1);
    deg++;
  }
  if (nodes[id]->right != -1) {
    setDepth(nodes[id]->right, nodes, depth + 1);
    deg++;
  }
  nodes[id]->degree = deg;
}

void print(Node *node) {
  printf(
      "node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = "
      "%d, %s\n",
      node->id, node->parent, node->sibling, node->degree, node->depth,
      node->height, node->nodeType.c_str());
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<Node *> nodes(n);
  REP(i, n) {
    nodes[i] = (Node *)malloc(sizeof(Node));
    nodes[i]->depth = 0;
    nodes[i]->height = 0;
    nodes[i]->nodeType = "";
    nodes[i]->parent = -1;
  }

  int id, left, right;
  REP(i, n) {
    cin >> id;
    nodes[i]->id = id;

    cin >> left >> right;
    nodes[i]->left = left;
    nodes[i]->right = right;
    if (left != -1) {
      nodes[left]->sibling = right;
      nodes[left]->parent = id;
    }
    if (right != -1) {
      nodes[right]->sibling = left;
      nodes[right]->parent = id;
    }
  }
  int root = -1;
  REP(i, n)
  if (nodes[i]->parent == -1) {
    root = nodes[i]->id;
  }

  setHeight(root, nodes);
  setDepth(root, nodes, 0);

  REP(i, n) print(nodes[i]);

  return 0;
}
