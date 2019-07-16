#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX_N 1000
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)

typedef long long ll;

ll A[MAX_N + 1], B[MAX_N + 1], C[MAX_N + 1];
ll AB[MAX_N * MAX_N + 1];
ll ABC[MAX_N * 3000 + 1];

int main()
{
  int x, y, z, k;
  cin >> x >> y >> z >> k;

  REP(i, x) cin >> A[i];
  REP(i, y) cin >> B[i];
  REP(i, z) cin >> C[i];

  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      AB[i * y + j] = A[i] + B[j];
    }
  }
  sort(AB, AB + (x * y), std::greater<ll>());
  ll lab = min(x * y, k);
  // AB だけ上位k個だけ
  for (int i = 0; i < lab; i++) {
    for (int j = 0; j < z; j++) {
      ABC[i * z + j] = AB[i] + C[j];
    }
  }
  sort(ABC, ABC + (lab * z), std::greater<ll>());
  for (int i = 0; i < k; i++) {
    cout << ABC[i] << endl;
  }
  return 0;
}

