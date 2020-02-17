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
#define M 1046527
#define NIL (-1)
#define L 14

char H[M][L];

int getChar(char ch) {
  if (ch == 'A')
    return 1;
  else if (ch == 'C')
    return 2;
  else if (ch == 'G')
    return 3;
  else if (ch == 'T')
    return 4;
  else
    return 0;
}

ll getKey(char str[]) {
  ll sum = 0, p = 1;
  for (int i = 0; i < strlen(str); i++) {
    sum += p * (getChar(str[i]));
    p *= 5;
  }
  return sum;
}

int h1(int key) { return key % M; }
int h2(int key) { return 1 + (key % (M - 1)); }

int find(char str[]) {
  ll key, h;
  key = getKey(str);
  for (ll i = 0;; i++) {
    h = (h1(key) + i * h2(key)) % M;
    if (strcmp(H[h], str) == 0)
      return 1;
    else if (strlen(H[h]) == 0)
      return 0;
  }
}

int insert(char str[]) {
  ll key = getKey(str);
  for (ll i = 0;; i++) {
    ll h = (h1(key) + i * h2(key)) % M;
    if (strcmp(H[h], str) == 0)
      return 1;
    else if (strlen(H[h]) == 0) {
      strcpy(H[h], str);
      return 0;
    }
  }
  return 0;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  char str[L], com[9];
  REP(i, M) H[i][0] = '\0';
  int n;
  scanf("%d", &n);
  REP(i, n) {
    scanf("%s %s", com, str);
    if (com[0] == 'i') {
      insert(str);
    } else {
      if (find(str)) {
        printf("yes\n");
      } else {
        printf("no\n");
      }
    }
  }

  return 0;
}
