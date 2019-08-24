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
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
const ll MOD = 1e9+7;
const ll INF = 1LL << 60;
const int inf = 1 << 31;
// clang-format on

int main(void)
{
  string s;
  cin >> s;

  bool f = true;
  bool includeC = false;
  for (int i = 0; i < s.length(); i++) {
    if (i == 0 && s[i] != 'A') {
      f = false;
      break;
    }

    if (2 <= i && i <= s.length() - 2 && s[i] == 'C') {
      if (includeC) {
        f = false;
        break;
      }
      includeC = true;
    }
    if (i != 0 && s[i] != 'C' && !('a' <= s[i] && s[i] <= 'z')) {
      f = false;
      break;
    }
  }
  // cout << f << includeC << endl;
  if (f && includeC) {
    cout << "AC" << endl;
  }
  else {
    cout << "WA" << endl;
  }
  return 0;
}
