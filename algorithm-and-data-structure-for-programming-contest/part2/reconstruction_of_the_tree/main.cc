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

void dfs(Node *v) {
  if (v->left != nullptr) dfs(v->left);
  if (v->right != nullptr) dfs(v->right);
  cout << v->id << " ";
}

int n, pos;
vector<int> pre, in, post;

void rec(int l, int r) {
  if (l >= r) return;
  int root = pre[pos++];
  int m = distance(in.begin(), find(in.begin(), in.end(), root));
  rec(l, m);
  rec(m + 1, r);
  post.push_back(root);
}
void solve() {
  pos = 0;
  rec(0, pre.size());
  REP(i, n) {
    if (i) cout << " ";
    cout << post[i];
  }
  cout << endl;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n;
  vector<Node *> nodes(n);
  int v;
  REP(i, n) cin >> v, pre.push_back(v);
  REP(i, n) cin >> v, in.push_back(v);
  REP(i, n) nodes[i] = (Node *)malloc(sizeof(Node));
  REP(i, n) nodes[i]->id = pre[i], nodes[i]->left = nodes[i]->right = nullptr;

  solve();

  return 0;
}

