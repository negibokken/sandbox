#include <stdio.h>
#include <iostream>
using namespace std;

// Self settings
// clang-format off
#define MAX_N 10000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
void myscanf(const char *fmt, int num, int *s, int *v) { REP(i,num) scanf(fmt, &s[i], &v[i]); }
void myscanf(const char *fmt, int num, int *s) { REP(i,num) scanf(fmt, &s[i]); }
// clang-format on

int a, b, x, y;

int extgcd(int a, int b, int &x, int &y)
{
  int d = a;
  if (b != 0) {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  }
  else {
    x = 1;
    y = 0;
  }
  return d;
}

void solve()
{
  int d = extgcd(a, b, x, y);
  if (d != 1) {
    cout << "-1" << endl;
    return;
  }
  if (x > 0) {
    cout << x << " 0 ";
  }
  else {
    cout << "0 " << abs(x) << " ";
  }
  if (y > 0) {
    cout << y << "0";
  }
  else {
    cout << "0 " << abs(y);
  }
}

int main(void)
{
  cin >> a >> b;
  solve();
  return 0;
}
