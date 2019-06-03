#include <iostream>
#include <vector>
using namespace std;

char toggleNow(char s) { return s == '#' ? '.' : '#'; }

int main() {
  long long n;
  string s;
  ios::sync_with_stdio(false);

  cin >> n >> s;
  vector<int> v;

  char now = '#';
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (now == s[i]) {
      cnt++;
    } else {
      v.push_back(cnt);
      now = toggleNow(now);
      cnt = 1;
    }
  }
  if (cnt != 0) {
    v.push_back(cnt);
  }
  if (v.size() % 2 != 0) {
    v.push_back(0);
  }

  vector<int> sum;
  vector<int> sumb;
  sum.push_back(0);
  sumb.push_back(0);
  int j = 0;
  for (int i = 0; i < v.size(); i += 2) {
    sum.push_back(sum[j] + v[i]);
    sumb.push_back(sumb[j] + v[v.size() - 1 - i]);
    j++;
  }
  cout << sum.size() << sumb.size() << endl;
  for (int i = 0; i < sum.size(); i++) {
    cout << "**" << sum[i] << "**" << endl;
    cout << "--" << sumb[i] << "--" << endl;
  }

  // int ans = 0;
  // for (int i = 0; i < v.size(); i += 2) {
  //   int left = i;
  //   int right = min(i + Add, (int)v.size());
  //   int tmp = sum[right] - sum[left];
  //   ans = min(tmp, ans);
  // }

  return 0;
}
