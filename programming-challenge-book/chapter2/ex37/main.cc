#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

// Self settings
// clang-format off
#define MAX_N 10000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
void myscanf(const char *fmt, int num, int *s, int *v) { REP(i,num) scanf(fmt, &s[i], &v[i]); }
void myscanf(const char *fmt, int num, int *s) { REP(i,num) scanf(fmt, &s[i]); }
// clang-format on

// 素数判定
bool is_prime(int n)
{
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) return false;
  }
  return n != 1;
}

// 約数の列挙
vector<int> divisor(int n)
{
  vector<int> res;
  for (int i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      res.push_back(i);
      // ここはどういういみか
      // i が n / i でないときはどんなときか
      // i で割り切れるなら、i は約数
      // もう一方の n / i もわり切れるはずなので追加する
      // ただほかのイテレーションで追加されるのでは？
      // => No : sqrt(n) までしかみないので
      // n = 100 のとき、 10 までしかイテレーションされない
      // このとき 100 や 50 も 約数だが、イテレーションされない
      // しかし、 i = 1 や i = 2 のときに下記計算を行うことで追加できる
      if (i != n / i) res.push_back(n / i);
    }
  }
  return res;
}

// 素因数分解
map<int, int> prime_factor(int n)
{
  map<int, int> res;
  for (int i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      ++res[i];
      n /= i;
    }
  }
  if (n != 1) res[n] = 1;
  return res;
}

int n;

void solve()
{
  bool ans = is_prime(n);
  cout << (ans ? "Yes" : "No") << endl;
}

int main(void)
{
  cin >> n;
  solve();
  vector<int> a = divisor(n);
  for (int i = 0; i < a.size(); ++i) {
    cout << a[i] << (i == a.size() - 1 ? "" : " ");
  }
  return 0;
}
