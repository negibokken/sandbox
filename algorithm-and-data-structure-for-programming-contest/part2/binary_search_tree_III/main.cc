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

typedef struct Node {
  int key;
  Node *right, *left, *parent;
} Node;

Node *root, *NIL;

Node *treeMinimum(Node *x) {
  while (x->left != NIL) x = x->left;
  return x;
}

Node *find(Node *u, int k) {
  while (u != NIL && u->key != k) {
    if (k < u->key)
      u = u->left;
    else
      u = u->right;
  }
  return u;
}

Node *treeSuccessor(Node *x) {
  if (x->right != NIL) return treeMinimum(x->right);
  Node *y = x->parent;
  while (y != NIL && x == y->right) {
    x = y;
    y = y->parent;
  }
  return y;
}

void treeDelete(Node *z) {
  Node *y;
  Node *x;

  if (z->left == NIL || z->right == NIL) {
    y = z;
  } else {
    y = treeSuccessor(z);
  }

  if (y->left != NIL)
    x = y->left;
  else
    x = y->right;

  if (x != NIL) x->parent = y->parent;

  if (y->parent == NIL) {
    root = x;
  } else {
    if (y == y->parent->left) {
      y->parent->left = x;
    } else {
      y->parent->right = x;
    }
  }
  if (y != z) {
    z->key = y->key;
  }
  free(y);
}

void insert(int k) {
  Node *y = NIL;
  Node *x = root;
  Node *z;

  z = (Node *)malloc(sizeof(Node));
  z->key = k;
  z->left = NIL;
  z->right = NIL;

  while (x != NIL) {
    y = x;
    if (z->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }
  z->parent = y;
  if (y == NIL) {
    root = z;
  } else {
    if (z->key < y->key) {
      y->left = z;
    } else {
      y->right = z;
    }
  }
}

void inorder(Node *u) {
  if (u == NIL) return;
  inorder(u->left);
  printf(" %d\n", u->key);
  inorder(u->right);
}

void preorder(Node *u) {
  if (u == NIL) return;
  printf(" %d\n", u->key);
  preorder(u->left);
  preorder(u->right);
}

int main() {
  int n, i, x;
  string com;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    cin >> com;
    if (com[0] == 'f') {
      scanf("%d", &x);
      Node *t = find(root, x);
      if (t != NIL)
        printf("yes\n");
      else
        printf("no\n");
    } else if (com == "insert") {
      scanf("%d", &x);
      insert(x);
    } else if (com == "print") {
      inorder(root);
      printf("\n");
      preorder(root);
      printf("\n");
    } else if (com == "delete") {
      scanf("%d", &x);
      treeDelete(find(root, x));
    }
  }
}
