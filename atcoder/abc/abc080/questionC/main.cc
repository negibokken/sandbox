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
typedef pair<int, int> PI;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

// Self settings
// clang-format off
#define MAX_N 200
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

int N;
bool F[MAX_N][5][2];
int P[MAX_N][11];
int cnt[MAX_N];

void resetcnt()
{
  for (int i = 0; i < N; i++) cnt[i] = 0;
}

int cntSum()
{
  int sum = 0;
  for (int i = 0; i < N; i++) sum += cnt[i];
  return sum;
}

vector<PI> workingDays(int n)
{
  vector<PI> wds;
  for (int i = 0; i < 10; i++) {
    int c = 1 << i;
    if ((c & n) > 0) {
      int date = i % 5;
      int time = i % 2;
      wds.push_back(PI(date, time));
    }
  }
  return wds;
}

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;
  REP(i, N) REP(j, 5) REP(k, 2) cin >> F[i][j][k];
  REP(i, N) REP(j, 11) cin >> P[i][j];

  int ans = -INT_MAX;
  for (int i = 0; i < (1 << 10); i++) {
    resetcnt();
    int p = 0;
    vector<PI> wds = workingDays(i);
    if (wds.size() == 0) continue;
    for (int j = 0; j < N; j++) {
      for (auto wd : wds) {
        if (F[j][wd.first][wd.second]) {
          cnt[j]++;
        }
      }
      p += P[j][cnt[j]];
    }
    ans = max(ans, p);
  }
  cout << ans << endl;

  return 0;
}
