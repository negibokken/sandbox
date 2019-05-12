#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// clang-format off
typedef long long ll;
int fact(int n) { int res = 1; for(int i=2;i<=n;++i) res = res * i; return res;}
int nCr(int n, int r) {return (fact(n)/fact(n-r)*fact(r)) ;}
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
// clang-format on

#define MAX_N 100000
bool used[MAX_N];
int perm[MAX_N];

void permutation1(int pos, int n)
{
  if (pos == n) {
    /* process to perm1 */
    return;
  }

  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      perm[pos] = i;
      used[i] = true;
      permutation1(pos + 1, n);
      used[i] = false;
    }
  }
  return;
}

#include <algorithm>
int perm2[MAX_N];
void permutation2(int n)
{
  for (int i = 0; i < n; i++) {
    perm2[i] = i;
  }
  do {
    // process to perm 2
  } while (next_permutation(perm2, perm2 + n));
  return;
}
int main(void) { return 0; }
