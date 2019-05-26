#include <stdio.h>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Self settings
// clang-format off
#define MAX_N 100
#define REP(i, N) for (int i = 0; i < (int)(N); ++i)
// clang-format on

int N;

int P[MAX_N + 1];
string S[MAX_N + 1];

typedef struct {
  string s;
  int p;
  int idx;
} Shop;

bool operator<(const Shop &Shop1, const Shop &Shop2)
{
  if (Shop1.s != Shop2.s) {
    return Shop1.s > Shop2.s;
  }
  return Shop1.p < Shop2.p;
};

int main(void)
{
  priority_queue<Shop> que;
  scanf("%d\n", &N);
  const char *fmt = "%d %d\n";
  for (int i = 1; i <= N; ++i) {
    cin >> S[i] >> P[i];
    Shop s = {S[i], P[i], i};
    que.push(s);
  }
  cout << que.empty() << endl;
  while (!que.empty()) {
    Shop s = que.top();
    cout << s.idx << endl;
    que.pop();
  }
  return 0;
}
