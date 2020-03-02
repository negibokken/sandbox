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
  int val;
  Node *left, *right;
} Node;

void preOrder(Node *v, vector<int> &ans) {
  if (v == nullptr) return;
  ans.push_back(v->val);
  if (v->left != nullptr) preOrder(v->left, ans);
  if (v->right != nullptr) preOrder(v->right, ans);
}

void inOrder(Node *v, vector<int> &ans) {
  if (v == nullptr) return;
  if (v->left != nullptr) inOrder(v->left, ans);
  ans.push_back(v->val);
  if (v->right != nullptr) inOrder(v->right, ans);
}

Node *create(int val) {
  Node *n = (Node *)malloc(sizeof(Node));
  n->val = val;
  n->left = n->right = nullptr;
  return n;
}

Node *insert(Node *T, Node *z) {
  if (T == nullptr) {
    return z;
  }

  Node *head = T;
  while (head != nullptr) {
    if (z->val <= head->val) {
      if (head->left == nullptr) {
        head->left = z;
        break;
      }
      head = head->left;
    } else {
      if (head->right == nullptr) {
        head->right = z;
        break;
      }
      head = head->right;
    }
  }
  return T;
}

void print(Node *T) {
  vector<int> ans;
  inOrder(T, ans);
  REP(i, ans.size()) cout << ans[i] << SLN(i, ans.size());

  ans.clear();
  preOrder(T, ans);
  REP(i, ans.size()) cout << ans[i] << SLN(i, ans.size());
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string order;
  int n, num;
  cin >> n;
  Node *T = nullptr;
  REP(i, n) {
    cin >> order;
    Node *cur;
    if (order[0] == 'i') {
      cin >> num;
      cur = create(num);
    }

    // cout << order << " ";
    // cout << "i(" << i << "): " << cur->val << endl;
    // cout << ">" << T << "<" << endl;
    if (order[0] == 'i') T = insert(T, cur);
    if (order[0] == 'p') print(T);
  }

  return 0;
}
