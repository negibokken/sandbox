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

struct Node {
  int key;
  Node *next, *prev;
};

class List {
 public:
  List() { head = nullptr; }
  void insert(int key) {
    if (head == nullptr) {
      head = (Node *)malloc(sizeof(Node));
      head->key = key;
      return;
    }

    Node *n = (Node *)malloc(sizeof(Node));
    n->key = key;
    n->prev = nullptr, n->next = head;
    head->prev = n;
    head = n;
    return;
  }

  void deleteKey(int key) {
    // printList();
    if (head == nullptr) return;
    Node *cur = head;
    while (cur->next != nullptr) {
      if (cur->key == key) break;
      cur = cur->next;
    }

    // printAtomic(cur);

    if (cur->key == key) {
      Node *next = cur->next;
      Node *prev = cur->prev;

      // prev->next = next;
      // next->prev = prev;
      if (prev != nullptr)
        prev->next = next;
      else
        head = next;
      if (next != nullptr) next->prev = prev;
      free(cur);
      // printList();
      return;
    }
  }

  void printAtomic(Node *n) { cout << n->key << " "; }
  void printAtomicDetail(Node *n) {
    cout << n->key << " "
         << "(" << n << ") ";
    if (n->prev != nullptr)
      cout << "(" << n->prev << ", ";
    else
      cout << "(null, ";
    if (n->next != nullptr)
      cout << n->next << ")" << endl;
    else
      cout << "null)" << endl;
  }

  void printList() {
    if (head == nullptr) return;
    for (Node *cur = head; cur != nullptr; cur = cur->next) {
      printAtomic(cur);
      // printAtomicDetail(cur);
    }
    cout << endl;
  }

 private:
  Node *head;
};

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  string order;
  int key;

  List *l = new List();

  REP(i, n) {
    cin >> order >> key;
    if (order == "insert") {
      l->insert(key);
    } else if (order == "delete") {
      l->deleteKey(key);
    }
  }

  l->printList();
  return 0;
}
