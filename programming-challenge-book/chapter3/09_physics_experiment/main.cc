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

const int dx[5] = {-1, 0, 0, 0, 1};
const int dy[5] = {0, -1, 0, 1, 0};

// Self settings
// clang-format off
#define MAX_N 100000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

const double g = 10.0;
int N, H, R, T;
double y[MAX_N];

double calc(int T)
{
  if (T < 0) return H;
  double t = sqrt(2 * H / g);
  int k = (int)(T / t);
  if (k % 2 == 0) {
    double d = T - k * t;
    return H - g * d * d / 2;
  }
  else {
    double d = k * t + t - T;
    return H - g * d * d / 2;
  }
}

void solve()
{
  for (int i = 0; i < N; i++) {
    y[i] = calc(T - i);
  }
  sort(y, y + N);
  for (int i = 0; i < N; i++) {
    // printf("%.2f%c\n", y[i] + 2 * R * i / 100.0, i + i == N ? '\n' : ' ');
    printf("%.2f%c", y[i] + 2 * R * i / 100.0, i == N - 1 ? '\n' : ' ');
  }
}

int main(void)
{
  cin >> N >> H >> R >> T;
  solve();
  return 0;
}
