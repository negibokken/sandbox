#include <iostream>
using namespace std;

#define MAX_N 1000000

int memo[MAX_N + 1];

int fib(int n)
{
  if (n <= 1) return n;
  if (memo[n] != 0) {
    return memo[n];
  }
  return fib(n - 1) + fib(n - 2);
}

int main(void)
{
  cout << fib(40) << endl;
  return 0;
}
