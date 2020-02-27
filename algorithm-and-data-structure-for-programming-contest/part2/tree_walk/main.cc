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
  int left, right;
} Node;

void preorder(vector<Node*> nodes, int v) {
  cout << nodes[v]->id << " ";
  if (nodes[v]->left != -1) preorder(nodes, nodes[v]->left);
  if (nodes[v]->right != -1) preorder(nodes, nodes[v]->right);
}
void inorder(vector<Node*> nodes, int v) {
  if (nodes[v]->left != -1) inorder(nodes, nodes[v]->left);
  cout << nodes[v]->id << " ";
  if (nodes[v]->right != -1) inorder(nodes, nodes[v]->right);
}
void postorder(vector<Node*> nodes, int v) {
  if (nodes[v]->left != -1) postorder(nodes, nodes[v]->left);
  if (nodes[v]->right != -1) postorder(nodes, nodes[v]->right);
  cout << nodes[v]->id << " ";
}

void walk(int t, vector<Node*> nodes, int root) {
  switch (t) {
    case 0: {
      preorder(nodes, root);
      return;
    }
    case 1: {
      inorder(nodes, root);
      return;
    }
    case 2: {
      postorder(nodes, root);
      return;
    }
  }
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, t;
  cin >> n >> t;
  vector<Node*> nodes(n);
  REP(i, n) nodes[i] = (Node*)malloc(sizeof(Node));

  int id, left, right;
  REP(i, n) {
    cin >> id >> left >> right;
    nodes[i]->id = id;
    nodes[i]->left = left;
    nodes[i]->right = right;
  }
  int root = 0;

  walk(t, nodes, root);

  return 0;
}
