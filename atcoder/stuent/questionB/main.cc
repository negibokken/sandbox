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
#define MAX_N 2000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
const ll mod = 1e9+7;
const ll INF = 1LL << 60;
const int inf = 1 << 31;
// clang-format on

struct mint {
  ll x;
  mint(ll x = 0) : x(x % mod) {}
  mint& operator+=(const mint a)
  {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a)
  {
    if ((x += mod - a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a)
  {
    (x *= a.x) %= mod;
    return *this;
  }
  mint operator+(const mint a) const
  {
    mint res(*this);
    return res += a;
  }
  mint operator-(const mint a) const
  {
    mint res(*this);
    return res -= a;
  }
  mint operator*(const mint a) const
  {
    mint res(*this);
    return res *= a;
  }
  mint pow(ll t) const
  {
    if (!t) return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }
  mint inv() const { return pow(mod - 2); }
  mint operator/=(const mint a) { return (*this) *= a.inv(); }
  mint operator/(const mint a) const
  {
    mint res(*this);
    return res /= a;
  }
};

int N, K;
// int A[MAX_N];

int main(void)
{
  cin >> N >> K;
  vector<int> A(N);
  REP(i, N) cin >> A[i];
  vector<int> B2 = A;
  B2.insert(B2.end(), A.begin(), A.end());

  vector<mint> AC(2 * N);

  for (int i = 0; i < N * 2; i++) {
    for (int j = i + 1; j < N * 2; j++) {
      if (B2[i] > B2[j]) {
        AC[i] += 1;
      }
    }
  }

  vector<mint> diff(N);
  for (int i = 0; i < N; i++) {
    diff[i] = AC[i] - AC[i + N];
  }
  // for (int i = 0; i < N; i++) {
  //   cout << diff[i].x << SLN(i, N);
  // }
  // for (int i = 0; i < N; i++) {
  //   cout << AC[i + N] << SLN(i, N);
  // }

  // REP(i, 2 * N) cout << AC[i] << SLN(i, 2 * N);

  mint k = K;
  mint ans = 0;
  if (N == 1) {
    // 繰り返しがない場合は最後の要素は省く (N-1)
    REP(i, N - 1) ans = (ans + AC[i]);
  }
  else {
    REP(i, N)
    {
      ans = (ans + (((k) * (k - 1)) / (mint)2) * diff[i] +
             (k - 1) * (mint)AC[i + N]);
    }
    // if (K % 2 == 0) {
    REP(i, N) { ans = ans + (mint)AC[i + N]; }
    // }
  }
  cout << ans.x << endl;

  return 0;
}
