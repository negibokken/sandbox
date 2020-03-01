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

int d(vector<int> in, int id) {
  return distance(in.begin(), find(in.begin(), in.end(), id));
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> v(n);
  vector<Node *> nodes(n + 1);
  REP(i, n + 1) {
    nodes[i] = (Node *)malloc(sizeof(Node));
    nodes[i]->id = i;
    nodes[i]->left = nodes[i]->right = nullptr;
  }
  int p, c;
  char t;
  REP(i, n) {
    cin >> p >> c >> t;
    if (t == 'l') {
      nodes[p]->left = nodes[c];
    } else if (t == 'r') {
      nodes[p]->right = nodes[c];
    }
  }
  dfs(nodes[1]);

  return 0;
}

