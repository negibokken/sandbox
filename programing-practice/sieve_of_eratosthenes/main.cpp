#include <bitset>
#include <iostream>
using namespace std;

int main(void)
{
  int n;
  cin >> n;
  bitset<100000> is_prime(0);
  for (int i = 2; i <= n; ++i) {
    is_prime.set(i);
  }
  for (int i = 2; i <= n; ++i) {
    if (is_prime[i]) {
      for (int j = i * 2; j <= n; j += i) {
        is_prime.reset(j);
      }
    }
  }
  for (int i = 2; i <= n; ++i) {
    if (is_prime[i]) {
      cout << i << endl;
    }
  }
  return 0;
}
