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

int head = 0, tail = 0;
vector<P> Q(5);
int LEN = 5;
void enqueue(P p) {
  Q[tail] = p;
  tail = tail + 1 % LEN;
}
void dequeue() { head = head + 1 % LEN; }
bool isFull() { return tail == LEN; }
bool isEmpty() { return head == tail; }
P top() { return Q[head]; }

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;
  int t, p;
  REP(i, n) {
    cin >> t >> p;
    enqueue((P){t, p});
  }

  int now = 0;
  while (!isEmpty()) {
    P cur = top();
    dequeue();

    // 時間内に収まるなら
    if (cur.second <= q) {
      printf("%d ", now + cur.second);
      now += cur.second;
    } else {
      enqueue({cur.first, cur.second - q});
      now += q;
    }
  };

  return 0;
}
