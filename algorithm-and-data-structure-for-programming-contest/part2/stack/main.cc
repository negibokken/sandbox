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

typedef struct {
  bool isop;
  int num;
  char op;
} Token;

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  stack<ll> nums;
  char s[1024];
  while (scanf("%s", s) != EOF) {
    if (s[0] == '+') {
      ll b = nums.top();
      nums.pop();
      ll a = nums.top();
      nums.pop();
      a += b;
      nums.push(a);
    } else if (s[0] == '-') {
      ll b = nums.top();
      nums.pop();
      ll a = nums.top();
      nums.pop();
      a -= b;
      nums.push(a);
    } else if (s[0] == '*') {
      ll b = nums.top();
      nums.pop();
      ll a = nums.top();
      nums.pop();
      a *= b;
      nums.push(a);
    } else {
      if (s[0] == '"') {
        int i = 1;
        while (s[i] != '\0') {
          s[i - 1] = s[i];
          i++;
        }
        s[i - 1] = '\0';
      }
      int num = atoi(s);
      nums.push(num);
    }
  }

  cout << nums.top() << endl;

  return 0;
}
