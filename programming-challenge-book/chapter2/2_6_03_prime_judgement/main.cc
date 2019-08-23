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
#define MAX_N 1000000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
const ll MOD = 1e9+7;
const ll INF = 1LL << 60;
const int inf = 1 << 31;
// clang-format on

int N;
bool is_prime[MAX_N];

void init()
{
  for (int i = 0; i < MAX_N; i++) is_prime[i] = true;
  is_prime[0] = is_prime[1] = false;
  for (int i = 0; i < MAX_N; i++) {
    if (is_prime[i]) {
      for (int j = 2 * i; j < MAX_N; j += i) is_prime[j] = false;
    }
  }
}

int main(void)
{
  cin >> N;
  init();
  cout << (is_prime[N] ? "Yes" : "No") << endl;
  return 0;
}
