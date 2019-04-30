#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> s(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s[i + 1] = a[i] + s[i];
  }
  for (int i = 0; i <= n; i++) {
    cout << s[i] << " ";
  }
  cout << endl;

  int right = n;
  int left = 1;
  cout << s[right] - s[left] << endl;
  return 0;
}
