#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

// Self settings
// clang-format off
#define MAX_N 100000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
#define SLN(i,N) (i == N-1 ? "\n" : " ")
// clang-format on

int N;
double v[MAX_N];

int main(void)
{
  cin >> N;
  REP(i, N) cin >> v[i];

  priority_queue<double, vector<double>, greater<double>> q;
  REP(i, N) q.push(v[i]);

  double ans = 0;
  while (!q.empty()) {
    double a = q.top();
    q.pop();
    if (q.empty()) {
      ans = a;
      break;
    }
    double b = q.top();
    q.pop();
    double c = (a + b) / 2.0;
    q.push(c);
  }
  cout << ans << endl;
  return 0;
}
