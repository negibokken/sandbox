#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <array>
#include <iostream>
using namespace std;

int fact(int n);
int nCr(int n, int r) { return fact(n) / (fact(r) * fact(n - r)); }

// Returns factorial of n
int fact(int n)
{
  int res = 1;
  for (int i = 2; i <= n; i++) res = res * i;
  return res;
}

int countAB(string s)
{
  int cnt;
  for (string::iterator i = s.begin(); i != s.end(); ++i) {
    if (*i == 'A') {
      if (i + 1 != s.end() && *(i + 1) == 'B') ++cnt;
    }
  }
  return cnt;
}

int threeComb(int &ea, int &sb, int &both)
{
  int mi = min({ea, sb, both});
  ea -= mi;
  sb -= mi;
  both -= mi;
  return mi * 2;
}

int twoComb(int &ea, int &sb, int &both)
{
  array<int, 3> a = {ea, sb, both};
  sort(a.begin(), a.end());
  int mi = min(a[1], a[2]);
  cout << a[1] << "|" << a[2] << endl;
  return mi;
}

int main(void)
{
  int n;
  scanf("%d", &n);

  string s;

  int ans = 0;
  int sb = 0, ea = 0;  // num of start a & end b
  int both = 0;

  for (int i = 0; i < n; ++i) {
    cin >> s;
    int cnt = countAB(s);
    ans += cnt;
    if (s[0] == 'B' && *(s.end() - 1) == 'A') {
      ++both;
    }
    else if (s[0] == 'B') {
      ++sb;
    }
    else if (*(s.end() - 1) == 'A') {
      ++ea;
    }
  }

  printf("ans: %d\n", ans);
  printf("ea: %d\n", ea);
  printf("sb: %d\n", sb);
  printf("both: %d\n", both);
  int part = 0;
  part += threeComb(ea, sb, both);
  printf("part: %d\n", part);

  printf("ea: %d\n", ea);
  printf("sb: %d\n", sb);
  printf("both: %d\n", both);
  part += twoComb(ea, sb, both);
  printf("ea: %d\n", ea);
  printf("sb: %d\n", sb);
  printf("both: %d\n", both);

  // part = max({part, nCr((sb + i), (ea + (both - i))),
  //             nCr((ea + i), (sb + (both - i)))});
  // printf("ans: %d\n", ans);
  // printf("ea: %d\n", ea);
  // printf("sb: %d\n", sb);
  // printf("both: %d\n", both);
  // printf("part: %d\n", part);

  printf("%d\n", ans + part);
  return 0;
}
