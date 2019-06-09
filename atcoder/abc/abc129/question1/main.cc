#include <iostream>
using namespace std;

#define REP(i, N) for (int i = 0; i < (int)(N); ++i)

int a[3];

int main(void)
{
  REP(i, 3) cin >> a[i];
  sort(a, a + 3);
  cout << a[0] + a[1] << endl;
  return 0;
}
