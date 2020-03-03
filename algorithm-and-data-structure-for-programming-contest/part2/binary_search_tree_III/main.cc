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
        if (current->left == nullptr) {
          current->left = createNode(v);
          current->left->parent = parent;
          return;
        }
        current = current->left;
      } else {
        if (current->right == nullptr) {
          current->right = createNode(v);
          current->right->parent = parent;
          return;
        }
        current = current->right;
      }
    }
    head = createNode(v);
  }
  void deleteNode(Node *z) {
    bool isLeft = false, isRoot = false;
    if (z->parent == nullptr) {
      isRoot = true;
    } else if (z->parent->left == z)
      isLeft = true;
    else if (z->parent->right == z)
      isLeft = false;

    // 両方とも子がなければ
    if (z->left == nullptr && z->right == nullptr) {
      // 左の子
      if (isRoot) head = nullptr;
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
        if (isRoot) {
          head = z->right;
        } else if (isLeft) {
          z->parent->left = z->right;
        } else {
          z->parent->right = z->right;
        }
        if (!isRoot) z->right->parent = z->parent;
        free(z);
        return;
      } else if (z->right == nullptr) {
        if (z->left == nullptr) {
          if (isRoot) {
            head = z->left;
          } else if (isLeft)
            z->parent->left = z->left;
          else
            z->parent->right = z->left;
        }
        if (!isRoot) z->left->parent = z->parent;
        free(z);
        return;
      }
    }

    // どちらも子があるとき
    // 左の子のうちで、右がnullptrな右の子を探す
    Node *current = z->left;
    Node *parent = nullptr;
    while (current->right != nullptr) {
      parent = current;
      current = current->right;
    }
    if (parent != nullptr) parent->right = nullptr;

    if (isRoot) {
      head = current;
      head->right = z->right;
    } else if (isLeft) {
      z->parent->left = current;
    } else {
      z->parent->right = current;
    }
    if (!isRoot) current->parent = z->parent;
    free(z);
  }

  void print() {
    printInorder(head);
    cout << endl;
    printPreorder(head);
    cout << endl;
  }

 private:
  void printInorder(Node *v) {
    if (v == nullptr) return;
    printInorder(v->left);
    cout << v->key << " ";
    printInorder(v->right);
  }
  void printPreorder(Node *v) {
    if (v == nullptr) return;
    cout << v->key << " ";
    printPreorder(v->left);
    printPreorder(v->right);
  }
};

int main() {
  int n;
  string com;
  BinaryTree *bt = new BinaryTree();
  cin >> n;
  int num;
  string order;
  REP(i, n) {
    cin >> order;
    if (order == "insert") {
      cin >> num;
      bt->insert(num);
    } else if (order == "find") {
      cin >> num;
      cout << (bt->find(num) ? "yes" : "no") << endl;
    } else if (order == "print") {
      bt->print();
    } else if (order == "delete") {
      cin >> num;
      bt->deleteNode(bt->find(num));
    }
  }
}
