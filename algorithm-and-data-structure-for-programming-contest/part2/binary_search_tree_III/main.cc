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

class BinaryTree {
  Node *head;

 public:
  BinaryTree() { head = nullptr; }
  Node *getRoot() { return head; }
  Node *find(int v) {
    Node *current = head;
    while (current != nullptr && current->key != v) {
      if (v < current->key)
        current = current->left;
      else
        current = current->right;
    }
    return current;
  }
  Node *createNode(int v) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->key = v, n->left = n->right = n->parent = nullptr;
    return n;
  }
  void insert(int v) {
    Node *current = head;
    Node *parent = nullptr;
    while (current != nullptr) {
      parent = current;
      if (v <= current->key) {
        current = current->left;
        if (current->left == nullptr) {
          current->left = createNode(v);
          current->left->parent = parent;
          break;
        }
      } else {
        current = current->right;
        if (current->right == nullptr) {
          current->right = createNode(v);
          current->right->parent = parent;
          break;
        }
      }
    }
    head = createNode(v);
  }
  void deleteNode(Node *z) {
    bool isLeft = false;
    if (z->parent->left == z)
      isLeft = true;
    else if (z->parent->right == z)
      isLeft = false;

    // 両方とも子がなければ
    if (z->left == nullptr && z->right == nullptr) {
      // 左の子
      if (isLeft)
        z->parent->left = nullptr;
      else
        z->parent->right = nullptr;
      free(z);
      return;
    }

    // どちらか子があるときには子をzの位置にする
    if (z->left == nullptr || z->right == nullptr) {
      if (z->left == nullptr) {
        if (isLeft)
          z->parent->left = z->right;
        else
          z->parent->right = z->right;
      } else if (z->right == nullptr) {
        if (z->left == nullptr) {
          if (isLeft)
            z->parent->left = z->left;
          else
            z->parent->right = z->left;
        }
        free(z);
        return;
      }

      // どちらも子があるとき
      // 左の子のうちで、右がnullptrな右の子を探す
      Node *current = z->left;
      Node *parent = nullptr;
      while (current->right != nullptr) {
        parent = current;
        current = current->right;
      }
      parent->right = nullptr;

      if (isLeft)
        z->parent->left = current;
      else
        z->parent->right = current;
      free(z);
    }
  }
};

int main() {
  int n, i, x;
  string com;
  BinaryTree *b = new BinaryTree();
}
