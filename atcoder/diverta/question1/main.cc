#include <iostream>
using namespace std;

int N, K;

void solve()
{
  if (K == 1) {
    cout << 0 << endl;
  }
  else {
    cout << N - K << endl;
  }
}

int main(void)
{
  cin >> N >> K;
  solve();
  return 0;
}
