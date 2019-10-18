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
const int inf = 1 << 31;
// clang-format on

char a, b, c, d;
int A, B, C, D;

const char opr[] = {'+', '-'};

int atoi(char cc) { return cc - '0'; }
void ops(int n, vector<char> &op)
{
  for (int i = 0; i < 3; i++) {
    op[i] = opr[n & 1];
    n = n >> 1;
  }
}

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> a >> b >> c >> d;
  A = atoi(a), B = atoi(b), C = atoi(c), D = atoi(d);
  vector<int> arr = {A, B, C, D};
  vector<char> op(3);

  for (int i = 0; i < (1 << 3); i++) {
    ops(i, op);
    int sum = arr[0];
    for (int i = 0; i < 3; i++) {
      if (op[i] == '+') {
        sum += arr[i + 1];
      }
      else {
        sum -= arr[i + 1];
      }
    }
    if (sum == 7) {
      REP(i, 3) printf("%d%c", arr[i], op[i]);
      printf("%d=7\n", arr[3]);
      return 0;
    }
  }

  return 0;
}
