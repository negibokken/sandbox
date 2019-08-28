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
#define MAX_N 200000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
ll gcd(ll a,ll b){if(b==0)return a;return gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
const ll MOD = 1e9+7;
const ll INF = 1LL << 60;
const int inf = 1 << 31;
// clang-format on

int N;
int A[MAX_N];
int B[MAX_N];

int median(int arr[], int num)
{
  if (num % 2 == 0) {
    return (arr[num / 2] + arr[(num / 2) - 1]) / 2;
  }
  else {
    return arr[num / 2];
  }
}

int main(void)
{
  cin >> N;
  REP(i, N) cin >> A[i];

  REP(i, N) B[i] = A[i] - (i + 1);
  sort(B, B + N);

  int b = median(B, N);
  ll sum = 0;
  REP(i, N) sum += abs(B[i] - b);
  cout << sum << endl;

  return 0;
}
