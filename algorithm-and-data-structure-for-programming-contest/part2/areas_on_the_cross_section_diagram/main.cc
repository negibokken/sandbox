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

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  stack<int> S1;
  stack<P> S2;
  char ch;
  int sum = 0;
  for (int i = 0; cin >> ch; i++) {
    if (ch == '\\')
      S1.push(i);
    else if (ch == '/' && S1.size() > 0) {
      int j = S1.top();
      S1.pop();
      sum += i - j;
      int a = i - j;
      while (S2.size() > 0 && S2.top().first > j) {
        a += S2.top().second;
        S2.pop();
      }
      S2.push(P(j, a));
    }
  }

  vector<int> ans;
  while (S2.size() > 0) {
    ans.push_back(S2.top().second);
    S2.pop();
  }
  reverse(ans.begin(), ans.end());
  cout << sum << endl;
  cout << ans.size();
  for (int i = 0; i < ans.size(); i++) {
    cout << " ";
    cout << ans[i];
  }
  cout << endl;

  return 0;
}
