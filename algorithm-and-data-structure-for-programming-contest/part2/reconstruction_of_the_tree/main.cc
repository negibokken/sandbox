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
#include <stack>
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
  int id;
  Node *left, *right;
} Node;

int searchIndex(vector<int> arr, int num) {
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] == num) return i;
  }
  return arr.size();
}

bool isLeft(vector<int> arr, int right, int num) {
  for (int i = right; i >= 0; i--) {
    if (arr[i] == num) return true;
  }
  return false;
}

void postorder(Node* v) {
  if (v->right != nullptr) postorder(v->right);
  if (v->left != nullptr) postorder(v->left);
  cout << v->id << " ";
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> preorders(n), inorders(n);
  vector<bool> pused(n), iused(n);
  vector<Node*> nodes(n);
  REP(i, n) cin >> preorders[i];
  REP(i, n) cin >> inorders[i];
  REP(i, n) {
    nodes[i] = (Node*)malloc(sizeof(Node));
    nodes[i]->left = nodes[i]->right = nullptr;
  }

  stack<Node*> st;

  for (int i = 0; i < n; i++) {
    nodes[i]->id = preorders[i];
    st.push(nodes[i]);

    // cout << i << endl;
    if (i + 1 > n) break;
    Node* current = nodes[i + 1];
    current->id = preorders[i + 1];

    while (!st.empty()) {
      Node* node = st.top();
      st.pop();
      cout << node->id << "," << current->id << endl;
      int p = searchIndex(inorders, node->id);
      if (isLeft(inorders, p - 1, current->id)) {
        node->left = current;
        st.push(node);
        break;
      }
      if (st.empty()) node->right = current;
    }
    if (i + 2 < n) st.push(current);
  }
  cout << "end" << endl;

  int root = preorders[0];
  postorder(nodes[root]);

  return 0;
}
