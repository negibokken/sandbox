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

    Node *cur = head;
    while (cur->next != nullptr) cur = cur->next;
    cur->next = n;
    n->prev = cur;
    return;
  }

  void deleteKey(int key) {
    if (head == nullptr) return;
    Node *cur = head;
    while (cur->next != nullptr && cur->key == key) cur = cur->next;
    if (cur->key == key) {
      if (cur->prev != nullptr) cur->prev->next = cur->next;
      if (cur->next != nullptr) cur->next->prev = cur->prev;
      free(cur);
      return;
    }
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
      // cout << "delete " << key << endl;
      l->deleteKey(key);
    }
  }

  printList();
  return 0;
}
