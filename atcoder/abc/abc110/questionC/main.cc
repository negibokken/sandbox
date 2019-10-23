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

string S, T;

int main(void)
{
  cin >> S >> T;
  map<int, int> ms, mt;
  int n = S.size();

  set<char> st;
  REP(i, n) ms[S[i]]++, mt[T[i]]++, st.insert(S[i]), st.insert(T[i]);

  priority_queue<int> qs, qt;

  for (auto m : ms) qs.push(m.second);
  for (auto m : mt) qt.push(m.second);

  while (!qs.empty()) {
    int ss = qs.top();
    qs.pop();
    int tt = qt.top();
    qt.pop();
    if (ss != tt) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;

  return 0;
}
