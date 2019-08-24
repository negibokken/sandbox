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
  string S;
  ll K;
  cin >> S >> K;

  // K = 1 ならどんなときも 1 文字目
  if (K == 1) {
    cout << S[0] << endl;
  }
  else {
    // もし 1 文字目が 1 なら 2 文字目、そうでなければ 1 文字目が K の範囲ない
    bool is_all_one = true;
    int idx = 0;
    for (int i = 0; i < K; i++) {
      if (S[i] != '1') {
        is_all_one = false, idx = i;
        break;
      }
    }
    if (is_all_one) {
      cout << S[0] << endl;
    }
    else {
      cout << S[idx] << endl;
    }
  }

  return 0;
}
