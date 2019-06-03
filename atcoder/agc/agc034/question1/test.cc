#include <stdio.h>
#include <iostream>
#define ll long long
#define inf 1000000000
#define infll 1000000000000000000ll
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define mpr make_pair
#define fi first
#define se second
#define pq priority_queue<int>
#define pqll priority_queue<ll>
#define up(x, y) (x < (y) ? x = (y) : 0)
#define dn(x, y) (x > (y) ? x = (y) : 0)
#define ad(x, y) (x = (x + (y)) % mod)
#define N 2000009
using namespace std;

int n, A, B, C, D;
char ch[N];
void gg()
{
  puts("No");
  exit(0);
}
bool check(int x, int y)
{
  int i;
  for (i = x; i < y; i++)
    if (ch[i] == '#' && ch[i + 1] == '#') return 0;
  return 1;
}
int main()
{
  scanf("%d%d%d%d%d%s", &n, &A, &B, &C, &D, ch + 1);
  ch[0] = ch[n + 1] = '#';
  int i;
  if (!check(A, C)) gg();
  if (!check(B, D)) gg();
  ;
  if (C > D) {
    for (i = B; i <= D; i++)
      if (ch[i] == '.' && ch[i - 1] == '.' && ch[i + 1] == '.') {
        puts("Yes");
        return 0;
      }
    gg();
  }
  puts("Yes");
  return 0;
}
